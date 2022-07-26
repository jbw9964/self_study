#ifndef __SortAlgorithm__
#define __SortAlgorithm__

typedef int ElementType;

#include "MaxHeap.h"
#include "MaxHeap.c"

void InsertionSort(int Size, ElementType *Array);

void InsertionSortForShell(int Size, ElementType **Array);
void ShellSort_Increasement(int Size, int Increasement, ElementType *Array);
void ShellSort(int Size, ElementType *Array);

void HeapSortArray(int Size, ElementType *Array);

void Combine(int Most_Left_Index, int Center_Index,int Most_Right_Index, ElementType *Array, ElementType *temp);
void Dived(int Most_Left_Index, int Most_Right_Index, ElementType *Array, ElementType *temp);
void MergeSort(int Size, ElementType *Array);

void QuickSortByRange(int Most_Left_Index, int Most_Right_Index, ElementType *Array);
void NormalQuickSort(int Size, ElementType *Array);

int SetMedian(int inex_1, int index_2, ElementType *Array);
void QuickSortByMedian(int Most_Left_Index, int Most_Right_Index, ElementType *Array);
void MedianQuickSort(int Size, ElementType *Array);

void Swap(ElementType *input_1, ElementType *input_2){
    ElementType temp = *input_1;
    *input_1 = *input_2;
    *input_2 = temp;
}
void PrintArray(int Size, ElementType *Array){
    printf("Array : [ ");
    for (int i = 1; i < Size + 1; i++){
        printf("%d ", Array[i]);
    }
    printf("]\n");
}

#endif