#include <stdio.h>
#include <stdlib.h>

#include "MaxHeap.h"

void ShiftDownArray(int index, int Size, ElementType *Array){

    if (index * 2 > Size) {return;}

    if (index * 2 + 1 > Size){

        if (Array[index] < Array[index * 2]){
            ElementType temp = Array[index * 2];
            Array[index * 2] = Array[index];
            Array[index] = temp;
        }
        return;
    }

    ElementType Maximum = Max(Array[2 * index], Array[2 * index + 1]);

    if (Array[index] >= Maximum) {return;}

    if (Maximum == Array[2 * index]){
        Array[index * 2] = Array[index];
        Array[index] = Maximum;
        return ShiftDownArray(2 * index, Size, Array);
    }   else{
        Array[2 * index + 1] = Array[index];
        Array[index] = Maximum;
        return ShiftDownArray(2 * index + 1, Size, Array);
    }

}
void ShiftUpArray(int index, ElementType *Array){
    
    if (Array[index] > Array[index/2]){
        ElementType temp = Array[index/2];
        Array[index/2] = Array[index];
        Array[index] = temp;
        return ShiftUpArray(index/2, Array);
    }

}
void BuildMaxHeapArray(int Size, ElementType *Array){

    for (int i = Size/2; i > 0; i--){
        ShiftDownArray(i, Size, Array);
    }

}

void DeleteMaxArray(int Size, ElementType *Array){

    ElementType temp = Array[1];
    Array[1] = Array[Size];
    Array[Size] = temp;

    ShiftDownArray(1, Size - 1, Array);

}
