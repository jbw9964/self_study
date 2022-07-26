#include <stdio.h>

// 문제 4 (p.307) : 문자열 두개 입력 받고 먼저 입력받은 문자열에서 나중에 입력받은 문자열의 위치를 검색하는 함수 만들기
// I_am_a_boy, am 입력 --> 첫번째에서 am 위치 찾음. am 위치는 [2] 니까 2 리턴. 만약 찾는 문자열 없으면 -1 리턴


int search_1(char *arr_1, char *arr_2, int *result_arr);     // 두 배열에서 처음으로 같은게 나온걸 검색하는 함수
int search_2(char *arr_1, char *arr_2, int *count, int *result);     // 처음 나온 후 그 뒤로도 같은지 확인하는 함수

int main() {
    printf("\ncode_start\n\n\n");

    char arr_1[100], arr_2[100];
    int result_arr[100];
    for (int i = 0; i < 100; i++){
        arr_1[i] = NULL;
        arr_2[i] = NULL;
        result_arr[i] = 0;
    }

    printf("첫번째 문자열 입력 : ");
    scanf("%s", arr_1);

    printf("검색할 문자열 : ");
    scanf("%s", arr_2);
    printf("\n\n\n");

    printf("원문 내용 : %s\n", arr_1);
    printf("검색할 문자열 : %s\n\n\n", arr_2);

    int result = search_1(arr_1, arr_2, result_arr);
    int i = 0;

    if (result != -1){
        printf("result : ");
        while (result_arr[i] != 0){
            printf("%d, ", result_arr[i]);
            i++;
        }
        printf("\n");
        i = 0;
        printf("문자열이 위치한 자리 : ");
        while (result_arr[i] != 0){
            printf("%d, ", result_arr[i]);
            i++;
        }
    }   else{
        printf("result : %d\n", result);
        printf("검색한 문자열이 존재하지 않습니다.\n");
    }
    
    printf("\n\n\ncode_end\n");
    return 0;
}

int search_1(char *arr_1, char *arr_2, int *result_arr){
    int count = 0;
    int num = 0;
    int final = -1;

    while (*arr_1){
        int result = 0;
        if (*arr_1 == *arr_2){
            search_2(arr_1, arr_2, &count, &result);
        }
        if (result == 1){
            result_arr[num] = count;
            num++;
            final = count;
        }
        arr_1++;
        count++;
    }

    return final;
}

int search_2(char *arr_1, char *arr_2, int *count, int *result){     // result : 0 --> 거짓, 1 --> 참
    *result = 1;
    while (*arr_2){
        if (*arr_1 != *arr_2){
            *result = 0;
            break;
        }
        arr_1++;
        arr_2++;
    }
    return 0;
}

// 아쉬운 점 : 만들긴 했는데 뭔가 쓸데없이 복잡하게 만든 느낌. 좀더 간결하게 만들으면 좋겠음.

// 진도 : p.307