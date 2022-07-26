/*
This is stack.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

Stack_pointer CreateStack(int max_capacity){    // 생성자

    Stack_pointer stack;
    stack = (Stack_pointer)malloc(sizeof(struct Stack));

    stack->capacity = max_capacity;
    stack->list = (struct Node*)malloc(sizeof(struct Node));
    stack->list = NULL;

    return stack;
}
void DisposeStack(Stack_pointer S){             // Stack 내 Node 들을 free 시키고 Stack 자체도 free 시킴

    if (!S->list) {free(S); return;}

    Node_pointer temp_1 = S->list;
    
    Node_pointer temp_2 = temp_1->next;

    while (temp_2){
        free(temp_1);
        temp_1 = temp_2;
        temp_2 = temp_2->next;
    }

    free(temp_1);
    free(S);

    return;
}
void Push(int input, Stack_pointer S){          // top 에 input 값을 같는 Node 넣기
    
    if (!S->list){
        Node_pointer temp_node = S->list;
        temp_node = (Node_pointer)malloc(sizeof(Node_pointer));
        temp_node->value = input;
        temp_node->next = NULL;
        S->list = temp_node;

        return;
    }

    Node_pointer temp_node = (Node_pointer)malloc(sizeof(Node_pointer));
    temp_node->value = input;
    temp_node->next = S->list;
    S->list = temp_node;
}
void Pop(Stack_pointer S){                      // top 에 있는 Node free
    if (!S->list){
        printf("This is empty Stack.\n");
    }   else{
        Node_pointer temp = S->list;
        S->list = temp->next;
        free(temp);
    }
}
void MakeEmpty(Stack_pointer S){                // Stack 내 Node 들을 free 시키지만 Stack 자체는 free 안시킴.
    if (!S->list) {printf("This is empty Stack.\n"); return;}
    while (S->list){
        Pop(S);
    }
    S->list = NULL;
}
int Top(Stack_pointer S){                       // top 에 있는 Node 의 value 값을 리턴함.
    if (!S->list){
        printf("This is empty Stack.\n");
        return 0;
    }
    return S->list->value;
}

// 만들었지만 별로 필요 없음.
bool IsEmpty(Stack_pointer S){
    if (!S->list) {return true;}
    return false;
}
bool IsFull(Stack_pointer S){
    int count = 0;
    Node_pointer temp = S->list;
    while (temp){
        count++;
        temp = temp->next;
    }

    if (count == S->capacity){return true;}
    return false;
}