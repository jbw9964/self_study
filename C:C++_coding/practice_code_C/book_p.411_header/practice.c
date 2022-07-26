#include <stdio.h>
#include "human.h"

int main() {
    printf("\ncode_start\n\n");
    
    struct HUMAN Lee = create_human("Lee", 40, Male);

    print_human(&Lee);

    

    printf("\n\ncode_end\n\n");
    return 0;
}

// 내가 쓰는게 vscode 여서 그런진 모르겠는데, 책에는 str.h, str.c 두개를 만들어서 했었음. 그러니까 둘이 연결되서 잘 구동 됨.
// 근데 난 안됨. 내가 하는 방법을 모르는건지 원래 안되는 건지 아님 설정이 잘못된건지 모르겠음.
// 그래서 결국 헤더 내에서 함수 정의까지 다 씀.

// 진도 : p.376