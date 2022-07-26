#include <iostream>

// 와 진짜 이건 못하겠다 어떻게해 이걸;;

class Array{
    const int dim;
    int *size;

    struct Address{
        int level;
        void *next;
    };

    Address *top;

    friend Int;

    public : 
    Array(int dim, int *array_size) : dim(dim){
        size = new int[dim];
        for (int i = 0; i < dim; i++) size[i] = array_size[i];

        top = new Address;
        top->level = 0;

        initialize_address(top);
    }

    Array(const Array &arr) : dim(arr.dim){
        size = new int[dim];
        for (int i = 0; i <dim; i++) size[i] = arr.size[i];

        top  = new Address;
        top->level = 0;

        initialize_address(top);
    }
    ~Array(){
        delete_address(top);
        delete [] size;
    }





    void initialize_address(struct Address *current){
        if (!current) return;
        if (current->level == dim - 1){
            current->next = new int[size[current->level]];
            return;
        }
        current->next = new Address[size[current->level]];
        for (int i = 0; i != size[current->level]; i++){
            (static_cast<Address *>(current->next) + i)->level = current->level + 1;
            initialize_address(static_cast<Address *>(current->next) + i);
        }
    }

    void delete_address(struct Address *current){
        if (!current) return;
        for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++){
            delete_address(static_cast<Address *>(current->next) + i);
        }
        delete [] current->next;
    }

};

class Int{
    void *data;

    int level;
    Array *array;

    public : 
    Int(int index, int _level = 0, void *_data = NULL, Array *_array = NULL)
    : level(_level), data(_data), array(_array) {
        if (_level < 1 || index >= array->size[_level - 1]){
            data = NULL;
            return;
        }
        if (level == array->dim){
            
        }
    }



};



int main(){
    std::cout << "\ncode_start\n\n" << std::endl;

    

    std::cout << "\n\ncode_end\n" << std::endl;
    return 0;
}


// 진도 : p.252