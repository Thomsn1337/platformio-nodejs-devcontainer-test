FROM node:18

# Install basic development tools
RUN apt update && apt install -y \ 
    less man-db sudo \
    python3-venv python3-pip \
    clang udev

# Ensure default `node` user has access to `sudo`
ARG USERNAME=node
RUN echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

USER node
RUN curl -fsSL -o /tmp/get-platformio.py https://raw.githubusercontent.com/platformio/platformio-core-installer/master/get-platformio.py
RUN python3 /tmp/get-platformio.py
RUN echo 'export PATH="$PATH:$HOME/.platformio/penv/bin"' | tee -a /home/node/.bashrc /home/node/.zshrc 
RUN echo 'export PATH="$PATH:$HOME/.platformio/penv/bin"' | sudo tee -a /root/.bashrc /root/.zshrc

# Set `DEVCONTAINER` environment variable to help with orientation
ENV DEVCONTAINER=true
