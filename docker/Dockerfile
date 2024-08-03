FROM ubuntu:latest

ARG TOOLCHAIN_VERSION=13.3.rel1
ARG TOOLCHAIN=arm-gnu-toolchain-${TOOLCHAIN_VERSION}-x86_64-arm-none-eabi
ARG EXTENSION=tar.xz
ARG TOOLCHAIN_URL=https://developer.arm.com/-/media/Files/downloads/gnu/${TOOLCHAIN_VERSION}/binrel/${TOOLCHAIN}.${EXTENSION}
ARG CHECKSUM_URL=https://developer.arm.com/-/media/Files/downloads/gnu/${TOOLCHAIN_VERSION}/binrel/${TOOLCHAIN}.${EXTENSION}.sha256asc

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y vim git make cmake gcc build-essential wget
RUN wget ${TOOLCHAIN_URL}
RUN wget ${CHECKSUM_URL}
RUN sha256sum -c ${TOOLCHAIN}.${EXTENSION}.sha256asc
RUN tar xJf ${TOOLCHAIN}.${EXTENSION} -C /opt
RUN rm ${TOOLCHAIN}.${EXTENSION}
RUN rm ${TOOLCHAIN}.${EXTENSION}.sha256asc
ENV PATH=/opt/${TOOLCHAIN}/bin:$PATH