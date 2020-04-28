FROM node:14
SHELL ["/bin/bash", "-c"]

RUN apt-get update
RUN apt-get install -y clang-format cmake default-jre python2.7 python-pip
RUN pip install cpplint
WORKDIR /root
RUN git clone https://github.com/emscripten-core/emsdk.git
WORKDIR /root/emsdk
RUN git pull
RUN ./emsdk install latest
RUN ./emsdk activate latest

CMD source /root/emsdk/emsdk_env.sh && bash
