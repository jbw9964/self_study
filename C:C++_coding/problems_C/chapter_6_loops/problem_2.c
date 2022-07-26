#include <stdio.h>

int main() {
    printf("\ncode_start\n\n\n");

    int row;
    printf("How many row do you want? : ");
    scanf("%d", &row);

     // i : 몇 번째 줄 까지 , j : 몇 번째 글자
    int collum = 2*row - 1; // 총 출력행야 되는 글자 수 (3줄 --> 5글자)

    printf("\n\n");
    for(int i = 1;i <= row; i++){
        int j = 1;
        for (; j <= collum; j++){
            if (j <= collum +1 - i && j >= i){
                printf("*");

            }   else {
                printf(" ");
            }
        }
        printf("\n");
    }




    printf("\n\n\ncode_end\n");
    return 0;
}