#include <stdio.h>

// 문제 3 (p.251) : 자기자신을 호출하는 함수를 이용. 1부터 특정한 수까지의 곱을 구하는 프로그램 만들기
// 10까지의 수 곱하는 프로그램

int loop(int *a, int *multi);

int main() {
    printf("\ncode_start\n\n\n");

    int a;
    int *point_a = &a;
    int multi = 1;
    int *point_multi = &multi;

    printf("What number do you want? : ");
    scanf("%d", &a);
    printf("\n");

    printf("The multiplies under the number %d are : ", a);
    loop(point_a, point_multi);
    printf("%d\n", multi);

    printf("\n\n\ncode_end\n");
    return 0;
}

int loop(int *a, int *multi){
    if (*a == 1) return 0;

    *multi *= *a;
    *a = *a - 1;

    loop(a, multi);

    return 0;
}


// 진도 : p.251