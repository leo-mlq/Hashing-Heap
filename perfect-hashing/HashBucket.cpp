#include "HashBucket.h"
#include "Matrix.h"
#include <string>
using namespace std;

HashBucket::HashBucket(){
    slots = 0;
    count = 0;
    flag_rehash = "one";
    hashMatrix = 0;
}

HashBucket::HashBucket(int matrix_r,int matrix_c){
    count = 0;
    slots = 0;
    flag_rehash = "one";
    hashMatrix = new Matrix(matrix_r,matrix_c);
}
HashBucket::~HashBucket(){
    slots = 0;
    data.clear();
    hashMatrix = 0;
    count = 0;
    flag_rehash = "one";
}
void HashBucket::insert(const vector<int>& v){
    data.push_back(v);
    count++;
    slots = count * count;
    if(slots>1){
        perform_second_level_hashing();
    }
}
void HashBucket::printSecond_level_hashMatrix(){
    hashMatrix->printMatrix();
}

vector<int>& HashBucket::lookup(const vector<int>& in){
    vector<int>* ans = new vector<int>;
    for(int i=0;i<in.size();i++){
        ans->push_back(-1);
    }
    if(slots == 0){
        return *ans;
    }
    if(slots == 1){
        if(equal(data[0].begin(),data[0].end(),in.begin())){
            ans->clear();
            ans = &data[0];
            return *ans;
        }
        else{return *ans;}
    }
    if(slots>1){
        vector<int>* temp = &data_temp[Binary2int(matrixMul(*hashMatrix,in))%slots];
        if(equal(temp->begin(),temp->end(),in.begin())){
            ans->clear();
            ans = temp;
            return *ans;
        }
        else{return *ans;}
    }
}

bool HashBucket::rehash(){
    data_temp.clear();
    data_temp.resize(slots);
    int* recorder = new int[slots]{0};
    //if(flag_rehash == "one")
    //{
        delete hashMatrix;
        hashMatrix = new Matrix(ceil(log2(slots)),data[0].size());
        //flag_rehash = "more";
    //}
    //else{
    //    hashMatrix->resetMatrix();
    //}
    for(unsigned int i=0;i<data.size();i++)
    {
        int index = Binary2int(matrixMul(*hashMatrix,data[i]))%slots;
        recorder[index]++;
        data_temp[index] = data[i];
    }
    for(unsigned int j=0;j<slots;j++)
    {
        if(recorder[j]>1)
        {
            return false;
        }
    }
}

void HashBucket::perform_second_level_hashing(){
    //hashMatrix = new Matrix(1,data[0].size());
    bool temp = true;
    temp = rehash();
    while(!temp)
    {
        temp = rehash();
    }
}

void HashBucket::resetBucket(){
    slots = 0;
    count = 0;
    flag_rehash = "one";
    data.clear();
    data_temp.clear();
}
