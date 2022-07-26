#include <stdio.h>

// 문제 1 (p.240) : 받은 원소를 큰 순으로 출력하는 함수 만들기

int max(int *input[], int num); // 배열의 원소 중 최대값을 출력하고 그 값을 0으로 바꿔주는 함수
int main() {
    printf("\ncode_start\n\n\n");
    
    int num;
    printf("몇개의 원소를 집어넣을 건가요? : ");
    scanf("%d", &num);

    int arr[num];
    for (int i = 0; i < num; i++){
        printf("%d 번째 원소 값 : ", i + 1);
        scanf("%d", &arr[i]);
    }

    int *point_arr[num]; 
    for (int i = 0; i < num; i++) point_arr[i] = &arr[i];
    int record[num];
    
    printf("\n");
    for (int i = 0; i < num; i++){
        record[i] = max(&point_arr[0], num);
        printf("%d번째 원소 : %d\n", i + 1, record[i]);
    }

    printf("\n\n\ncode_end\n");
    return 0;
}

int max(int *input[], int num){
    int max = *input[0];
    int count = 0;
    for (int i = 1; i < num; i++){
        if (max < *input[i]){
            max = *input[i];
            count = i;
        }
    }
    *input[count] = 0; // 결국 마지막엔 처음 배열 arr가 모두 0이 됨
    return max;
}
// 아쉬운 점 : arr를 0으로 만들지 않고 다른 방법은 없는지 궁금함.


// 진도 : p.240