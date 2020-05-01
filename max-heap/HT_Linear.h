#ifndef HT_LINEAR_H
#define HT_LINEAR_H
#include "Data_node.h"
#include "Max_heap.h"
#include <iostream>

using namespace std;

class HT_Linear{

    public:
        HT_Linear();
        HT_Linear(int ht_size);
        ~HT_Linear();
        void Load_HT(int k, Max_heap& h);
        void hash_insert(Data_node* n);
        int find_min_index();
        Data_node* delete_index(int index);

        int get_size() const {return this->table_size;};
        Data_node* search_ht(int k);
        Data_node*& search_ht_index(int k);
        void print_tableContent();


    private:
        Data_node** data;
        int table_size;

};

#endif // HT_LINEAR_H
