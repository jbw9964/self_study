#include <stdio.h>

int main() {
    printf("\ncode_start\n\n\n");

    // n 까지의 수를 곱함

    int num;
    printf("숫자를 입력하시오 : ");
    scanf("%d", &num);

    int power = 1;

    for(int i = 1 ; i <= num; i++){
        power = power * i;
    }
    
    printf("The powers of the numbers under %d is %d (including number 5)", num, power);

    printf("\n\n\ncode_end\n");
    return 0;
}