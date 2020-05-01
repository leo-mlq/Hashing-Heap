#include "Matrix.h"
#include <iostream>
using namespace std;

int Binary2int(const vector<int>& bNums)
{
    int sum = 0;
    for(unsigned int i=0;i<bNums.size();i++)
    {
        sum = sum + bNums[bNums.size()-(i+1)]*pow(2,i);
    }
    return sum;
}

Matrix::Matrix()
{
    nums=0;
    row=0;
    column=0;
}
Matrix::~Matrix(){
    nums=0;
    row=0;
    delete []nums;
}

Matrix::Matrix(int in_row, int in_col):row(in_row),column(in_col)
{
    nums=new int[row*column];
    srand((unsigned)time(0));
    for(int i=0;i<row*column;i++){
        nums[i]=rand()%2;
    }
}

void Matrix::printMatrix(){
    for(int i=0; i<row;i++){
        for(int j=0; j<column;j++){
            cout<<nums[i*column+j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void Matrix::resetMatrix(){
    for(int i=0;i<row*column;i++){
        nums[i]=rand()%2;
    }
}

void Matrix::resizeMatrix(int new_row, int new_col){
    delete []nums;
    row=new_row;
    column=new_col;
    nums = new int[row*column];
    for(int i=0;i<row*column;i++){
        nums[i]=rand()%2;
    }
}

const vector<int>& matrixMul(const Matrix& m, const vector<int>& v){
    vector<int>* temp = new vector<int>;
    for(int i=0;i<m.row;i++){
        int t=0;
        for(int j=0;j<m.column;j++){
            //int t=0;
            t = t + m.getElement(i,j)*v[j];
            //temp->push_back(t%2);
        }
        temp->push_back(t%2);
    }
    return *temp;
}

