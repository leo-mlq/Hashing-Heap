#ifndef MAX_HEAP_H
#define MAX_HEAP_H
#include <vector>
#include "Data_node.h"

using namespace std;

class Max_heap{
    public:
        Max_heap();
        ~Max_heap();
        void MH_reheapify();
        void MH_reheapify(int index);
        void Load_MH(int input_key, int input_value);
        void MH_insert(Data_node* in);
        Data_node* MH_deleteMax();
        Data_node* search_MH(int key); //return NULL if not found, otherwise return node for priority update;
        int MH_size() const{return data.size();}

        //print test result;
        void print_content();

    private:
        vector<Data_node*> data;
};


#endif // MAX_HEAP_H
