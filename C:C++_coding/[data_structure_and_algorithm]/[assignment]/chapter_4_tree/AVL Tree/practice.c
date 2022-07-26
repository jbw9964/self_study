#include <stdio.h>
#include <stdlib.h>

// 4.21 4.25 4.26 풀이

#include "AVL_tree.h"
#include "AVL_tree.c"

int main(){
    printf("\ncode_start\n\n\n");

    AVLTree temp = Create(2);
    temp = Insert(1,temp);
    temp = Insert(4,temp);
    temp = Insert(5,temp);
    temp = Insert(9,temp);
    temp = Insert(3,temp);
    temp = Insert(6,temp);
    temp = Insert(7,temp);

    PrintByLevel(temp);

    printf("\n\ncode_end\n\n");
    return 0;
}