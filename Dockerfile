# Use Ubuntu 22.04 as the base image
FROM ubuntu:22.04

# Set environment variables to non-interactive (this prevents some prompts)
ENV DEBIAN_FRONTEND=non-interactive

# Update and install required packages
RUN apt-get update && \
    apt-get install -y \
    clang-15 \
    universal-ctags \
    less \
    make

RUN ln -s '/usr/bin/clang-15' '/usr/bin/clang' && \
    ln -s '/usr/bin/clang++-15' '/usr/bin/clang++'

ENV LESS="-R"

# Copy all directories, subdirectories, and files from the current directory
COPY . /workspace

# Set the working directory to /workspace
WORKDIR /workspace

# Default command (can be overridden)
CMD ["/bin/bash"]

