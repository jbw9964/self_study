#include <stdio.h>

// 문제 5 (p.251) : N진법에서 M진법으로 바꾸기

int n_decimal(int n, int *num);           // n진법에서 10진법으로 바꾼 수를 반환하는 함수
int append_n(int *num_1);                 // 입력된 값의 첫번째 값을 반환하고 한 자리수를 줄여주는 함수
int power(int n, int i);                  // C언어에 자체 제곱 기능이 없어서 math.h 넣기 귀찮으니까 제곱하는 함수 그냥 만듬. n^i
int decimal_m(int m, int *num);           // 10진법에서 m진법으로 바꾼 수를 반환하는 함수
int append_m(int m, int *num_1, int *count); // 입력된 값을 m 진수로 나타낼 때 몇자리 수 인지 계산해 count에 저장, 추후 연산을 위해 나머지(?)를 반환.

int main() {
    printf("\ncode_start\n\n\n");

    int n, m;
    int num, num_1;
    
    printf("N진법에서 M진법으로 바꾸기\n");
    printf("N(진법) : ");
    scanf("%d", &n);
    printf("M(진법) : ");
    scanf("%d", &m);
    printf("%d진법 숫자 : ", n);
    scanf("%d", &num);
    num_1 = num;

    printf("2 %% 2 : %d\n", 2 % 2);
    int *point_num = &num;
    num = n_decimal(n, point_num);
    printf("\nnum : %d\n", num);

    num = decimal_m(m, point_num);
    printf("\nnum : %d\n", num);


    printf("\n%d진법 --> %d진법\n", n, m);
    printf("%d(%d) --> %d(%d)", num_1, n, num, m);
    
    printf("\n\n\ncode_end\n");
    return 0;
}

int n_decimal(int n, int *num){         // num : 입력되고 계산 한자리씩 없어지는 수
    int num_1;
    num_1 = *num;
    int decimal = 0;

    for (int i = 0; ; i++){
        decimal = decimal + power(n, i) * append_n(&num_1);
        if (num_1 == 0) {break;}
    }
    return decimal;
}

int append_n(int *num_1){
    int append = *num_1, first;
    append = (int)append / 10;
    append = append * 10;

    first = *num_1 - append;                    // 입력된 수의 첫번째 자리 수
    *num_1 = (int)*num_1 / 10;                  // 입력된 수의 첫째 자리를 없애고 저장.   

    return first;
}

int power(int n, int i){
    int result = 1;
    for (int j = 0; j < i; j++) {result = result * n;}
    return result;
}

int decimal_m(int m, int *num){

    int num_1;
    num_1 = *num;
    int final = 0;                      // m 진수로 변환될 수
    int count;

    for (int i = 0; ; i++){
        if (num_1 < 3){
            final = final + num_1;
            break;
        }
        final = final + append_m(m, &num_1, &count) * power(10, count);
    }
    return final;
}

// 함수는 계속 나누다 몫이 0(나눌 수 없을 때)의 나머지를 반환하고 입력된 수를 몫이 0이 되기 전의 수로 만듬.
int append_m(int m, int *num_1, int *count){               // 진수 변환 하려면 m으로 계속 나눠서 나온 몫이 m보다 작을 때까지 해야됨.
    int quotient = *num_1;                                 // 몫
    int remain;                                            // 나머지

    for (int i = 0; ; i++){
        remain = quotient % m;
        quotient = (int)quotient / m;
        *count = i;                                        // num이 m 진수로 몇 자리수인지 알 수 있음
        if (quotient == 0) {break;}
    }
    *num_1 = *num_1 - remain * power(m, *count);           // num : 37 --> 37 - 27 = 10, num 수정 후 저장
    return remain;
}


/*
1 => 1(3)
1 / 3 = 0, 1 % 3 = 1

10 => 101(3)
10 / 3 = 3, 10 % 3 = 1
3 / 3 = 1, 3 % 3 = 0
1 / 3 = 0, 1 % 3 = 1    

37 => 1101(3)
37 / 3 = 12, 37 % 3 = 1
12 / 3 = 4, 12 % 3 = 0
4 / 3 = 1, 4 % 3 = 1
1 / 3 = 0, 1 % 3 = 1 ---> remain * 3^i = 27  (i = 3)        자리수 : i + 1
*/

// 아쉬운 점 : 그냥 쌩 노가다로 한 느낌이 강함. 비트 연산자를 이용해 어떻게 하는게 있을 것 같기도 하고 잘 모르겠음.
// 그리고 마지막에 어떻게 만들긴 했지만 이게 왜 되지? 하는 부분이 있음 count = i 하고 자리수 넘길 때 i + 1 자리수여야 되는게 아닌가 생각했는데 i 로 입력해야됨. 왜 그런지 모르겠음.
// + 10진법 까지만 변환 가능함. 조금 아쉬움

// 진도 : p.251