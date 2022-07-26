#include <stdio.h>

// 문제 2 : (p.360) : 큰 수를 덧셈, 뺄셈하는 프로그램 만들기. 구조체 이용해서

struct Number{
    char input_1[100];
    char input_2[100];
    int result[100];
    int sign;   // 0 이면 양수, 1 이면 음수
};

void num(struct Number *input, int *num_1, int *num_2);     // 100 - num : input 처음 시작하는 배열 자리수(?) : 123 --> [97]
void sort(struct Number *input, int num_1, int num_2);
void plus(struct Number *input, int *count);
void minus(struct Number *input, int *count);       // 큰 수에서 작은수 뺀 결과
void swap(struct Number *input, int num_1, int num_2); // 입력 한 수를 큰수, 작은수 순으로 바꿔주는 함수

int main() {
    printf("\ncode_start\n\n");
    
    struct Number input;
    for (int i = 0; i < 100; i++){
        input.input_1[i] = NULL;
        input.input_2[i] = NULL;
        input.result[i] = 0;
    }

    printf("input 1 : ");
    scanf("%s", input.input_1);
    printf("input 2 : ");
    scanf("%s", input.input_2);

    int num_1, num_2;
    num(&input, &num_1, &num_2);
    sort(&input, num_1, num_2);

    printf("Which operation do you want? (+ or -) : ");
    char variable[5];
    scanf("%s", variable);

    int count;
    if (variable[0] == '+') plus(&input, &count);
    else if (variable[0] == '-') {
        swap(&input, num_1, num_2);
        minus(&input, &count);
    }

    printf("Result : ");
    if (input.sign == 0){
        for (int i = 100 - count; i < 100; i++){
            printf("%d", input.result[i]);
        }
    } else{
        printf("-");
        for (int i = 100 - count; i < 100; i++){
            printf("%d", input.result[i]);
        }
    }
    


    printf("\n\ncode_end\n");
    return 0;
}

void num(struct Number *input, int *num_1, int *num_2){     // 100 - num : input 처음 시작하는 배열 자리수(?)
    int count = 0;
    for (int i = 0; ; i++){
        if (input->input_1[i] == NULL) break;
        count++;
    }
    *num_1 = count;
    count = 0;
    for (int i = 0; ; i++){
        if (input->input_2[i] == NULL) break;
        count++;
    }
    *num_2 = count;
}
void sort(struct Number *input, int num_1, int num_2){
    for (int i = 0; ; i++){
        if (input->input_1[i] == NULL) break;
        input->input_1[100 - num_1 + i] = input->input_1[i];
        input->input_1[i] = NULL;
    }
    for (int i = 0; ; i++){
        if (input->input_2[i] == NULL) break;
        input->input_2[100 - num_2 + i] = input->input_2[i];
        input->input_2[i] = NULL;
    }
}
void plus(struct Number *input, int *count){
    *count = 0;
    for (int i = 99; ; i--){
        if (input->input_1[i] == NULL && input->input_2[i] == NULL) break;
        if (input->input_1[i] == NULL || input->input_2[i] == NULL){
            input->result[i] = input->input_1[i] + input->input_2[i] - 48;
        }   else input->result[i] = input->input_1[i] + input->input_2[i] - 96;
        *count += 1;
    }
    for (int i = 99; i > 99 - *count; i--){
        if (input->result[i] >= 10){
            input->result[i - 1]++;
            input->result[i] -= 10;
        }
    }
    input->sign = 0;
}
void minus(struct Number *input, int *count){
    *count = 0;
    for (int i = 99; ; i--){
        if (input->input_1[i] == NULL && input->input_2[i] == NULL) break;
        if (input->input_1[i] == NULL || input->input_2[i] == NULL){
            input->result[i] = input->input_1[i] - input->input_2[i] - 48;
        }   else input->result[i] = input->input_1[i] - input->input_2[i];
        *count += 1;
    }
    for (int i = 99; i > 99 - *count; i--){
        if (input->result[i] < 0){
            input->result[i - 1]--;
            input->result[i] += 10;
        }
    }
}
void swap(struct Number *input, int num_1, int num_2){
    char temp;
    int result = 0;
    input->sign = 0;

    if (num_2 > num_1){
        for (int i = 99; ; i--){
            if (input->input_1[i] == NULL && input->input_2[i] == NULL) break;
            temp = input->input_1[i];
            input->input_1[i] = input->input_2[i];
            input->input_2[i] = temp;
        }
        input->sign = 1;
    }   else if (num_1 == num_2){
        for (int i = 100 - num_1; i < 100; i++){
            if (input->input_2[i] > input->input_1[i]) {
                result = 1;
                break;
            }
        }
        if (result == 1){
            for (int i = 99; ; i--){
                if (input->input_1[i] == NULL && input->input_2[i] == NULL) break;
                temp = input->input_1[i];
                input->input_1[i] = input->input_2[i];
                input->input_2[i] = temp;
            }
            input->sign = 1;
        }
    }
}

// 아쉬운 점 : 덧셈, 뺄셈은 어떻게 만들었는데 곱셈이랑 나눗셈은 안만듬.
// 곱셈은 그나마 어떻게 할 수 있을 것 같은데 나눗셈은... ㄹㅇ 머리가 하예진다

// 진도 : p.360