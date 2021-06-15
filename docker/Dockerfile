FROM debian:buster

RUN apt-get update -y \
    && apt-get install -y --no-install-recommends \
    build-essential gdb strace man manpages-dev vim less procps psmisc lsof curl sudo \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

RUN useradd -M -d / -G sudo -s /bin/bash docker \
    && echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers
