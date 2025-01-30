#include <string>
#include <iostream>
#include <stdio.h>
#include "matrix.h"

//Matrix = std::vector<std::vector<double>>;
//matrix = vector of vectors

Matrix createMatrix(int rows, int cols) {
    Matrix created(rows, std::vector<double>(cols, 0));

    return created; //returns a zero matrix with given dims
}

Matrix createMatrix(std::vector<std::vector<double>> mtx) {
    return mtx; //create a filled matrix object with vector
}

double getMat(const Matrix& m1, int row, int col) {
    return m1[row][col];

}

Matrix addMatrices(const Matrix& m1, const Matrix& m2) {

    //TODO make size_t
    int rw1 = m1.size(); //num rows for m1
    int cl1 = m1[0].size(); //num cols m1

    int rw2 = m2.size(); //num rows for m2
    int cl2 = m2[0].size(); //num cols m2

    Matrix added = createMatrix(rw1, cl1);
    
    if((rw1 != rw2) || (cl1 != cl2)) {
        throw std::invalid_argument("Matrix dimensions do not match!");
    }

    for(int rw = 0; rw < rw1; rw++) {
        for(int cl = 0; cl < cl1; cl++) {
            added[rw][cl] = m1[rw][cl] + m2[rw][cl];
            
        }
    }

    return added;

}

Matrix subtractMatrices(const Matrix& m1, const Matrix& m2) {

    int rw2 = m2.size(); 
    int cl2 = m2[0].size(); 

    Matrix invert = createMatrix(rw2, cl2);

    for(int rw = 0; rw < rw2; rw++) {
        for(int cl = 0; cl < cl2; cl++) {
            invert[rw][cl] = m2[rw][cl] * -1; //make matrix negative
            
        }
    }

    Matrix result = addMatrices(m1, invert);

    return result;

}

Matrix multiplyMatrices(const Matrix& m1, const Matrix& m2) {

    int rw1 = m1.size(); //num rows for m1
    int cl1 = m1[0].size(); //num cols m1

    int rw2 = m2.size(); //num rows for m2
    int cl2 = m2[0].size(); //num cols m2

    Matrix result = createMatrix(rw1, cl2);

    if(cl1 != rw2) {
        throw std::invalid_argument("Matrix dimensions cannot be multiplied!");
    }

    //col2 times row 1...

    for (int i = 0; i < rw1; i++) {
        for (int j = 0; j < cl2; j++) {
            for (int k = 0; k < cl1; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return result;

}

// int main() {
//     return 0;
// }