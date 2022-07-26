#include <stdio.h>

#include "Heap.h"

Heap CreateHeap(int capacity){
    Heap temp = (Heap)malloc(sizeof(struct Node));
    temp->Capacity = capacity;
    temp->Size = 0;
    temp->Array = (ElementType *)malloc(sizeof(ElementType) * capacity);

    return temp;
}
void PrintHeap(Heap H){

    for (int i = 1; i <= H->Size; i++){
        printf("%d ", H->Array[i]);
    }
    printf("\n");
}

void ShiftDown(int index, Heap H){

    if (index * 2 > H->Size) {return;}

    if (index * 2 + 1 > H->Size){

        if (H->Array[index] > H->Array[index * 2]){
            ElementType temp = H->Array[index * 2];
            H->Array[index * 2] = H->Array[index];
            H->Array[index] = temp; 
        }
        return;
    }
    
    ElementType Minimum = Min(H->Array[2 * index], H->Array[2 * index + 1]);

    if (H->Array[index] > Minimum){

        if (Minimum == H->Array[2 * index]){
            H->Array[2 * index] = H->Array[index];
            H->Array[index] = Minimum;
            return ShiftDown(2 * index, H);
        }   else{
            H->Array[2 * index + 1] = H->Array[index];
            H->Array[index] = Minimum;
            return ShiftDown(2 * index + 1, H);
        }
    }

}
void ShiftUp(int index, Heap H){

    if (H->Array[index] < H->Array[index/2]){
        ElementType temp = H->Array[index/2];
        H->Array[index/2] = H->Array[index];
        H->Array[index] = temp;
        return ShiftUp(index/2, H);
    }
}

Heap BuildHeap(Heap Unorder_Heap){
    Heap temp = (Heap)malloc(sizeof(struct Node));
    temp->Capacity = 100;
    
    int count;
    for (count = 1; count <= Unorder_Heap->Size ; count++){
        temp->Array[count] = Unorder_Heap->Array[count];
    }
    temp->Size = count;

    for (int i = temp->Size/2; i > 0; i--){
        ShiftDown(i, temp);
    }
    
    return temp;
}

void IncreaseKey(int index, ElementType value, Heap H){

    H->Array[index] = H->Array[index] + value;

    ShiftDown(index, H);

}
void DecreaseKey(int index, ElementType value, Heap H){

    H->Array[index] = H->Array[index] - value;

    ShiftUp(index, H);

}

void Insert(ElementType input, Heap H){

    int i = ++H->Size;

    for ( ; i > 1 && (H->Array[i/2] > input); i /= 2){
        H->Array[i] = H->Array[i/2];
    }

    H->Array[i] = input;

}
ElementType DeleteMin(Heap H){
    int Min = H->Array[1];

    H->Array[1] = H->Array[H->Size];
    H->Size = H->Size - 1;

    int i = 1;
    int child, value = H->Array[1];

    for ( ; 2*i <= H->Size; i = child){
        child = 2*i;

        if (child != H->Size && (H->Array[child+1] < H->Array[child])){
            child++;
        }

        if (value > H->Array[child]) {H->Array[i] = H->Array[child];}
        else {break;}
    }
    H->Array[i] = value;

    return Min;
}

void PrintUnder(ElementType input, Heap H, int index){

    if (H->Array[index] <= input) {printf("%d ", H->Array[index]);}
    else {return;}

    if (index == H->Size) {return;}

    if (H->Array[index * 2] <= input){
        PrintUnder(input, H, index * 2);
    }
    if (H->Array[index * 2 + 1] <= input){
        PrintUnder(input, H, index * 2 + 1);
    }

}
Heap Combine(Heap H1, Heap H2){

    Heap temp = (Heap)malloc(sizeof(struct Node));
    temp->Capacity = 100;
    temp->Array = (ElementType *)malloc(sizeof(ElementType) * 100);
    temp->Array[1] = -5555;

    int count_1 = 1, count_2 = 2;
    int count_H1 = 1;
    int count_H2 = 1;
    while (1){

        for (int i = 0 ; i < count_1; i++){
            temp->Array[count_2] = H1->Array[count_H1];
            count_2++;
            count_H1++;
        }
        for (int j = 0 ; j < count_1; j++){
            temp->Array[count_2] = H2->Array[count_H2];
            count_2++;
            count_H2++;
        }
        count_1 *= 2;

        if ((H1->Size < count_H1) && (H2->Size < count_H2)) {break;}
    }
    temp->Size = count_2 - 1;

    DeleteMin(temp);

    PrintHeap(temp);
    return temp;
}


// 2    4 5     8 9 10 11               16 17 18 19 20 21 22 23
// 3        6 7             12 13 14 15                         24 25 26 27 28 29 30 31