#include <stdio.h>

// 문제 2 (p.251) : 유클리드 호제법으로 N개 수들의 최대공약수 구하기
// 유클리드 호제법 : 수 a, b가 있을 때 두 수의 최대공약수는 두 수를 서로 나눈 나머지를 계속 시행했을 때, 나머지가 0이 나오는 수와 같다.
/* [136] [24]
136 % 24 = 16
24 % 16 = 8
16 % 8 = 0 --> 최대공약수 : 8

[확인] 
136 : 2 * 2 * 2 * 17
24 : 2 * 2 * 2 * 3
*/

int gcd(int *a, int *b);        // Greatest Common Divisor
int swap(int *a, int *b);

int main() {
    printf("\ncode_start\n\n\n");

    int a, b;
    printf("Which number do you want to know? : (A,B) : ");
    scanf("%d %d", &a, &b);
    printf("\n");

    if (a == b) {printf("A and B are same number\n\n"); return 0;}
    else if (a == 1 || b ==1) {printf("There's no GCD between two numbers : 1\n\n"); return 0;}

    int *point_a = &a;
    int *point_b = &b;

    swap(point_a, point_b);
    printf("The GCD between %d and %d are : ", a, b);
    
    for (int i = 0;;i++){
        if (gcd(point_a, point_b) == 0) break;
    }

    printf("%d\n", a);

    printf("\n\n\ncode_end\n");
    return 0;
}

int gcd(int *a, int *b){
    swap(a, b);             // a, b 큰 순서대로 나타냄
    *a = *a % *b;
    swap(a, b);
    return *b;               // b가 0이 되면 위에 for에서 멈춤, 딱 나눠떨어질 때, swap에서 b를 작은거라고 했으니까
}

int swap(int *a, int *b){
    if (*a < *b){             // 생각하기 편하게 a, b 순서 큰대로 나타내기 : (a > b)
        int swap = *a;
        *a = *b;
        *b = swap;
    }
    return 0;
}


// 진도 : p.251