FROM ubuntu:mantic AS test_build

USER root


RUN apt-get update && apt-get install -y \
    gcc-arm-none-eabi \
    gcc \
    g++ \
    cmake \
    lcov \
    git \

    # WORKDIR /repo
