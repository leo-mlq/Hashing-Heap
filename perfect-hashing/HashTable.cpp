#include "HashTable.h"
#include "HashBucket.h"
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

HashTable::HashTable(){
    table_size=0;
    ht = 0;
    d_size = 0;
    ht_matrix = 0;
    temp.clear();
}

HashTable::HashTable(int ht_size,int data_size){
    table_size = ht_size;
    d_size = data_size;
    ht = new HashBucket[table_size];
    ht_matrix = new Matrix(ceil(log2(table_size)),d_size);
    temp.clear();
}

HashTable::~HashTable(){
    for(int i=0;i<table_size;i++){
        ht[i].resetBucket();
    }
    delete[] ht;
    table_size=0;
    d_size = 0;
    delete ht_matrix;
    temp.clear();

}
void HashTable::ht_hash(const vector<int>& in)
{
    ht[Binary2int(matrixMul(*ht_matrix,in))%table_size].insert(in);
    temp.push_back(in);
}

void HashTable::reset_ht_matrix(){
    ht_matrix->resetMatrix();
}

void HashTable::print_ht_matrix(){
    ht_matrix->printMatrix();
}

void HashTable::reset_ht(){
    reset_ht_matrix();
    for(int i=0;i<table_size;i++){
        ht[i].resetBucket();
    }
}
int HashTable::find_ht_space(){
    int total = 0;
    for(int i=0;i<table_size;i++){
        if(ht[i].findSpace_bucket() == 0){
            total = total + 1; //ht[1] takes a space;
        }
        else if(ht[i].findSpace_bucket() == 1){
            total = total + 1;
        }
        else if(ht[i].findSpace_bucket() > 1){
            total = total + ht[i].findSpace_bucket() + 1;
        }
    }
    return total;
}

void HashTable::ht_rehash(){
    temp1 = temp;
    while(find_ht_space()>=2*table_size){
        reset_ht();
        for(int i=0;i<temp1.size();i++){
            ht_hash(temp1[i]);
        }
    }
    temp.clear();
    //temp1.clear();
    return;
}
void HashTable::print_buckets_matrix(){
    for(int i=0;i<table_size;i++){
        if(ht[i].getCount()>1){
            ht[i].printSecond_level_hashMatrix();
        }
        else
        {
            cout<<"NULL"<<endl<<endl;
        }
    }
}

void HashTable::print_buckets_slots(){
    for(int i=0;i<table_size;i++){
        cout<<ht[i].findSpace_bucket()<<endl;
    }
}

void HashTable::print_buckets_count(){
    for(int i=0;i<table_size;i++){
        cout<<ht[i].getCount()<<endl;
    }
}

void HashTable::print_visit_time(){
    for(int i=0;i<table_size;i++){
        unsigned int v = ht[Binary2int(matrixMul(*ht_matrix,temp1[i]))%table_size].getCount();
        if(v <= 1){
            cout<<"1"<<endl;
        }
        else
            cout<<"2"<<endl;
    }
    temp1.clear();
}



