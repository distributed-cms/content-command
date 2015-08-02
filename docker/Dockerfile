FROM debian:latest

MAINTAINER Carlos Martin Sanchez "carlosvin@gmail.com"

RUN apt-get update && apt-get install -y \
  autoconf \
  autotools-dev \
  build-essential \
  curl \
  gcc \
  git \
  libc6-dbg \
  libc6-dev \
  libgtest-dev \
  libgflags-dev \
  libtool \
  make \
  meson \
  libzmq3-dev \
  unzip && apt-get clean

RUN git clone https://github.com/grpc/grpc.git /var/local/git/grpc
RUN cd /var/local/git/grpc && \
  git submodule update --init --recursive

RUN cd /var/local/git/grpc/third_party/protobuf && \
  ./autogen.sh && \
  ./configure --prefix=/usr && \
  make -j12 && make check && make install && make clean

RUN cd /var/local/git/grpc && make install

#Install content-command

RUN git clone https://github.com/distributed-cms/content-command.git
RUN mkdir /content-command/bin
WORKDIR /content-command/bin
RUN meson ../src .
RUN ninja

ENV CMD_PORT 5000

EXPOSE $CMD_PORT

ENTRYPOINT ./content-command $CMD_PORT
