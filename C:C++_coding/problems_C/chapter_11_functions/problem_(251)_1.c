#include <stdio.h>

// 문제 1 (p.251) : 5명 학생 성적 (국어, 영어, 수학) 받고 평균이 가장 높은 사람부터 정렬
// 평균 기준으로 평균 이상인 사람 합격, 불합격 출력

double eval_ave(double (*arr)[3]);                               // 학생 한명의 평균을 계산해 출력하는 함수
double max(double *ave, int *order);                             // 학생들의 평균 중 가장 높은 값을 출력하는 함수
int eval_pass(double *ave_1, int *order, double total_ave);      // 학생이 합격인지 불합격읹지 확인하는 함수

int main() {
    printf("\ncode_start\n\n\n");

    double arr[5][3]; // 성적 넣는 배열
    double ave[5];    // 평균 넣는 배열
    int order[5];     // 순서 적어두는 배열

    for (int i = 0; i < 5; i++){
        printf("%d번학생 성적 (국어, 영어, 수학) : ", i + 1);
        for (int j = 0; j < 3; j++){
            scanf("%lf", &arr[i][j]);
        }
        printf("\n");
    }

    double (*point_arr)[3] = arr;
    double *point_ave;
    point_ave = ave;
    int *point_order;
    point_order = order;
    
    for (int i = 0; i < 5; i++){            // 평균값 계산 후 ave에 집어넣음
        ave[i] = eval_ave(&point_arr[i]);   // 각 학생들의 평균 계산, ave에 집어넣음
    }
    printf("\n");

    double ave_1[5];                                    // 내림차순으로 정렬된 배열
    for (int i = 0; i < 5; i++){                        // ave 함수에서 가장 큰 수를 출력시키고 그 값을 새로운 배열 ave_1에 저장함
        ave_1[i] = max(point_ave, &point_order[i]);     // i + 1 번째 큰 평균 순서: order[i], i + 1 번째 학생
    }
    // 지금까지 평균 값을 내림차순으로 정리, 몇번재 학생 데이터인지 저장하는 거 만들음.

    double total_ave = 0.0;                             // 전체 평균 계산
    for (int i = 0; i < 5; i++) { total_ave = total_ave + ave_1[i]; }
    total_ave = total_ave / 5;
    
    printf("전체 평균 : %.1f\n\n", total_ave);
    for (int i = 0; i < 5; i++){
        if (eval_pass(&ave_1[i], &point_order[i], total_ave) == 1) printf("합격\n\n");
        else printf("불합격\n\n");
    }
    
    

    printf("\n\n\ncode_end\n");
    return 0;
}

double eval_ave(double (*arr)[3]){      // i번째 학생 데이터 첫번째 걸로 생각
    double sum = 0;
    for (int i = 0; i < 3; i++){
        sum += arr[0][i];
    }
    double ave = sum / 3;
    return ave;
}

double max(double *ave, int *order){ // 들어온 배열의 최대값을 출력하고 몇번째 학생인지도 출력. 다음 계산을 위해 그 학생 성적은 0으로 만들고 순서도 ordder에 저장.
    double max = ave[0];
    int count = 0;
    for (int i = 0; i < 5; i++){
        if (max <= ave[i]) {
            max = ave[i];
            count = i;
        }
    }
    ave[count] = 0;
    order[0] = count;
    return max;
}

int eval_pass(double *ave_1, int *order, double total_ave){         // 합격 : 1, 불합격 : 0
    printf("%d 번째 학생의 평균 : %.1f --> ", order[0] + 1, ave_1[0]);
    if (ave_1[0] > total_ave) return 1;
    else return 0;
} 


// 진도 : p.251