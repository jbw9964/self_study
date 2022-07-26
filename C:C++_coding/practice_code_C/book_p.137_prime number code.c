#include <stdio.h>

int main() {
    printf("\ncode_start\n\n\n");

    // arr를 이용해 소수 찾기

    int num;
    printf("3 이상의 숫자를 입력하시오\n");
    printf("어느 범위까지 찾을까요 : ");
    scanf("%d", &num);
    printf("\n");

    int arr[num];
    for (int a = 0; a <= num; a++){ // arr[0] = 2
        arr[a] = 2;
    }
    int count = 0;
    int prime = 1; // true : 1, false : 0
    
    // i : 지금 소수인지 확인하는 숫자
    // j : n번째 배열의 값 arr[j-1]

    printf("The prime number between 3 and %d are 2", num);
    
    
    for (int i = 3; i <= num; i++){
        for (int j = 0; j <= num; j++){
            if (i % arr[j] == 0){
                prime = 0;
                break;
            }
        }
        if (prime == 0){
            prime = 1;
            continue;
        } else{
            count++;
            arr[count] = i;
            printf(", %2d", arr[count]);
        }
    }

    for (int b = count + 1; b <= num; b++){
        arr[b] = 0;
    }

    printf("\n\nThe number of the prime numbers between 3 and %d are %d", num, count + 1);



    printf("\n\n\ncode_end\n");
    return 0;
}