#include <stdio.h>

int main() {
    printf("\ncode_start\n\n\n");

    // 문제 7 임의의 자연수 n 을 받아 소인수 분해하기. 18 = 2 * 3 * 3

    unsigned long long num;
    printf("What number do you want to know? : ");
    scanf("%lld", &num);

    printf("\nThe number %llu is made of ", num);

    for (unsigned long long i = 2; i <= num; i++){
        for (unsigned long long j = 2; num % i == 0; j++){
            num = num / i;
            printf("%llu * ", i);
        }
    }



    printf("\n\n\ncode_end\n");
    return 0;
}

// 아쉬운 점 : 내가 스스로 생각해내지 못함.
// 어떻게 해야되는지 모르겠어서 구글링 토대로 만듬.
// num = num / i 할 생각을 못했음. 그래도 이해는 하긴 했지만 아쉬움. 코드 핵심은 num 값이 2번째 for 빠져나가도 num 값이 유지되는 점임.