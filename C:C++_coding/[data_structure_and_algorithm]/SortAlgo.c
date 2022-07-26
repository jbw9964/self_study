#include <stdio.h>
#include <stdlib.h>

#include "SortAlgo.h"

void InsertionSort(int Size, ElementType *Array){ // Array starts at Array[0]

    for (int i = 1; i < Size; i++){
        ElementType temp = Array[i];

        int index;
        for (index = i; index > 0 && (Array[index-1] > temp); index--){
            Array[index] = Array[index-1];
        }
        Array[index] = temp;
    }
    
}

void InsertionSortForShell(int Size, ElementType **Array){
    
    for (int i = 1; i < Size; i++){
        ElementType temp = *Array[i];

        int index;
        for (index = i; index > 0 && (*Array[index - 1] > temp); index--){
            *Array[index] = *Array[index - 1];
        }
        *Array[index] = temp;
    }

}
void ShellSort_Increasement(int Size, int Increasement, ElementType *Array){

    for (int i = 0; i < Size; i++){
        int count = 0;
        ElementType *temp[100];
        for (int j = 0; i + Increasement * j < Size; j++){
            temp[j] = &Array[i + Increasement * j];
            count++;
        }
        InsertionSortForShell(count, temp);
    }

}
void ShellSort(int Size, ElementType *Array){

    int Increasement = Size / 2;
    while (Increasement != 0){
        for (int i = 0; i < Size; i++){
            int count = 0;
            ElementType *temp[100];
            for (int j = 0; i + Increasement * j < Size; j++){
                temp[j] = &Array[i + Increasement * j];
                count++;
            }
            InsertionSortForShell(count, temp);
        }
        Increasement/=2;
    }

}

void HeapSortArray(int Size, ElementType *Array){
    BuildMaxHeapArray(Size, Array);
    PrintArray(Size, Array);
    printf("Array above is MaxHeapify-Builded array.\n\n");
    for (int i = 0; i < Size; i++){
        DeleteMaxArray(Size - i, Array);
        printf("%d DeleteMax ", i + 1);
        PrintArray(Size, Array);
    }
}

void Combine(int Most_Left_Index, int Center_Index,int Most_Right_Index, ElementType *Array, ElementType *temp){
    
    int ComparePos_1 = Most_Left_Index;
    int ComparePos_2 = Center_Index;

    int Counting_Index = Most_Left_Index;
    while (ComparePos_1 <= Center_Index && ComparePos_2 <= Most_Right_Index){
        if (Array[ComparePos_1] <= Array[ComparePos_2]){
            temp[Counting_Index] = Array[ComparePos_1];
            ComparePos_1++;
            Counting_Index++;
        }   else{
            temp[Counting_Index] = Array[ComparePos_2];
            ComparePos_2++;
            Counting_Index++;
        }
    }

    while (ComparePos_1 <= Center_Index){
        temp[Counting_Index] = Array[ComparePos_1];
        ComparePos_1++;
        Counting_Index++;
    }
    while (ComparePos_2 <= Most_Right_Index){
        temp[Counting_Index] = Array[ComparePos_2];
        ComparePos_2++;
        Counting_Index++;
    }

    for (int i = 0; i < Counting_Index; i++){
        Array[i] = temp[i];
    }

}
void Dived(int Most_Left_Index, int Most_Right_Index, ElementType *Array, ElementType *temp){
    
    int Center;

    if (Most_Left_Index < Most_Right_Index){
        Center = (Most_Left_Index + Most_Right_Index) / 2;
        Dived(Most_Left_Index, Center, Array, temp);      // Dived right side of Array
        Dived(Center + 1, Most_Right_Index, Array, temp); // Dived left side of Array
        Combine(Most_Left_Index, Center + 1, Most_Right_Index, Array, temp);
    }

}
void MergeSort(int Size, ElementType *Array){
    
    ElementType *temp = (ElementType *)malloc(sizeof(ElementType) * Size);
    Dived(0, Size - 1, Array, temp);
    
    free(temp);
}


void QuickSortByRange(int Most_Left_Index, int Most_Right_Index, ElementType *Array){

    if (Most_Right_Index - Most_Left_Index < 0) {return;}

    int Pivot = Array[Most_Right_Index];
    int Pivot_Index = Most_Right_Index;

    int Count_Left = Most_Left_Index;
    int Count_Right = Most_Right_Index - 1;

    while (1){
        while (1){
            if (Count_Left <= Count_Right && Pivot > Array[Count_Left]) {Count_Left++;}
            else {break;}
        }
        while (1){
            if (Count_Left <= Count_Right && Pivot < Array[Count_Right]) {Count_Right--;}
            else {break;}
        }

        if (Count_Left < Count_Right){
            Swap(&Array[Count_Left], &Array[Count_Right]);
        }   else {break;}
    }

    if (Pivot < Array[Count_Left]) {Swap(&Array[Count_Left], &Array[Pivot_Index]);}
    QuickSortByRange(Most_Left_Index, Count_Left - 1, Array);
    QuickSortByRange(Count_Left + 1, Most_Right_Index, Array);
}
void NormalQuickSort(int Size, ElementType *Array){ // set pivot as last element
    QuickSortByRange(0, Size - 1, Array);
}

int SetMedian(int index_1, int index_2, ElementType *Array){ // returrn median's value and set median as last element

    int Center_Index = (index_1 + index_2) / 2;

    if (Array[index_1] > Array[Center_Index]) {Swap(&Array[index_1], &Array[Center_Index]);}
    if (Array[index_1] > Array[index_2]) {Swap(&Array[index_1], &Array[index_2]);}
    if (Array[Center_Index] < Array[index_2]) {Swap(&Array[Center_Index], &Array[index_2]);}

    return Array[index_2];
}
void QuickSortByMedian(int Most_Left_Index, int Most_Right_Index, ElementType *Array){

    if (Most_Right_Index - Most_Left_Index <= 0) {return;}

    int Pivot = SetMedian(Most_Left_Index, Most_Right_Index, Array);
    int Pivot_Index = Most_Right_Index;

    int Count_Left = Most_Left_Index;
    int Count_Right = Most_Right_Index - 1;

    while (1){
        while (1){
            if (Pivot > Array[Count_Left]) {Count_Left++;}
            else {break;}
        }
        while (1){
            if (Pivot < Array[Count_Right]) {Count_Right--;}
            else {break;}
        }

        if (Count_Left < Count_Right){
            Swap(&Array[Count_Left], &Array[Count_Right]);
        }   else {break;}
    }

    if (Pivot < Array[Count_Left]) {Swap(&Array[Count_Left], &Array[Pivot_Index]);}
    QuickSortByRange(Most_Left_Index, Count_Left - 1, Array);
    QuickSortByRange(Count_Left + 1, Most_Right_Index, Array);

}
void MedianQuickSort(int Size, ElementType *Array){ // set pivot as median of 0, n, n/2 th elements
    QuickSortByMedian(0, Size - 1, Array);
}
