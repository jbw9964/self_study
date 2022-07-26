#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* p. 81 : 문제 2.27
N*N 행렬이 메모리상 있다 가정한다. 각 행은 왼쪽에서 오른쪽으로, 각 열은 위에서 ㅇ아래로 증가한다.
주어진 수 X가 이 행렬의 원소인지를 결정하는 최악의 성능 O(N) 알고리즘을 제시하라.
*/

bool cal(int **array, int number, int value);

int main(){
    printf("\ncode_start\n\n\n\n");

    int number, value;
    printf("number : ");
    scanf("%d", &number);
    printf("value : ");
    scanf("%d", &value);

    int **array;
    printf("input array\n");
    array = (int **)malloc(sizeof(int *) * number);
    for (int i = 0; i < number; i++){
        array[i] = (int *)malloc(sizeof(int) * number);
    }

    for (int i = 0; i < number; i++){
        for (int j = 0; j < number; j++){
            scanf("%d", &array[i][j]);
        }
    }

    bool result = cal(array, number, value);

    if (result == true) {printf("There is value : true");}
    else {printf("There isn't value : false");}


    printf("\n\n\n\ncode_end\n\n");
    return 0;
}

bool cal(int **array, int number, int value){

    int current_row = 0;
    int current_column = number - 1;

    while (true){
        if (current_column == -1) {break;}
        if (array[current_row][current_column] == value) {return true;}

        if (array[current_row][current_column] > value){
            current_column--;
        }   else if (array[current_row][current_column] < value){
            current_row++;
        }   else {continue;}
    }

    return false;
}

/*
3 3
1 2 3
4 5 6
7 8 9
--> 있음

4  10
1 2 3 4 
2 3 4 5 
6 7 8 9 
7 8 9 11
--> 없음



*/

