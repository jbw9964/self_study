#include <stdio.h>

// 문제 1 (p.307) : 길이가 최대 100인 문자열을 하나 만들어 입력한 것의 역순으로 출력하기

int reverse(char *arr, char *result);

int main() {
    printf("\ncode_start\n\n\n");

    char arr[100];
    char result[100];
    for (int i = 0; i < 100; i++){
        arr[i] = NULL;
        result[i] = NULL;
    }

    printf("문자열 입력 : ");
    scanf("%s", arr);

    printf("\n입력한 문자열 : %s\n", arr);

    reverse(arr, result);

    printf("\n출력된 문자열 : %s\n", arr);
    
    printf("\n\n\ncode_end\n");
    return 0;
}

int reverse(char *arr, char *result){
    int count = 0;
    for (int i = 0; ; i++){
        if (arr[i] == NULL) break;
        result[i] = arr[i];
        count++;
    }
    for (int i = 0; i < count; i++){
        if (result[i] == NULL) break;
        arr[i] = result[count - 1 - i];
    }
    return 0;
}

// 진도 : p.307