#include <stdio.h>
#include <stdlib.h>

#include "SortAlgo.h"
#include "SortAlgo.c"

int main(){
    printf("\ncode_start\n\n\n");

    int *Array;
    char input[100];
    gets(input);

    int count = 0;
    int temp_Array[100];

    int temp_count = 0;
    while (input[temp_count]){
        if (input[temp_count] - '0' >= 0 && input[temp_count] - '0' <= '9'){
            
            if (input[temp_count+1] - '0' >= 0 && input[temp_count+1] - '0' <= '9'){
                int value = input[temp_count] - '0';
                while (1){
                    temp_count++;
                    if (!input[temp_count] || input[temp_count] == ' ') {break;}
                    
                    value = (value * 10) + input[temp_count] - '0';
                }
                temp_Array[count] = value;
                count++;
                
            }   else{
                temp_Array[count] = input[temp_count] - '0';
                count++;
            }
        }
        temp_count++;
    }

    int size = count;
    Array = (int *)malloc(sizeof(int) * (count + 1));
    Array[0] = -1;
    for (int i = 0; i < size; i++){
        Array[i + 1] = temp_Array[i];
    }
    printf("\n\n");

    PrintArray(size, Array);
    printf("Array above is original array.\n\n");

    HeapSortArray(size, Array);

    printf("\nSorted ");
    PrintArray(size, Array);

    printf("\n\ncode_end\n\n");
    return 0;
}