#include <stdio.h>
#include <stdlib.h>

// 문제 1 (p.446) : 학생별 평균으로 등수를 출력하는 프로그램
// 과목 귀찮으니 3개로

struct score {
    int score[3];       // 과목별 점수
    int average;        // 학생의 평균
    int sort;           // 학생의 등수
};

void data(struct score *arr);       // 점수 입력하는 함수
void ave(struct score *arr);        // 점수를 토대로 평균을 계산, 넣어주는 함수
int sort(struct score *arr, int student, int input);    // 평균을 토대로 (input) 번째 학생의 등수를 반환하는 함수

int main() {
    printf("\ncode_start\n\n");
    
    struct score *arr;
    int student;
    printf("How many student? : ");
    scanf("%d", &student);

    arr = (int *)malloc(sizeof(int) * student);
    for (int i = 0; i < student; i++){
        printf("\nType %d students score.\n", i + 1);
        data(&arr[i]);
    }
    for (int i = 0; i < student; i++) {ave(&arr[i]);}
    
    for (int i = 0; i < student; i++) {arr[i].sort = sort(arr, student, i);}

    printf("\n");
    for (int i = 0; i < student; i++){
        printf("%d 번째 학생의 등수 : %d\n", i + 1, arr[i].sort);
    }
    
    printf("\n\ncode_end\n\n");
    return 0;
}

void data(struct score *arr){
    for (int i = 0; i < 3; i++){
        int answer;
        printf("subject_%d : ", i + 1);
        scanf("%d", &answer);
        arr->score[i] = answer;
    }
}
void ave(struct score *arr){
    int sum = 0;
    for (int i = 0; i < 3; i++){
        sum += arr->score[i];
    }
    arr->average = sum / 3;
}
int sort(struct score *arr, int student, int input){
    int count = 1;
    int value = arr[input].average;
    for (int i = 0; i < student; i++){
        if (value < arr[i].average) count++;
    }
    return count;
}

// 아쉬운 점 : 귀찮기도 했었지만 처음에 과목수를 지정 해둬야 되는 점이 아쉬움.
// 뭔가 방법이 있을 것 같은데 그러면 애초에 struct 를 사용해서 만들면 안되는 걸 지도 모르겠음.

// 진도 : p.446