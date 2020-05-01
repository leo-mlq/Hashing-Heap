#include "HT_Linear.h"
#include "Data_node.h"
#include <iostream>
using namespace std;

HT_Linear::HT_Linear(){
    table_size = 0;
    data = nullptr;
}

HT_Linear::HT_Linear(int ht_size){
    table_size = ht_size;
    data = new Data_node* [table_size];
    for(int i=0; i<table_size; i++){
        data[i] = nullptr;
    }
}

HT_Linear::~HT_Linear(){
    for(int i=0; i<table_size; i++){
        delete data[i];
    }
    delete[] data;
    table_size = 0;
}

void HT_Linear::hash_insert(Data_node* n){
    int index = n->get_key()%table_size;
    while(data[index] != nullptr){
        index = (index+1)%table_size;
    }
    data[index] = n;
}

Data_node* HT_Linear::search_ht(int k){
    int tracker = 0;
    /*int index = k%table_size;

    while(data[index] == nullptr){
        index = (index+1)%table_size;
        tracker = tracker + 1;
        if(tracker>table_size){
            return nullptr;
        }
        else{
            break;
        }
    }*/
    int index = k%table_size;
    while(true){
        if(data[index] != nullptr && data[index]->get_key() == k){
            //data[index]->incremnet_priority();
            return data[index];
            break;
        }
        else if(data[index] != nullptr && data[index]->get_key() != k){
            index = (index+1)%table_size;
            tracker = tracker + 1;
            if(tracker>table_size){
                return nullptr;
                break;
            }
        }
        else if(data[index] == nullptr){
            index = (index+1)%table_size;
            tracker = tracker + 1;
            if(tracker>table_size){
                return nullptr;
                break;
            }
        }
    }
    return nullptr;
}

int HT_Linear::find_min_index(){
    int tracker = 0;
    int index = 0;
    while(data[index] == nullptr){
        index = (index+1)%table_size;
        tracker = tracker + 1;
        if(tracker > table_size){
            return -1;
        }
    }
    for(int i=0; i<table_size; i++){
        if(data[i] != nullptr){
            if(data[index]->get_priority() > data[i]->get_priority() ||(data[index]->get_priority() == data[i]->get_priority() && data[index]->get_key() > data[i]->get_key())){
                index = i;
            }
        }
        else
            continue;
    }
    return index;
}

Data_node*& HT_Linear::search_ht_index(int k){
    return data[k];
}

Data_node* HT_Linear::delete_index(int index){
    Data_node* temp = new Data_node(data[index]->get_key(),data[index]->get_value(),data[index]->get_priority());
    delete data[index];
    data[index] = nullptr;
    return temp;
}

void HT_Linear::print_tableContent(){
    for(int i=0;i<table_size;i++){
        if(data[i] == nullptr){
            cout<<"NULL"<<endl;
        }
        else{
            cout<<data[i]->get_key()<<" ";
        }
    }
}

void HT_Linear::Load_HT(int k, Max_heap& h){
    //int min_index_ht = find_min_index();
    //if(min_index_ht == -1){
        for(int i=0;i<k;i++){
            Data_node* temp = h.MH_deleteMax();
            hash_insert(temp);
        }
    //}
   // else{

    //}
    for(int j=0;j<h.MH_size();j++){
        int ht_min_index = find_min_index();
        if(ht_min_index == -1){
            return;
        }
        else{
            Data_node* temp1 = h.MH_deleteMax();
            if(temp1->get_priority() > data[ht_min_index]->get_priority() ||(temp1->get_priority() == data[ht_min_index]->get_priority() && temp1->get_key() > data[ht_min_index]->get_key())){
                //hash_insert(temp1);
                Data_node* temp2 = delete_index(ht_min_index);
                //swap_Data_node(temp1,temp2);
                h.MH_insert(temp2);
                hash_insert(temp1);
            }
            else{
                h.MH_insert(temp1);
            }
        }
    }
    h.MH_reheapify();
}
