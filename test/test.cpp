#define CATCH_CONFIG_MAIN			// this line tells Catch to provide a main() function
#define CATCH_CONFIG_COLOUR_NONE	// this line avoids problems due to color-coding the output
#include "catch2/catch.hpp"
#include "matrix.h"

TEST_CASE("default constructor", "[CreatMatrix]") {
    Matrix newmat = createMatrix(2, 2);

    REQUIRE(newmat[0][0] == 0);
    REQUIRE(newmat[0][1] == 0);
    REQUIRE(newmat[1][0] == 0);
    REQUIRE(newmat[1][1] == 0);
}

TEST_CASE("parameterized constructor", "[CreatMatrix]") {
    std::vector<std::vector<double>> mtx = {{2.0, 2.0}, {4.0, 4.0}};

    Matrix nextmat = createMatrix(mtx);

    REQUIRE(nextmat[0][0] == 2);
    REQUIRE(nextmat[0][1] == 2);
    REQUIRE(nextmat[1][0] == 4);
    REQUIRE(nextmat[1][1] == 4);


}

TEST_CASE("adding", "[addMatrices]") {
    std::vector<std::vector<double>> mtx = {{2.0, 2.0}, {4.0, 4.0}};
    Matrix mat1 = createMatrix(mtx);

    std::vector<std::vector<double>> mtx2 = {{8, 1}, {1, 3}};
    Matrix mat2 = createMatrix(mtx2);

    Matrix inv = createMatrix(1, 1);

    Matrix added = addMatrices(mat1, mat2);

    REQUIRE(added[0][0] == 10);
    REQUIRE(added[0][1] == 3);
    REQUIRE(added[1][0] == 5);
    REQUIRE(added[1][1] == 7);

    REQUIRE_THROWS(addMatrices(mat1, inv));

}

TEST_CASE("subtracting", "[subtractMatrices]") {

    std::vector<std::vector<double>> mtx = {{2.0, 2.0}, {4.0, 4.0}};
    Matrix mat1 = createMatrix(mtx);

    std::vector<std::vector<double>> mtx2 = {{8, 1}, {1, 3}};
    Matrix mat2 = createMatrix(mtx2);

    Matrix inv = createMatrix(1, 1);

    Matrix subbed = subtractMatrices(mat1, mat2);

    REQUIRE(subbed[0][0] == -6);
    REQUIRE(subbed[0][1] == 1);
    REQUIRE(subbed[1][0] == 3);
    REQUIRE(subbed[1][1] == 1);

    REQUIRE_THROWS(subtractMatrices(mat1, inv));

}

TEST_CASE("multiplying", "[multiplyMatrices]") {

    std::vector<std::vector<double>> mtx = {{1, 2}, {3, 4}};
    Matrix mat1 = createMatrix(mtx);

    std::vector<std::vector<double>> mtx2 = {{5, 6}, {7, 8}};
    Matrix mat2 = createMatrix(mtx2);

    Matrix inv = createMatrix(1, 1);

    Matrix mult = multiplyMatrices(mat1, mat2);

    //mult = 
    // [19, 22] [43, 50]

    REQUIRE(mult[0][0] == 19);
    REQUIRE(mult[0][1] == 22);
    REQUIRE(mult[1][0] == 43);
    REQUIRE(mult[1][1] == 50);

}