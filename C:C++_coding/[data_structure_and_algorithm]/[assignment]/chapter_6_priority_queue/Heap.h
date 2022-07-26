#ifndef __Heap__
#define __Heap__

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Heap;

typedef int ElementType;

struct Node{
    int Capacity;
    int Size;

    ElementType *Array;
};

Heap CreateHeap(int capacity);
void PrintHeap(Heap H);

void ShiftDown(int index, Heap H);
void ShiftUp(int index, Heap H);

Heap BuildHeap(Heap Unorder_Heap);

void IncreaseKey(int index, ElementType value, Heap H);
void DecreaseKey(int index, ElementType value, Heap H);

void Insert(ElementType input, Heap H);
ElementType DeleteMin(Heap H);

void PrintUnder(ElementType input, Heap H, int index);
Heap Combine(Heap H1, Heap H2);

ElementType Min(ElementType input_1, ElementType input_2){
    if (input_1 <= input_2) {return input_1;}
    return input_2;
}

#endif