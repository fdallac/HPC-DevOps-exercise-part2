# Use an official Ubuntu base image
FROM ubuntu:20.04

# Set environment variables to non-interactive for automatic installations
ENV DEBIAN_FRONTEND=noninteractive

# Update the package list and install necessary packages
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    wget \
    curl \
    vim \
    git \
    cmake \
    libssl-dev \
    libffi-dev \
    python3 \
    python3-pip \
    openmpi-bin \
    openmpi-common \
    libopenmpi-dev


# Copy the specified files and directories into the container
COPY matrixA.txt /cnt/matrixA.txt
COPY matrixB.txt /cnt/matrixB.txt
COPY CMakeLists.txt /cnt/CMakeLists.txt
COPY ./src /cnt/src
COPY ./include /cnt/include
COPY ./lib /cnt/lib
COPY ./googletest /cnt/googletest
COPY ./test /cnt/test


# Build the application
RUN cd cnt && \
    mkdir -p build && \
    cd build && \
    cmake .. && \
    cmake --build . && \
    cd ..


# Set working directory
WORKDIR /cnt


# Entry point for the container that runs test cases
ENTRYPOINT ["./build/test_multiplication"]
