#include <stdio.h>

int compare(char word_1, char word_2);

// 이해 안가는 점 : 처음 구상했던 방식은 VLA 처럼 하고 싶었음. 그래서 대충 word_1[2] 길이 대충 설정하고 scanf에서 더 넣어봄. 근데 그러니까
// word_1 값이랑 word_2 값이 서로 침범당함. 왜그런지 주소값을 나타내보니 애초에 &word_1, &word_2 가 서로 붙어있었음. word_1 바로 뒤 주소가
// word_2 였음. 왜 이렇게 되는지 궁금함, 이해안됨.
// 또 궁극적으로 처음에 문자열 수를 지정 안하고 사용자가 편하게 비교해볼 수 있는 방법이 있었으면 좋겠는데 그걸 어떻게 해야되는지 잘 모르겠음.

int main() {
    printf("\ncode_start\n\n\n");

    char word_1[10];
    char word_2[10];

    printf("비교할 두 문자열을 입력하세요 (10글자 이내) : ");
    scanf("%s", word_1);
    printf("비교할 두 문자열을 입력하세요 (10글자 이내) : ");
    scanf("%s", word_2);

    printf("\nword_1 : %s\n", word_1);
    printf("word_2 : %s\n", word_2);

    for (int i = 0; ; i++){
        if (word_1[i] == NULL || word_2[i] == NULL) break;
        if (compare(word_1[i], word_2[i]) == 0){
            printf("\nfalse\n\n\n");
            return 0;
        }
    }
    printf("\ntrue\n");


    printf("\n\n\ncode_end\n");
    return 0;
}

int compare(char word_1, char word_2){
    if (word_1 != word_2) return 0;
    else return 1;
}

// 진도 : p.279