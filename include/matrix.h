 #include <vector>

 using Matrix = std::vector<std::vector<double>>;

 Matrix createMatrix(int rows, int cols);
 Matrix setMat(double val, int row, int col); //set a value at a certain coordinate value
 double getMat(int row, int col); //gets a value at a row/col coordinate

 Matrix addMatrices(const Matrix& m1, const Matrix& m2);
 Matrix subtractMatrices(const Matrix& m1, const Matrix& m2);
 Matrix multiplyMatrices(const Matrix& m1, const Matrix& m2);

