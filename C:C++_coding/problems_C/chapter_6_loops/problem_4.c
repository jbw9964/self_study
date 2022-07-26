#include <stdio.h>

int main() {
    printf("\ncode_start\n\n\n");


    // 피보나치 수열 계산하기 (10000 이하) --> 짝수 항들의 합 구하기
    /*피보나치 수열 : (n번째 항) = (n-1번째 항) + (n-2번째 항)
    3 : 2
    4 : 3
    5 : 5
    6 : 8 
    */

    int fib_1 = 0; // 0번째 항
    int fib = 1; // 1번째 항

    int num;
    printf("몇 보다 작은 피보나치 수열을 보고싶습니까? : ");
    scanf("%d", &num);

    int i = 2; // i 번째 항
    printf("\n%d 보다 작은 피보나치 수는 ", num);
    
    int sum = 0;

    if (num <= 1){
        printf("없습니다.\n\n");
        return 0;
    } else {
        printf("%d(1)", fib);
    }

    for (; ; i++){ // i번째 피보나치 수열 : fib (2항 부터 시작)
        fib = fib + fib_1;      // 2항 (i)
        fib_1 = fib - fib_1;    // 1항 (i-1)

        

        if (fib >= num){
            break;
        }
        if (i % 2 == 0){
            sum = sum + fib;
        }
        printf(", %d(%d)", fib, i);
    }
    
    printf("\n\n%d 보다 작은 피보니치 수 중 짝수번째 항들의 합은 %d 입니다.", num, sum);

    printf("\n\n\ncode_end\n");
    return 0;
}

/*아쉬운 점*/
/*입력 숫자가 1 이하일 때 그냥 if를 써서 코드 넘김. 이걸 for 안에 넣고 싶은데 어떻게 해야될지 좀 복잡해 보여서 안함.*/