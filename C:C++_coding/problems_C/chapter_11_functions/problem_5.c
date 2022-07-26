#include <stdio.h>

// 문제 5 : 숫자 N을 소인수분해하기 (p.223)

int evalu_fun(int input_1){ // 받은 수를 가장 작은 수 (2부터 시작)로 한번 나눠주는 함수
    for (int j = 2; j < input_1; j++){
        if (input_1 % j == 0) {
            input_1 = input_1 / j;
            return input_1; // input을 한번 나눠준 수로 돌려줌
            }
    }
    return 0; // 더이상 숫자가 나눠지지 않을 때
}

int print_fun(int input_1){ // 위에거랑 다를 거 없는데 print까지 하는 함수 : 원래 위에 printf까지 있었는데 input = fun(input)하는 과정에서 출력까지 되서 이렇게 바꿈
    for (int j = 2; j < input_1; j++){
        if (input_1 % j == 0) {
            input_1 = input_1 / j;
            printf("%d * ", j);
            return input_1; 
            }
    }
    printf("%d", input_1);
    return 0; 
}

int main() {
    printf("\ncode_start\n\n\n");
    
    int num;
    printf("Number : ");
    scanf("%d", &num);

    printf("\n%d = ", num);

    int input = num;

    for (int i = 0;; i++){
        if (evalu_fun(input) == 0){
            print_fun(input);
            break;
        }   else {
            print_fun(input);
            input = evalu_fun(input);
        }
    }

    printf("\n\n\ncode_end\n");
    return 0;
}

// 진도 : p.223