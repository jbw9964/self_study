#include <iostream>

#include "HashTable.h"
#include "HashTable.cpp"

int main(){
    std::cout << "\ncode_start\n\n" << std::endl;

    auto sample_hash = DoubleHashing();
    sample_hash.Insert(4371);
    sample_hash.Insert(1323);
    sample_hash.Insert(6173);   
    sample_hash.Insert(4199);
    sample_hash.Insert(4344);
    sample_hash.Insert(9679);
    
    sample_hash.Print();

    auto rehash_1 = DoubleReHashing(sample_hash);
    rehash_1->Print();

    std::cout << "\n\ncod_end\n" << std::endl;
    return 0;
}