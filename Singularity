Bootstrap: docker
From: ubuntu:18.04

%post
    apt-get update && 
    apt-get upgrade -y && 
    apt-get autoremove -y &&
    apt-get clean -y &&
    apt-get -y install g++ cmake libopenmpi-dev &&
    apt-get autoremove -y &&
    apt-get clean -y
    # build
    build.sh
    

%files
    matrixA.txt
    matrixB.txt
    CMakeLists.txt
    build.sh
    ./src /src
    ./include /include
    ./lib /lib
    ./googletest /googletest
    ./test /test


%runscript
    echo "Container was created."
    
    # test
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