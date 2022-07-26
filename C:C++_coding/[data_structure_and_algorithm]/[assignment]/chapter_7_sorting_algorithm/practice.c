#include <stdio.h>
#include <stdlib.h>

#include "SortAlgo.h"
#include "SortAlgo.c"

int main(){
    printf("\ncode_start\n\n\n");

    int *Array;
    Array = (int *)malloc(sizeof(int) * 8);
    int size = 50;
    int count = 0;
    
    for (int i = 0; i < size; i++){
        Array[count] = size - i;
        count++;
    }

    Swap(&Array[3], &Array[4]);
    Swap(&Array[1], &Array[9]);
    Swap(&Array[8], &Array[4]);
    Swap(&Array[5], &Array[8]);
    Swap(&Array[4], &Array[6]);
    PrintArray(size, Array);

    MedianQuickSort(size, Array);
    PrintArray(size, Array);

    printf("\n\ncode_end\n\n");
    return 0;
}