#include <iostream>
#include "HashTable.h"

/*
h(x) = x % 10
h2(x) = 7 - (x % 7)
And table size is fixed as 10
*/

ChainHash::ChainHash(){
    for (int i = 0; i < table_size; i++){
        array[i] = nullptr;
    }
    std::cout << "The table size is : " << table_size << std::endl << std::endl;
}
void ChainHash::Insert(int input){
    int key = input % 10;

    if (!array[key]){
        array[key] = new(struct Node);
        array[key]->next = nullptr;
        array[key]->value = input;
        return;
    }

    Node_Pointer temp = array[key];
    while (temp->next){
        temp = temp->next;
    }
    temp->next = new(struct Node);
    temp = temp->next;
    temp->value = input;
    temp->next = nullptr;
    return;
}
void ChainHash::Print() const{
    std::cout << "This is Chain Hash Table" << std::endl << std::endl;
    for (int i = 0; i < table_size; i++){
        std::cout << "[" << i << "] : ";

        Node_Pointer temp = array[i];
        while (temp){
            std::cout << temp->value << "(" << temp->value % table_size << ") ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
}
ChainHash::~ChainHash(){
    for (int i = 0; i < table_size; i++){
        if (array[i]){
            Node_Pointer temp = array[i];
            while (temp){
                auto temp_1 = temp->next;
                delete(temp);
                temp = temp_1;
            }
        }
    }
}

LinearProbingHash::LinearProbingHash(){
    for (int i = 0; i < table_size; i++){
        array[i] = nullptr;
    }
    std::cout << "The table size is : " << table_size << std::endl << std::endl;
}
void LinearProbingHash::Insert(int input){
    int key = input % 10;

    if (!array[key]){
        array[key] = new(struct Node);
        array[key]->value = input;
        array[key]->next = nullptr;
        return;
    }

    while (true){
        key++;
        key %= 10;

        if (!array[key]) {break;}
    }
    array[key] = new(struct Node);
    array[key]->value = input;
    array[key]->next = nullptr;

}
void LinearProbingHash::Print() const{
    std::cout << "This is Linear Probing Hash Table" << std::endl << std::endl;

    for (int i = 0; i < table_size; i++){
        std::cout << "[" << i << "] : ";
        if (array[i]) {std::cout << array[i]->value << "(" << array[i]->value % table_size << ")";}
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
LinearProbingHash::~LinearProbingHash(){
    for (int i = 0; i < table_size; i++){
        if (array[i]) {delete(array[i]);}
    }
}

QuadraticProbingHash::QuadraticProbingHash(){
    for (int i = 0; i < table_size; i++){
        array[i] = nullptr;
    }
    std::cout << "The table size is : " << table_size << std::endl << std::endl;
}
void QuadraticProbingHash::Insert(int input){
    int key = input % 10;

    if (!array[key]){
        array[key] = new(struct Node);
        array[key]->value = input;
        array[key]->next = nullptr;
        return;
    }

    for (int i = 0;; i++){
        int temp = (key + i*i) % 10;
        if (!array[temp]) {key = temp; break;}
    }
    array[key] = new(struct Node);
    array[key]->value = input;
    array[key]->next = nullptr;

}
void QuadraticProbingHash::Print() const{
    std::cout << "This is Quadratic Probing Hash Table" << std::endl << std::endl;

    for (int i = 0; i < table_size; i++){
        std::cout << "[" << i << "] : ";
        if (array[i]) {std::cout << array[i]->value << "(" << array[i]->value % table_size << ")";}
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
QuadraticProbingHash::~QuadraticProbingHash(){
    for (int i = 0; i < table_size; i++){
        if (array[i]) {delete(array[i]);}
    }
}

// Double Hasing 일 때에는 1989 (마지막 값) 넣으면 안됨.
// 그러면 무한루프 걸림.
DoubleHashing::DoubleHashing(){
    for (int i = 0; i < table_size; i++){
        array[i] = nullptr;
    }
    std::cout << "The table size is : " << table_size << std::endl << std::endl;
}
void DoubleHashing::Insert(int input){
    int key = input % 10;

    if (!array[key]){
        array[key] = new(struct Node);
        array[key]->value = input;
        array[key]->next = nullptr;
        return;
    }

    int temp = 7 - (input % 7);
    
    while (true){
        key = (key + temp) % 10;
        if (!array[key]) {break;}
    }
    array[key] = new(struct Node);
    array[key]->value = input;
    array[key]->next = nullptr;

}
void DoubleHashing::Print() const{
    std::cout << "This is Double Hash Table" << std::endl << std::endl;

    for (int i = 0; i < table_size; i++){
        std::cout << "[" << i << "] : ";
        if (array[i]) {std::cout << array[i]->value << "(" << array[i]->value % table_size << ")";}
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
DoubleHashing::~DoubleHashing(){
    for (int i = 0; i < table_size; i++){
        if (array[i]) {delete(array[i]);}
    }
}


// Rehaahsing by hash table size 19
ReHash* ChainReHashing(ChainHash &input){
    std::cout << "ReHash table inserts in Chain Hashing methods" << std::endl;
    std::cout << "Rehashing ChainHash table" << std::endl;

    auto temp = new ReHash;

    for (int i = 0; i < input.TableSzie(); i++){
        Node_Pointer temp_2 = input.ReturnArray(i);
        
        while (temp_2){
            temp->ChainInsert(temp_2->value);
            temp_2 = temp_2->next;
        }
    }
    std::cout << std::endl;
    return temp;

}
ReHash* LinearReHashing(LinearProbingHash &input){
    std::cout << "ReHash table inserts in Linear Probing methods" << std::endl;
    std::cout << "Rehashing LinearHash table" << std::endl;

    auto temp = new ReHash;

    for (int i = 0; i < input.TableSzie(); i++){
        Node_Pointer temp_2 = input.ReturnArray(i);
        
        while (temp_2){
            temp->LinearInsert(temp_2->value);
            temp_2 = temp_2->next;
        }
    }
    std::cout << std::endl;
    return temp;
}
ReHash* QuadraticReHashing(QuadraticProbingHash &input){
    std::cout << "ReHash table inserts in Quadratic Probing methods" << std::endl;
    std::cout << "Rehashing QuadraticHash table" << std::endl;

    auto temp = new ReHash;

    for (int i = 0; i < input.TableSzie(); i++){
        Node_Pointer temp_2 = input.ReturnArray(i);
        
        while (temp_2){
            temp->QuadraticInsert(temp_2->value);
            temp_2 = temp_2->next;
        }
    }
    std::cout << std::endl;
    return temp;
}
ReHash* DoubleReHashing(DoubleHashing &input){
    std::cout << "ReHash table inserts in Double Haashing methods" << std::endl;
    std::cout << "h2(x) = 7 - (x % 7)" << std::endl;
    std::cout << "Rehashing DoubleHash table" << std::endl;

    auto temp = new ReHash;

    for (int i = 0; i < input.TableSzie(); i++){
        Node_Pointer temp_2 = input.ReturnArray(i);
        
        while (temp_2){
            temp->DoubleInsert(temp_2->value);
            temp_2 = temp_2->next;
        }
    }
    std::cout << std::endl;
    return temp;
}
