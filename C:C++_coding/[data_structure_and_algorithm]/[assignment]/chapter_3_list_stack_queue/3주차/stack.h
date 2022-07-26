/*
This is stac.h
Linked list Node, Stack
*/

#ifndef _Stack_and_Linked_List_
#define _Stack_and_Linked_List_
#include <stdbool.h>

struct Node{
    int value;
    struct Node *next;
};

struct Stack{
    int capacity;
    struct Node *list;
};

typedef struct Stack *Stack_pointer;
typedef struct Node *Node_pointer;

Stack_pointer CreateStack(int max_capacity);    // 생성자
void DisposeStack(Stack_pointer S);             // Stack 내 Node 들을 free 시키고 Stack 자체도 free 시킴
void Push(int input, Stack_pointer S);          // top 에 input 값을 같는 Node 넣기
void Pop(Stack_pointer S);                      // top 에 있는 Node free
void MakeEmpty(Stack_pointer S);                // Stack 내 Node 들을 free 시키지만 Stack 자체는 free 안시킴.
int Top(Stack_pointer S);                       // top 에 있는 Node 의 value 값을 리턴함.

// 만들었지만 별로 필요 없음
bool IsEmpty(Stack_pointer S);                  // Stack 이 비어있다면 true 리턴
bool IsFull(Stack_pointer S);                   // Stack 이 꽉 차있다면 true 리턴
#endif