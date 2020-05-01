#ifndef HASHBUCKET_H
#define HASHBUCKET_H
#include <iostream>
#include <vector>
#include "Matrix.h"
using namespace std;

class HashBucket{
    public:
        HashBucket();//default constructor;
        HashBucket(int matrix_r,int matrix_c);
        ~HashBucket();

        void printSecond_level_hashMatrix();
        void insert(const vector<int>& v);
        vector<int>& lookup(const vector<int>& in);
        void resetBucket();
        int findSpace_bucket(){return count*count;}
        int getCount() const {return count;}

    private:
        vector<vector<int>> data; //used to stored data being hashed to the bucket;
        vector<vector<int>> data_temp;
        Matrix* hashMatrix;
        int count; //count how many data in this bucket;
        string flag_rehash; //if only one data, no need to rehash; if more, rehash and reset hashMatrix;
        unsigned int slots;
        bool rehash(); //true, no need to rehash again;
        void perform_second_level_hashing();

};
#endif // HASHBUCKET_H
