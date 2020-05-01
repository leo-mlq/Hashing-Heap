#include "Max_heap.h"
#include "Data_node.h"
#include <iostream>

using namespace std;

Max_heap::Max_heap(){}

Max_heap::~Max_heap(){data.clear();}

void Max_heap::MH_insert(Data_node* in){
    if(data.size() == 0){
        data.push_back(in);
        in->parent = nullptr;
        in->left_child = nullptr;
        in->right_child = nullptr;
    }
    else{
        for(int i=0;i<data.size();i++){
            if(data[i]->left_child == nullptr){
                data[i]->left_child = in;
                in->parent = data[i];
                data.push_back(in);
                break;
            }
            else if(data[i]->right_child == nullptr){
                data[i]->right_child = in;
                in->parent = data[i];
                data.push_back(in);
                break;
            }
        }
    }
    MH_reheapify();
}

void Max_heap::Load_MH(int input_key, int input_value){
    Data_node* temp = new Data_node(input_key,input_value);
    MH_insert(temp);
}

Data_node* Max_heap::search_MH(int key){
    for(int i=0; i<data.size(); i++){
        if(data.at(i)->get_key() == key){
            return data[i];
        }
    }
    return nullptr;
}

void Max_heap::MH_reheapify(int index){

    Data_node* temp = data[index];
    if(temp->parent != nullptr){
        if(temp->get_priority() > temp->parent->get_priority() || (temp->get_priority() == temp->parent->get_priority() && temp->get_key() > temp->parent->get_key())){
            swap_Data_node(temp, temp->parent);
        }
    }
}


void Max_heap::MH_reheapify(){
    if(data.size() <= 1){return;}
    for(int i=0;i<data.size();i++){
        MH_reheapify(i);
    }
}

void Max_heap::print_content(){
    for(int i=0;i<data.size();i++){
        cout<<data.at(i)->get_key()<<" ";
    }
}

Data_node* Max_heap::MH_deleteMax(){
    Data_node* temp;
    if(data.size() == 0){
        temp = nullptr;
    }
    else if(data.size() == 1){
        temp = new Data_node(data[0]->get_key(),data[0]->get_value(),data[0]->get_priority());
        data.pop_back();
    }
    else if(data.size()>1) {
        temp = new Data_node(data[0]->get_key(),data[0]->get_value(),data[0]->get_priority());
        swap_Data_node(data[0],data[data.size()-1]);
        if(data[data.size()-1] == data[data.size()-1]->parent->left_child){
            data[data.size()-1]->parent->left_child = nullptr;
            data.pop_back();
        }
        else if(data[data.size()-1] == data[data.size()-1]->parent->right_child){
            data[data.size()-1]->parent->right_child = nullptr;
            data.pop_back();
        }
    }
    MH_reheapify();
    return temp;
}
