#include <stdio.h>
#include <stdlib.h>

#include "Heap.h"
#include "Heap.c"

typedef int ElementType;

/* 문제 6.17(a) : 완전한 두 이진 힙을 병합하는 알고리즘. 이 때, 두 이진 힙의 Node 개수는 같다 가정
--> 이 때 각 힙의 Node 개수를 a, b 라 했을 때, N = a + b 이고 O(logN) 인 알고리즘 생성하기.

어려울 것 없음. 두 이진 힙이 "완전한 이진 힙", 정렬(?) 되있음을 기억.
두 이진힙이 SubTree 인 BinaryTree 생각. root Node 값은 negative infinite.
이 때, DeleteMin 하면 됨.
--> DeleteMin 함으로써 정렬되어야 하는데, "완전한 이진 힙" 이기 때문에 한쪽만 정리하면 됨. 즉, 다른 한쪽의 SubTree 는 건들여지지도 않고
건들여지는 한쪽 Tree 도 Shifting down 연산으로 그렇게 많이 안바꿈.

*/

int main(){
    printf("\ncode_start\n\n");

    Heap temp_1 = CreateHeap(100);

    Insert(1, temp_1);
    Insert(3, temp_1);
    Insert(5, temp_1);
    Insert(7, temp_1);
    Insert(9, temp_1);
    Insert(11, temp_1);
    Insert(13, temp_1);

    IncreaseKey(1, 5 + 2, temp_1);
    PrintHeap(temp_1);

    DecreaseKey(5, 8, temp_1);
    PrintHeap(temp_1);
    

    printf("\ncode_end\n\n");
    return 0;
}

