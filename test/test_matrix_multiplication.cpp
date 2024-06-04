#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <random>
#include <gtest/gtest.h>



// utility function to generate a matrix of given dimensions 
// where every element is zero
// to be used for test cases
std::vector<std::vector<int>> generateZeroMatrix(int rows, int cols) {
    // Create a matrix with the given sizes, initialized with zeros
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));
    
    return matrix;
}

// utility function to generate a squared identity matrix of given dimension 
// where every element is zero but the unitary diagonal
// to be used for test cases
std::vector<std::vector<int>> generateIdentityMatrix(int size) {
    // Create a square matrix with the given size
    std::vector<std::vector<int>> matrix(size, std::vector<int>(size, 0));
    
    // Fill the diagonal with ones
    for(int i = 0; i < size; ++i) {
        matrix[i][i] = 1;
    }
    
    return matrix;
}

// utility function to generate a random matrix of given dimensions 
// where elements are integers within the interval [0, 100]
// to be used for test cases
std::vector<std::vector<int>> generateRandomMatrix(int rows, int cols) {
    // Initialize the random number generator with a random seed
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Define the range of random numbers
    std::uniform_int_distribution<> dis(0, 100); // Adjust the range as needed

    // Create a matrix with the given sizes
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    
    // Fill the matrix with random integers
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            matrix[i][j] = dis(gen);
        }
    }
    
    return matrix;
}

// Base test case
TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :((((";
}

// Test: multiplication of a 5x2 random matrix by a 2x4 zero matrix
// Expected result: 5x4 zero matrix 
TEST(MatrixMultiplicationTest, TestMultiplyMatrixByZero_0) {
    int nr_A = 5;
    int nc_A = 2;
    int nc_O = 4;

    std::vector<std::vector<int>> A = generateRandomMatrix(nr_A, nc_A);
    std::vector<std::vector<int>> O = generateZeroMatrix(nc_A, nc_O);
    std::vector<std::vector<int>> R(nr_A, std::vector<int>(nc_O, 0));
    std::vector<std::vector<int>> R0(nr_A, std::vector<int>(nc_O, 0));

    multiplyMatrices(A, O, R, nr_A, nc_A, nc_O);

    ASSERT_EQ(R, R0) << "Matrix multiplication-by-zero test failed! :((((";
}

// Test: multiplication of a 3x3 random matrix by a 3x3 zero matrix
// Expected result: 3x3 zero matrix 
TEST(MatrixMultiplicationTest, TestMultiplyMatrixByZero_1) {
    int nr_A = 3;
    int nc_A = 3;
    int nc_O = 3;

std::vector<std::vector<int>> A = generateRandomMatrix(nr_A, nc_A);
    std::vector<std::vector<int>> O = generateZeroMatrix(nc_A, nc_O);
    std::vector<std::vector<int>> R(nr_A, std::vector<int>(nc_O, 0));
    std::vector<std::vector<int>> R0(nr_A, std::vector<int>(nc_O, 0));

    multiplyMatrices(A, O, R, nr_A, nc_A, nc_O);

    ASSERT_EQ(R, R0) << "Matrix multiplication-by-zero test failed! :((((";
}

// Test: multiplication of a 2x2 random matrix by a 2x2 identity matrix
// Expected result: equal as the first matrix
TEST(MatrixMultiplicationTest, TestMultiplyMatrixByIdentity_0) {
    int nr_A = 2;

    std::vector<std::vector<int>> A = generateRandomMatrix(nr_A, nr_A);
    std::vector<std::vector<int>> I = generateIdentityMatrix(nr_A);
    std::vector<std::vector<int>> R(nr_A, std::vector<int>(nr_A, 0));

    multiplyMatrices(A, I, R, nr_A, nr_A, nr_A);

    ASSERT_EQ(R, A) << "Matrix multiplication-by-zero test (0) failed! :((((";
}

// Test: multiplication of a 5x5 random matrix by a 5x5 identity matrix
// Expected result: equal as the first matrix
TEST(MatrixMultiplicationTest, TestMultiplyMatrixByIdentity_1) {
    int nr_A = 5;

    std::vector<std::vector<int>> A = generateRandomMatrix(nr_A, nr_A);
    std::vector<std::vector<int>> I = generateIdentityMatrix(nr_A);
    std::vector<std::vector<int>> R(nr_A, std::vector<int>(nr_A, 0));

    multiplyMatrices(A, I, R, nr_A, nr_A, nr_A);

    ASSERT_EQ(R, A) << "Matrix multiplication-by-zero test (1) failed! :((((";
}

// Test: multiplication of a 2x2 identity matrix by a 2x2 random matrix
// Expected result: equal as the second matrix
TEST(MatrixMultiplicationTest, TestMultiplyIdentityByMatrix_0) {
    int nr_A = 2;

    std::vector<std::vector<int>> A = generateRandomMatrix(nr_A, nr_A);
    std::vector<std::vector<int>> I = generateIdentityMatrix(nr_A);
    std::vector<std::vector<int>> R(nr_A, std::vector<int>(nr_A, 0));

    multiplyMatrices(I, A, R, nr_A, nr_A, nr_A);

    ASSERT_EQ(R, A) << "Matrix multiplication-by-identity test (0) failed! :((((";
}

// Test: multiplication of a 5x5 identity matrix by a 5x5 random matrix
// Expected result: equal as the second matrix
TEST(MatrixMultiplicationTest, TestMultiplyIdentityByMatrix_1) {
    int nr_A = 5;

    std::vector<std::vector<int>> A = generateRandomMatrix(nr_A, nr_A);
    std::vector<std::vector<int>> I = generateIdentityMatrix(nr_A);
    std::vector<std::vector<int>> R(nr_A, std::vector<int>(nr_A, 0));

    multiplyMatrices(I, A, R, nr_A, nr_A, nr_A);

    ASSERT_EQ(R, A) << "Matrix multiplication-by-identity test (1) failed! :((((";
}

// Test: multiplication of A * B * C
// where A: 3x4 random matrix
//       B: 4x5 random matrix
//       C: 5x4 random matrix
// Expected result: associative property holds, i.e. (A*B)*C = A*(B*C) 
TEST(MatrixMultiplicationTest, TestMultiplyMatrixAssociativeProp_0) {
    int nr_A = 3;
    int nc_A = 4;
    int nc_B = 5;
    int nc_C = 3;

    std::vector<std::vector<int>> A = generateRandomMatrix(nr_A, nc_A);
    std::vector<std::vector<int>> B = generateRandomMatrix(nc_A, nc_B);
    std::vector<std::vector<int>> C = generateRandomMatrix(nc_B, nc_C);
    std::vector<std::vector<int>> A_B(nr_A, std::vector<int>(nc_B, 0));
    std::vector<std::vector<int>> B_C(nc_A, std::vector<int>(nc_C, 0));
    std::vector<std::vector<int>> R1(nr_A, std::vector<int>(nc_C, 0));
    std::vector<std::vector<int>> R2(nr_A, std::vector<int>(nc_C, 0));

    multiplyMatrices(A, B, A_B, nr_A, nc_A, nc_B);
    multiplyMatrices(B, C, B_C, nc_A, nc_B, nc_C);
    multiplyMatrices(A, B_C, R1, nr_A, nc_A, nc_C);
    multiplyMatrices(A_B, C, R2, nr_A, nc_B, nc_C);

    ASSERT_EQ(R1, R2) << "Matrix multiplication-associative property test (0) failed! :((((";
}

// Test: multiplication of A * B * C
// where A: 5x7 random matrix
//       B: 7x4 random matrix
//       C: 4x6 random matrix
// Expected result: associative property holds, i.e. (A*B)*C = A*(B*C) 
TEST(MatrixMultiplicationTest, TestMultiplyMatrixAssociativeProp_1) {
    int nr_A = 5;
    int nc_A = 7;
    int nc_B = 4;
    int nc_C = 6;

    std::vector<std::vector<int>> A = generateRandomMatrix(nr_A, nc_A);
    std::vector<std::vector<int>> B = generateRandomMatrix(nc_A, nc_B);
    std::vector<std::vector<int>> C = generateRandomMatrix(nc_B, nc_C);
    std::vector<std::vector<int>> A_B(nr_A, std::vector<int>(nc_B, 0));
    std::vector<std::vector<int>> B_C(nc_A, std::vector<int>(nc_C, 0));
    std::vector<std::vector<int>> R1(nr_A, std::vector<int>(nc_C, 0));
    std::vector<std::vector<int>> R2(nr_A, std::vector<int>(nc_C, 0));

    multiplyMatrices(A, B, A_B, nr_A, nc_A, nc_B);
    multiplyMatrices(B, C, B_C, nc_A, nc_B, nc_C);
    multiplyMatrices(A, B_C, R1, nr_A, nc_A, nc_C);
    multiplyMatrices(A_B, C, R2, nr_A, nc_B, nc_C);

    ASSERT_EQ(R1, R2) << "Matrix multiplication-distributive property test (1) failed! :((((";
}




// main
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
