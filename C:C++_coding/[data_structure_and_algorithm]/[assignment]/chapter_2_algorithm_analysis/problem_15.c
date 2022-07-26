#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* p. 81 : 문제 2.15
정수배열 A0 < A1 < ... < An 에서 Ai = i 를 만족하는 정수가 존재하는지를 결정하는 효율적인 알고리즘을 작성하라.
그 알고리즘의 실행시간은 어떻게 되는가?
*/

bool cal(int *array, int number);

int main(){
    printf("\ncode_start\n\n\n\n");

    int num, *array;

    printf("numbers : ");
    scanf("%d", &num);

    array = (int *)malloc(sizeof(int) * num);

    for (int i = 0; i < num; i++){
        scanf("%d", &array[i]);
    }

    printf("\n\n");

    bool result = cal(array, num);
    if (result == true) {printf("true");}
    else {printf("false");}

    printf("\n\n\n\ncode_end\n\n");
    return 0;
}

bool cal(int *array, int number){

    int low, high;
    low = 0;
    high = number;
    int mid = number / 2;

    while((mid != number - 1) && (mid != 0)){
        mid = (high + low) / 2;

        if (array[mid - 1] < mid){
            low = mid + 1;
        }   else if (array[mid - 1] > mid){
            high = mid - 1;
        }   else {return true;}
    }    
    mid = (high + low) / 2;

    if (array[mid - 1] == mid) {return true;}

    return false;
}

/*
10
-1 0 1 2 3 5 6 7 9 12
--> 있음

10
0 1 2 3 4 5 6 7 8 9
--> 없음

10
1 3 4 5 6 7 8 9 10 11
--> 있음
*/
