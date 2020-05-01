#ifndef DATA_NODE_H
#define DATA_NODE_H
//#include "Max_heap.h"
//#include "HT_Linear.h"

using namespace std;

class Data_node{

    friend void swap_Data_node(Data_node* &n1, Data_node* &n2){
        Data_node* temp = new Data_node(n1->key,n1->value,n1->priority);
        n1->key = n2->key;
        n1->value = n2->value;
        n1->priority = n2->priority;
        n2->key = temp->key;
        n2->value = temp->value;
        n2->priority = temp->priority;
    }
    friend void node_incre(Data_node* &n){
        (n->priority)++;
    }

    public:
        Data_node(int k=0, int v=0, int p=0): key(k),value(v),priority(p){
            parent = 0;
            left_child = 0;
            right_child = 0;
        }
        ~Data_node(){key=0;value=0;priority=0;};

        int& get_key() {return key;};
        int& get_value() {return value;};
        int& get_priority() {return priority;};


        Data_node* parent;
        Data_node* left_child;
        Data_node* right_child;

    private:
        int key;
        int value;
        int priority;
};


#endif // DATA_NODE_H
