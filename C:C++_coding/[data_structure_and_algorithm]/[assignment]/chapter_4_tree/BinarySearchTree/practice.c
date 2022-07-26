#include <stdio.h>
#include <stdlib.h>

// 4.37, 4.40 풀이 : PrintBetween, PrintByLevel(+que)

#include "tree.h"
#include "tree.c"

int main(){
    printf("\ncode_start\n\n\n");

    Tree temp = Create(3);
    temp = Insert(1, temp);
    temp = Insert(4, temp);
    temp = Insert(6, temp);
    temp = Insert(9, temp);
    temp = Insert(2, temp);
    temp = Insert(5, temp);
    temp = Insert(7, temp);

    PrintByLevel(temp);
    printf("Print result between 0 and 5 : ");
    PrintBetween(0, 5, temp);
    

    printf("\n\ncode_end\n\n");
    return 0;
}