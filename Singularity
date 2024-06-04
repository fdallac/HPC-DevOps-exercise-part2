Bootstrap: docker
From: ubuntu:18.04

# %post
#     # Set the working directory inside the container
#     mkdir -p /app
#     cd /app

#     # Copy files into container
#     cp 
    
    
#     #apt-get update && apt-get install -y netcat
    

%files
    matrixA.txt
    matrixB.txt
    CMakeLists.txt
    build.sh
    src/ src/
    include/ include/
    lib/ lib/
    googletest/ googletest/
    test/ test/


%runscript
    echo "Container was created."
    build.sh
    build/test_multiplication


# %test
#     grep -q NAME=\"Ubuntu\" /etc/os-release
#     if [ $? -eq 0 ]; then
#         echo "Container base is Ubuntu as expected."
#     else
#         echo "Container base is not Ubuntu."
#     fi