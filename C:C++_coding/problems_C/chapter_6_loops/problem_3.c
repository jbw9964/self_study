#include <stdio.h>

int main() {
    printf("\ncode_start\n\n\n");


    // 1000 이하의 3 또는 5의 배수인 자연수들의 합을 구하기 --> 입력한 수 이하로 계산하기

    int num = 0;
    printf("Number : ");
    scanf("%d", &num);

    int sum;
    for (int i = 1; i <= num; i++){
        if (i % 3 == 0 || i % 5 == 0){
            sum = sum + i;
        }
    }

    printf("\n\nThe sum of the number : %d\n", sum);

    printf("\n\n\ncode_end\n");
    return 0;
}