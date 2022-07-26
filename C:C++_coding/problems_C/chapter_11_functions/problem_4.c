#include <stdio.h>

// 문제 4 : N까지의 소수의 개수 출력하기 (p.223)

int fun_1(int a) { // 받은 값이 소수인지 아닌지 판별하는 함수
                   // a : 입력 값
    
    for (int j = 2; j < a; j++){
        if (a % j == 0){return 0;}
    }
    return 1;
} // true : 1, false : 0

int main() {
    printf("\ncode_start\n\n\n");

    int num;
    printf("N : ");
    scanf("%d", &num);
    int count = 0;

    for (int i = 2; i <= num; i++){
        if (fun_1(i) == 1){
            count++;
        }
    }
    printf("The number of the prime numbers under %d : %d", num, count);

    printf("\n\n\ncode_end\n");
    return 0;
}
// 아 함수 이용하니까 확실히 편해지고 보기 편해지네
// 같은 코드(?), 핵심은 같더라도 훨씬 보기 좋고 편한듯

// 아쉬운 점 : 큰 수를 넣어도 연산 빨라지도록 i나 j를 홀수넣고 돌려서(?) 하고싶은데 약간씩 꼬임


// 진도 : p.223