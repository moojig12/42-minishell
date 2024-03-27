FROM mcr.microsoft.com/devcontainers/cpp:1-ubuntu-22.04

ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="3.22.2"

# Optionally install the cmake for vcpkg
COPY ./reinstall-cmake.sh /tmp/

RUN if [ "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}" != "none" ]; then \
        chmod +x /tmp/reinstall-cmake.sh && /tmp/reinstall-cmake.sh ${REINSTALL_CMAKE_VERSION_FROM_SOURCE}; \
    fi \
    && rm -f /tmp/reinstall-cmake.sh

# [Optional] Uncomment this section to install additional vcpkg ports.
# RUN su vscode -c "${VCPKG_ROOT}/vcpkg install <your-port-name-here>"

# [Optional] Uncomment this section to install additional packages.
RUN apt-get update && \
    export DEBIAN_FRONTEND=noninteractive && \
    apt-get -y install --no-install-recommends \
    build-essential bash-completion zsh \
    lsb-release clang valgrind \
    nano curl git wget man-db \
    python3 python3-pip \
    libreadline8 libreadline-dev && \
    pip install norminette==3.3.50

# try to install francinette but not working
# RUN wget https://raw.github.com/xicodomingues/francinette/master/bin/install.sh && \
#     chmod +x install.sh && \
#     ./install.sh

# try to get my .zshrc but not working
# RUN git clone https://github.com/yuki-jinnouchi/dotfiles.git "$HOME/dotfiles" && \
#     chmod +x "$HOME/dotfiles/dotfiles_setup.sh" && \
#     bash "$HOME/dotfiles/dotfiles_setup.sh"

# CMD [ "zsh" ]

# sample (https://42born2code.slack.com/archives/C04C5N7EWS2/p1702100269255449?thread_ts=1702045412.546779&cid=C04C5N7EWS2)
# FROM ubuntu:20.04
# ENV DEBIAN_FRONTEND=noninteractive
# WORKDIR /home/root
# VOLUME /home/root
# RUN apt update && \
#     apt-get install -y lsb-release valgrind clang wget nano python3 python3-pip build-essential && \
#     pip install norminette==3.3.50 && \
#     apt-get install -y cmake git curl python3.8-venv && \
#     apt-get install -y libreadline-dev
# RUN apt update && \
#     wget https://raw.github.com/xicodomingues/francinette/master/bin/install.sh && chmod +x install.sh && ./install.sh
# RUN wget https://github.com/Peltoche/lsd/releases/download/0.23.1/lsd-musl_0.23.1_amd64.deb && \
#     dpkg -i lsd-musl_0.23.1_amd64.deb && \
#     echo "alias ls='lsd'">> ~/.bashrc
# ENV HOME /home/pool
# CMD ["bash"]
