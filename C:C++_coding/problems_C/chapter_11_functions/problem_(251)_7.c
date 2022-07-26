#include <stdio.h>

// 문제 7 (p.251) : 1000 자리수들의 덧셈, 뺄셈, 곱셈, 나눗셈을 수행하는 프로그램 만들기. 소수 부분은 잘라도 됨
// 애초에 1000 자리수까지 메모리를 할당할 수 없음. 값 크기가 애초에 그렇게 넣을 수 없음. 그럼 어떻게 해야될까? 가 문제 포인트인듯
// 1000 자리수 * a, b 라고 가정하자.
// double은 15자리수 까지 가능하다 함.

// 만들다 포기 ㅅㅂ 진짜 못하겠다. 그나마 더하기랑 빼기 만들고 있었는데 애초에 처음부터 잘못한게 숫자 입력을 int a, b로 했는데
// 그러면 a, b가 int형 최대범위밖에 지정못하는 거니까 잘못만듬 ㅅㅂ

int append(int a, int b, char *point_arr_a, char *point_arr_b, int *point_num_a, int *point_num_b);
int count(int a, int b, int *point_num_a, int *point_num_b);
int add(char var, char *point_arr_a, char *point_arr_b, int num_a, int num_b, char *point_result);
int mul(char *point_arr_a, char *point_arr_b, int num_a, int num_b, char *point_result);
int div(char *point_arr_a, char *point_arr_b, int num_a, int num_b, char *point_result);
int power_10(int i);            // 10^i

int main() {
    printf("\ncode_start\n\n\n");

    char arr_a[1000];
    char arr_b[1000];
    char result[1000];
    for (int i = 0; i < 1000; i++){
        arr_a[i] = 0;
        arr_b[i] = 0;
        result[i] = 0;
    }
    char *point_arr_a = arr_a;
    char *point_arr_b = arr_b;
    char *point_result = result;
    char var;

    int num_a, num_b;
    int *point_num_a = &num_a;
    int *point_num_b = &num_b;
    int a, b;

    printf("(A, B) : ");
    scanf("%d %d", &a, &b);
    printf("Which operation do you want (+, -, *, /) : ");
    scanf("%s", &var);

    count(a,b, point_num_a, point_num_b);
    append(a, b, point_arr_a, point_arr_b, point_num_a, point_num_b);

    if (var == '+' || var == '-') add(var ,point_arr_a, point_arr_b, num_a, num_b, point_result);
    else if (var == '*') mul(point_arr_a, point_arr_b, num_a, num_b, point_result);
    else if (var == '/') div(point_arr_a, point_arr_b, num_a, num_b, point_result);
    else {printf("You put unknown operation : %c\n", var);  return 0;}
    
    printf("Result : ");
    for (int i = 0; i <= num_a; i++){
        printf("%d", point_result[999 - num_a + i]);
    }

    printf("\n\n\ncode_end\n");
    return 0;
}

int append(int a, int b, char *point_arr_a, char *point_arr_b, int *point_num_a, int *point_num_b){
    printf("\nappend started\n");
    for (int i = 0; i <= *point_num_a; i++){
        point_arr_a[999 - *point_num_a + i] = a / power_10(*point_num_a - i);
        a = a - point_arr_a[999 - *point_num_a + i] * power_10(*point_num_a - i);
    }
    for (int i = 0; i <= *point_num_b; i++){
        point_arr_b[999 - *point_num_b + i] = b / power_10(*point_num_b - i);
        b = b - point_arr_b[999 - *point_num_b + i] * power_10(*point_num_b - i);
    }
    return 0;
}

int count(int a, int b, int *point_num_a, int *point_num_b){        // 3 : 0자리수 (count_n_a : 0)
    int count_num_a = 0;
    int count_num_b = 0;
    int result_a = a;
    int result_b = b;
    for (int i = 0; ; i++){
        if (result_a / 10 == 0 && result_b / 10 == 0) break;
        if (result_a / 10 != 0) count_num_a++;
        if (result_b / 10 != 0) count_num_b++;
        result_a /= 10;
        result_b /= 10;
    }
    *point_num_a = count_num_a;
    *point_num_b = count_num_b;
    return 0;
}

int add(char var, char *point_arr_a, char *point_arr_b, int num_a, int num_b, char *point_result){  // 정상작동함. point_result에 결과갑 저장.
    int count;
    if (num_a > num_b) count = num_a;
    else count = num_b;
    num_a = count;
    num_b = count;
    if (var == '+'){
        for (int i = 0; i <= count; i++){
            point_result[999 - count + i] = point_arr_a[999 - count + i] + point_arr_b[999 - count + i];
        }
        for (int i = 0; ; i++){
            int result = 0;
            for (int j = 0; j <= count; j++){
                if (point_result[999 - j] > 10){
                    point_result[999 - j - 1]++;
                    point_result[999 - j] -= 10;
                    result = 1;
                }
            }
            if (result == 0) break;
        }
    }   else{   // 빼기 연산

        for (int i = 0; i <= count; i++){
            point_result[999 - count + i] = point_arr_a[999 - count + i] - point_arr_b[999 - count + i];
        }
        for (int i = 0; ; i++){
            int result = 0;
            for (int j = 0; j < count; j++){
                if (point_result[999 - j] < 0){
                    point_result[999 - j - 1]--;
                    point_result[999 - j] += 10;
                    result = 1;
                }
            }
            if (result == 0) break;
        }
    }
    return 0;
}

int mul(char *point_arr_a, char *point_arr_b, int num_a, int num_b, char *point_result){
    printf("\nmul started\n");
    return 0;
}

int div(char *point_arr_a, char *point_arr_b, int num_a, int num_b, char *point_result){
    printf("\ndiv started\n");
    return 0;
}

int power_10(int i){
    int result = 1;
    for (int j = 0; j < i; j++) {result *= 10;}
    return result;
}


// 진도 : p.251