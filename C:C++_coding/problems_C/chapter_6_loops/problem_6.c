#include <stdio.h>

int main() {
    printf("\ncode_start\n\n\n");

    // 문제 6 A + B + C = 2000, A > B > C 임을 만족하는 자연수 쌍의 개수 구하기

    int a, b, c;
    int num; // 입력 숫자
    int num_1;

    printf("Nuber : ");
    scanf("%d", &num);

    int count = 0;

    for (a = 1; a <= num; a++){  // 순서 쌍 (a, b, c) : a가 1일 때부터 시작
        num_1 = num - a; // 5 에서 1(a)를 뺀 숫자 (4)
        for (b = 1; b <= num_1; b++){ // b : 1
            c = num_1 - b; // c : num - b

            if (a > b && b > c && a > c && c > 0){ // 조건 만족할 때만 count
                count++;
                printf ("\n(a, b, c) : (%d, %d, %d)", a, b, c);
            }
        }

    }


    printf("\n\nThe combination of the numbers, that qualify (A + B + C = %d), are above.\n", num);
    printf("And the numbers of the combinations are %d", count);


    printf("\n\n\ncode_end\n");
    return 0;
}