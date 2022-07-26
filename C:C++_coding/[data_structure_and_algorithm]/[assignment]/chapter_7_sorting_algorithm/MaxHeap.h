#ifndef __MaxHeap__
#define __MaxHeap__

void DeleteMaxArray(int Size, ElementType *Array);
void ShiftDownArray(int index, int Size, ElementType *Array);
void ShiftUpArray(int index, ElementType *Array);
void BuildMaxHeapArray(int Size, ElementType *Array);

ElementType Max(ElementType input_1, ElementType input_2){
    if (input_1 > input_2) {return input_1;}
    return input_2;
}

#endif