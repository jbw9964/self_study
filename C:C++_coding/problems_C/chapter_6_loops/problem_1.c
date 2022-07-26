#include <stdio.h>


int main () {
    printf("code_start\n\n\n");

    
    
    /* N줄인 삼각형 만들기 :예시 : 3줄

          *         *****       -> collum  |
         ***         ***                   v row
        *****         *     대충 이렇게*/

//문제 1 : 첫번째 그림

    int row; 
    printf("N : ");
    scanf("%d", &row); //줄 입력

    if (row >= 25){ //너무 크면 진짜 출력할건지 물음
        printf("\nIt could be too large to print. Are you sure to print it?\n\n");
        printf("Yes : press 1\nNo : press 0\n");
        int answer;
        scanf("%d", &answer);
        if (answer == 0){
            printf("\nThe program was over.\n\n\n");
            return 0;
        }
    } 

    printf("\nThe program was excuted.");
    int collum = 2*row - 1; // 총 입력해야 되는 숫자, 3줄 : 5개

    printf("\n\n\n");
    int i = 1; // i번째 줄 --> 1, 2, 3
    int j; // j번째 문자
    for (;i <= row; i++){ //1번째 줄일때
        for (j = 1; j <= collum; j++){ // 1번째 문자부터 시작해서 collum번째 까지
            if (j > row - i && j < row + i){ //중간에 2<j<4인 j번째 줄은 *로 출력
                printf("*");  //collum번째 문자가 가운데이기 때문에 collum +- 1,2,(i)
            }   else { //j가 가운데 영역에 있지 않을 땐 공백 출력
                printf(" ");
            }
        }
        printf("\n");
    }
    



    printf("\n\n\ncode_end");
    return 0;
}

/* 아쉬운 점 : 처음 N 너무 클 때 진짜 출력할거냐고 물을 때 
그냥 키보드에 y, yes 이런거 쳐도 입력되게 하고 싶었는데 못함.
일단 문자니까 char로 해야되는 건 맞는데 그렇게 하고 scanf("%s")도 맞게 했는데
그 if 구문을 넘어가면 처음 입력했던 N(row)가 초기화됨. 왜그런지는 모르겠음.*/