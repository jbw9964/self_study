#include <stdio.h>

int add(char *str1, char *str2, int num);
int count(char *str1);

int main() {
    printf("\ncode_start\n\n\n");

    char str1[100] = "hello my name is ";
    char str2[] = "Psi";
    int num;

    printf("합치기 이전 : %s\n", str1);
    printf("\n");

    num = count(str1);
    add(str1, str2, num);

    printf("합치기 이후 : %s\n", str1);

    printf("\n\n\ncode_end\n");
    return 0;
}

int add(char *str1, char *str2, int num){
    int count = 0;
    for (int i = num; ; i++){
        if (str2[count] == NULL) break;
        str1[i] = str2[count];
        count++;
    }
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

// 진도 : p.302