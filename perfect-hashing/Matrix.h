#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
using namespace std;

int Binary2int(const vector<int>& bNums);

class Matrix{

    friend const vector<int>& matrixMul(const Matrix& m, const vector<int>& v);
    public:
        Matrix();
        ~Matrix();
        Matrix(int in_row, int in_col);

        int getElement(int in_row, int in_col) const{return nums[in_row*column+in_col];}
        void resetMatrix();
        void printMatrix();
        void resizeMatrix(int new_row, int new_col);
        int getRow() const {return row;}
        int getCol() const {return column;}

    private:
        int* nums;
        int row;
        int column;

};

#endif // MATRIX_H
