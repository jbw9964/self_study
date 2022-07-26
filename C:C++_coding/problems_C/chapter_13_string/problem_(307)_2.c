#include <stdio.h>

// 문제 2 (p.307) : 소문자는 대문자로, 대문자는 소문자로 바꾸는 함수 만들기
// ASCII --> A : 65, a : 97 // B : 66, b : 98
// 대문자, 소문자는 32만큼 차이남.
// 대문자 A ~ Z : [65 ~ 90], 소문자 a ~ z : [97 ~ 122]

int convert(char *arr);

int main() {
    printf("\ncode_start\n\n\n");

    char arr[100];
    
    for (int i = 0; i < 100; i++) arr[i] = NULL;

    printf("문자열 입력 : ");
    scanf("%s", arr);

    printf("\n입력한 문자열 : %s\n", arr);
    printf("\n");

    convert(arr);

    printf("\n출력된 문자열 : %s\n", arr);
    
    printf("\n\n\ncode_end\n");
    return 0;
}

int convert(char *arr){
    for (int i = 0; ; i++){
        if (*arr == NULL) break;
        if (*arr >= 65 && *arr <= 90){
            *arr = *arr +32;
            arr++;
        }   else if (*arr >= 97 && *arr <= 122){
            *arr = *arr - 32;
            arr++;
        }   else {
            printf("You put wrong strings : %c\n", *arr);
            arr++;
        }
    }
    return 0;
}

// 이해 안되는 점 : C에서 elif라 쓰면 애가 못읽나? 전혀 다른게 없는데 이상한 오류가 떴어서 똑같은 내용 다시썼음.
// 그리고 else, else if 뒤에 쓸 내용 그냥 그 줄에 쓰면 뭔가 오류 뜰수도 있나? 실제로 진행해보니 읽지 말아야 되는데 읽는 상황이 나타나기도 함.
// Ex : else printf(""); arr++; 여기에서 읽지 말아야 되는데 읽었었음.

// 진도 : p.307