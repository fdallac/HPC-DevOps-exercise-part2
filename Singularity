Bootstrap: docker
From: ubuntu:18.04

%files
    matrixA.txt /cnt/matrixA.txt
    matrixB.txt /cnt/matrixB.txt
    CMakeLists.txt /cnt/CMakeLists.txt
    ./src /cnt/src
    ./include /cnt/include
    ./lib /cnt/lib
    ./googletest /cnt/googletest
    ./test /cnt/test

%post
    apt-get update && 
    apt-get upgrade -y && 
    apt-get autoremove -y &&
    apt-get clean -y &&
    apt-get -y install g++ cmake libopenmpi-dev &&
    apt-get autoremove -y &&
    apt-get clean -y

    # build
    cd cnt
    mkdir -p build && cd build
    cmake ..
    cmake --build .
    cd ..
    
%runscript
    echo "Container was created."
    
    # test
    cd cnt
    build/test_multiplication
    # # main
    # mpirun -np 2 main


# %test
#     grep -q NAME=\"Ubuntu\" /etc/os-release
#     if [ $? -eq 0 ]; then
#         echo "Container base is Ubuntu as expected."
#     else
#         echo "Container base is not Ubuntu."
#     fi