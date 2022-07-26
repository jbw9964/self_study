#include <stdio.h>
#include <stdlib.h>

// 문제 2 (p.446) : 동적 할당된 배열의 크기를 다시 바꾸는 프로그램

int *append(int *arr, int origin, int add);

int main() {
    printf("\ncode_start\n\n");
    
    int origin;
    int *arr;
    printf("How many arries (in int) do you want? : ");
    scanf("%d", &origin);

    arr = (int *)malloc(sizeof(int) * origin);
    for (int i = 0; i < origin; i++) {arr[i] = i;}

    int add;
    printf("How many more arries (in int) do you want? : ");
    scanf("%d", &add);
    arr = append(arr, origin, add);

    for (int i = 0; i < origin + add; i++) {printf("arr[%d] : %d\n", i, arr[i]);}

    printf("\n\ncode_end\n\n");
    return 0;
}

int *append(int *arr, int origin, int add){      // ?? 이게 되네? 지ㅣ린다 ㄷ ㄷ
    int *new_arr;
    new_arr = (int *)malloc(sizeof(int) * (origin + add));
    new_arr = arr;
    return new_arr;
}

// 궁금한 점 : 문제 의도가 이렇게 하라는 게 맞나...?
// + 동적 할당으로 만든 (int)형 배열은 초기값이 그냥 0이던데 이유..? 가 궁금하기도 하고 아니기도 하고...
// 아쉬운 점 : append 함수 들어가는 인자가 origin, add 가 들어가야 되는데 이걸 피하고서는 안되는지 궁금함.
// 그냥 append 함수 내에서 add 는 만들 수는 있는데 이런방식(?) 말고?

// 진도 : p.446