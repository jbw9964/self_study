#include <stdio.h>

// 문제 4 (p.251) : 계산기 만들기, 이전의 계산 결과는 계속 누적되고 지우는 기능도 있어야 함.

double cal(char *variable, double *num, double *result, double *previous);      // 연산 부호 판별 함수
double can(char *variable, double *num, double *result, double *previous);      // 취소했을 때 함수
double add(char *variable, double *num, double *result, double *previous);      // 덧셈 함수
double multi(char *variable, double *num, double *result, double *previous);    // 곱셈 함수
double fin(char *variable, double *num, double *result, double *previous);      // 끝내기 함수

int main() {
    printf("\ncode_start\n\n\n");

    double result = 0.0;
    double num;
    double *point_result = &result;
    double *point_num = &num;
    
    double previous;
    double *point_previous = &previous;
    char variable;
    char *point_variable = &variable;

    printf("Warning. Please press the numbers and operators one by one with pressing enter\n");
    printf("Canclation variable : 'c' OR 'e'\n");
    printf("===================================Calculator===================================\n\n");
    
    scanf("%lf", &num);
    cal(point_variable, point_num, point_result, point_previous);

    printf("\n\n===================================Calculator===================================");

    printf("\n\n\ncode_end\n");
    return 0;
}

double cal(char *variable, double *num, double *result, double *previous){
    printf("\nCalculation : %.3f ", *num);
    scanf("%s", variable);

    if (*variable == '+' || *variable == '-') add(variable, num, result, previous);
    else if (*variable == '*' || *variable == '/') multi(variable, num, result, previous);
    else if (*variable == '=') fin(variable, num, result, previous);
    else if (*variable == 'c' || *variable == 'e') can(variable, num, result, previous);
    else printf("\nYou put the wrong calculation sign : %c", *variable); return 0;
    
    return 0;
}

double can(char *variable, double *num, double *result, double *previous){          // previous : 취소했을 때 연산 이전 숫자로 돌려줌
    printf("\nCalculation canceled\nReturn to previous calculation\n");
    cal(variable, previous, previous, previous);
    return 0;
}

double add(char *variable, double *num, double *result, double *previous){ 
    printf("\nCalculation : %.3f %c ", *num, *variable);
    double num_1;
    scanf("%lf", &num_1);
    
    *previous = *num;

    printf("\nCalculation : %.3f %c %.3f = ", *num, *variable, num_1);
    if (*variable == '+') *result = *num + num_1;
    else *result = *num - num_1;
    printf("%.3f\n", *result);

    cal(variable, result, result, previous);
    
    return 0;
}

double multi(char *variable, double *num, double *result, double *previous){
    printf("\nCalculation : %.3f %c ", *num, *variable);
    double num_1;
    scanf("%lf", &num_1);
    
    *previous = *num;

    printf("\nCalculation : %.3f %c %.3f = ", *num, *variable, num_1);
    if (*variable == '*') *result = *num * num_1;
    else *result = *num / num_1;
    printf("%.3f\n", *result);

    cal(variable, result, result, previous);
    
    return 0;
}

double fin(char *variable, double *num, double *result, double *previous){
    printf("\nExiting calculator");
    printf("\nFianl calculation : %.3f\n", *result);
    return 0;
}

/* 아쉬운 점
뭔가 어떻게 만들기는 했는데 마음에 들지 않음.
계산을 취소시키려면 계산 부호 입력할 때 c, e 눌러야 되는데 만약 숫자 입력할 때 넣으면 깨짐
그리고 함수 각각으로 만들어 두긴 했는데 뭔가 쓸때없이 복잡하게 만든 느낌
마지막으로 계산 취소를 시켜도 이전 연산 전 값으로만 돌아가지 그것보다 전이나 그 계산이 어떻게 이루어 졌었던 건지 나타내질 못함
*/

// 진도 : p.251