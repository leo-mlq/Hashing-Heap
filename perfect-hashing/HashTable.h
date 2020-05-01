#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "HashBucket.h"
#include "Matrix.h"
#include <vector>
using namespace std;

class HashTable{
    public:
        HashTable();
        HashTable(int ht_size,int data_size);
        ~HashTable();
        void ht_hash(const vector<int>& in);
        void ht_rehash();
        int find_ht_space();
        void print_ht_matrix();
        void print_buckets_matrix();
        void print_buckets_slots();
        void print_buckets_count();
        void print_visit_time();
        void set_matrix(int s2){ht_matrix = new Matrix(ceil(log2(table_size)),s2);}
        void set_table(int s3){table_size = s3;ht = new HashBucket[s3];}

        void reset_ht_matrix();

    private:
        int table_size;
        int d_size;
        HashBucket* ht;
        Matrix* ht_matrix;
        vector<vector<int>> temp;
        vector<vector<int>> temp1;;
        //void reset_ht_matrix();
        void reset_ht();


};
#endif // HASHTABLE_H
