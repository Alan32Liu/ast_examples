import json


def get_all_functions_from_ast(ast_filepath: str, ast_source: str):
    with open(ast_filepath, 'r') as file:
        try:
            data = json.load(file)
        except json.JSONDecodeError as e:
            print(f'Error parsing JSON: {e}')

    function_list = []
    file_data = data['inner']
    filepath = ''
    for entry in file_data:
        kind = entry['kind'] if 'kind' in entry else None
        name = entry['name'] if 'name' in entry else None
        file = entry['loc']['file'] if 'loc' in entry and 'file' in entry['loc'] else None
        line = entry['loc']['line'] if 'loc' in entry and 'line' in entry['loc'] else None
        col = entry['loc']['col'] if 'loc' in entry and 'col' in entry['loc'] else None
        type = entry['type']['qualType'] if 'type' in entry and 'qualType' in entry['type'] else None

        if file:
            filepath = file
        if 'FunctionDecl' in kind and filepath and not ('usr' in filepath or ast_source in filepath):
            return_type, input_type = map(str.strip, type.split('(', 1))

            if 'inner' in entry:
                input_type = input_type.split(')', 1)[0]
                arg_list_type = input_type.split(',')
                arg_list_name = []

                parameters = entry['inner']
                for param in parameters:
                    if 'ParmVarDecl' in param['kind'] and 'name' in param:
                        arg_list_name.append(param['name'])
                    elif 'ParmVarDecl' in param['kind']:
                        arg_list_name.append('')
                        
                combined = []
                for t, n in zip(arg_list_type, arg_list_name):
                    if ' *' in t:
                        combined.append(t + n)
                    else:
                        combined.append(t + ' ' + n)

                prototype = f"{return_type} {name}({','.join(combined)})"
            else:
                prototype = f"{return_type} {name}({input_type}"
            
            function_data = {
                'name': name,
                'prototype': prototype,
                'file': filepath,
                'line': str(line),
                'column': str(col)
            }
            function_list.append(function_data)

    json_data = json.dumps(function_list, indent=4)
    print(json_data)

get_all_functions_from_ast('main.c.ast', 'main.c')
# get_all_functions_from_ast('_project_asts__succeed_opusfile_opusfile.c.ast', 'opusfile.c')
# get_all_functions_from_ast('_project_asts__succeed_expat_xmlrole.c.ast', 'xmlrole.c')
