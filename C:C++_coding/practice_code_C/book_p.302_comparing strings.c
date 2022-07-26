#include <stdio.h>

int count(char *str1);
int compare(char *str_1, char *str_2, int num_a, int num_b, char *result);      // 틀린 글자의 개수를 반환하는 함수. 두 글자수가 다르면?

int main() {
    printf("\ncode_start\n\n\n");

    int num_a, num_b;
    char str_1[16];
    char str_2[16];
    char result[16];
    int num = 0;

    for (int i = 0; i < 16; i++){
        str_1[i] = NULL;
        str_2[i] = NULL;
    }

    printf("비교할 두 문자열을 입력하세요 (단, 15글자 이내의 문자열)\n");
    scanf("%s %s", str_1, str_2);

    num_a = count(&str_1[0]);
    num_b = count(&str_2[0]);

    for (int i = 0; i < 16; i++) result[i] = NULL;

    num = compare(&str_1, &str_2, num_a, num_b, &result);

    printf("\n두 문자열에서 다른 글자 수 : %d\n", num);
    printf("\n다른 글자열 비교\n\n");

    int value = 0;
    printf("str_1 : ");
    for (int i = 0; i < 16; i++){
        if (result[i] == '1'){
            if(str_1[i] == NULL) printf("a[%d] --> '/0' ", i);
            else printf("a[%d] -->  %c   ", i, str_1[i]);
            value = 1;
        }
    }
    if (value == 0) printf("There's no difference between two strings.\n");
    printf("\nstr_2 : ");
    for (int i = 0; i < 16; i++){
        if (result[i] == '1'){
            if(str_2[i] == NULL) printf("b[%d] --> '/0' ", i);
            else printf("b[%d] -->  %c   ", i, str_2[i]);
        }
    }
    if (value == 0) printf("There's no difference between two strings.\n");
    
    printf("\n\n\ncode_end\n");
    return 0;
}

int count (char *str1){
    int count = 0;
    for (int i = 0; ; i++){
        if (*str1 == NULL) break;
        str1++;
        count++;
    }
    return count;
}

int compare (char *str_1, char *str_2, int num_a, int num_b, char *result){
    int count = 0;
    int loop = num_b;
    if (num_a >= num_b) loop = num_a;

    for (int i = 0; i < loop; i++){
        if (*str_1 != *str_2){
            count++;
            *result = '1';
        }
        str_1++;
        str_2++;
        result++;
    }

    return count;
}

// 아쉬운 점 : result 배열을 2차원 배열로 해서 result[0]은 a, [1]은 b로 해서 편하게 하고싶었는데 어떻게 선언, 함수에 넣어야 되는지 잘 모르겠음.
// 또 처음에 15글자 처럼 미리 설정을 할 수 밖에 없는게 아쉬움.

// 진도 : p.302