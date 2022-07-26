#include <stdio.h>

int main() {
    printf("\ncode_start\n\n\n");

    // 9장 문제 2 - p.147 : 학생들의 성적을 그래프로 나타내기

    int student;
    printf("학생은 몇명인가요 : ");
    scanf("%d", &student);

    int arr[student];

    for (int a = 0; a < student; a++) {
        printf("%d 번째 학생 성적 : ", a + 1);
        scanf("%d", &arr[a]);
    }

    printf("\n학생들의 성적을 그래프로 나타낸 결과입니다.\n\n");

    int sum = 0;
    for (int b = 0; b < student; b++) sum += arr[b];
    const int total = sum;

    for (int i = 0; i < student; i++){
        int j = (int) 50*arr[i]/total;
        printf("%d 번째 학생 : ", i + 1);
        for (int k = 1; k <= j; k++) printf("◼︎"); // 특수문자(?)여도 입력 되는듯?
        printf("\n");
    }

    printf("\n\n\ncode_end\n");
    return 0;
}

// 아쉬운 점 : 그래프로 나타내는 게 이렇게 문자(?) 말고 뭔가 다른 거 써서 하는 방법은 없나? 뭐 math.h? 이런거 이용해서?