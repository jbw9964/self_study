#include <stdio.h>

int main() {
    printf("\ncode_start\n\n\n");

    // 9장 문제 1 - p.147 : 입력받은 학생들의 성적을 높은 순으로 배열하기

    int student;
    printf("학생은 몇명인가요 : ");
    scanf("%d", &student);

    int arr_1[student];
    int arr_2[student]; /* 1 : 입력값을 저장할 배열, 2 : 값들을 높은 순으로 배열시킬 배열*/

    for (int a = 0; a < student; a++) {
        printf("%d 번째 학생 성적 : ", a + 1);
        scanf("%d", &arr_1[a]);
    }

    printf("\n성적을 높은 순으로 배열한 결과입니다.\n\n");

    for (int j = 0; j < student; j++){
        int max = 0;
        int count = 0;

        for (int k = 0; k < student; k++){
            if (arr_1[k] >= max){
                max = arr_1[k];
                count = k;
            }
        }
        arr_2[j] = max;
        arr_1[count] = 0;

        printf("학생 %d : %d\n", count + 1, arr_2[j]);
    }
    
    printf("\n\n\ncode_end\n");
    return 0;
}