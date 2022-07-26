#include <stdio.h>

/*
정수 N의 2진수 표기에서 1의 개수를 출력하는 재귀함수를 작성하라. N이 홀수일 때 N/2 에 대한 2진수 표기에서 1의 개수에 1을 더한 것과 
같다는 특징을 이용해라.
*/

int cal(int num);

int main(){
    printf("\ncode_start\n\n\n\n");

    int num;
    scanf("%d", &num);
    printf("\n");

    printf("Number of '1' : %d", cal(num));

    printf("\n\n\n\ncode_end\n\n");
    return 0;
}

int cal(int num){
    if ((num % 2) == 1){
        num /= 2;
        return cal(num) + 1;
    }   else if (num == 0) {
        return 0;
    }   else{
        num /= 2;
        return cal(num);
    }
}

/* N이 짝수일 때 (ex 6 : 110(2) / 8 : 1000(2))



*/

/* N이 홀수일 때 (ex 15 : 1111(2) / 13 : 1101(2))

계속 N/2 를 하여 짝수 또는 0일 때까지 만듬.                --> 15 / 7 / 3 / 1 / 0 (4번 나눠야 됨) : 13 / 6 (1번 나눠야 됨)
짝수 또는 0일 때의 수를 n 이라 하고 n에 대한 1의 개수 찾음     --> 0 : 0개 / 6 : 110(2) 2개
위에서 재귀된 횟수 + n의 1의 개수 리턴                    --> 15 : 4 / 13 : 3

*/
