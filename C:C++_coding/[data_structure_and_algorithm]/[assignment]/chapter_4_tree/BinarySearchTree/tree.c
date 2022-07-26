#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

Tree Create(int innput){
    Tree temp = (Tree)malloc(sizeof(struct Node));
    temp->key_value = innput;
    temp->right = temp->left = NULL;

    return temp;
}

Position Find(int input, Tree T){

    if (!T) {return NULL;}

    if (input < T->key_value){
        return Find(input, T->left);
        
    }   else if (input > T->key_value){
        return Find(input, T->right);

    }  else {return T;}

}
Position Insert(int input, Tree T){

    if (!T){
        Tree temp = (Tree)malloc(sizeof(struct Node));
        temp->key_value = input;
        temp->left = 0;
        temp->right = 0;

        return temp;
    }

    if (input > T->key_value){
        T->right = Insert(input, T->right);

    }   else if (input < T->key_value){
        T->left = Insert(input, T->left);

    }

    return T;
}
Position Delete(int input, Tree T){

    if (!T) {return NULL;}
    Position temp;

    if (input < T->key_value){
        T->left = Delete(input, T->left);

    }   else if (input > T->key_value){
        T->right = Delete(input, T->right);

    }   else if (T->left && T->right){
        temp = FindMin(T->right);
        T->key_value = temp->key_value;
        T->right = Delete(T->key_value, T->right);

    }   else{
        temp = T;
        if (!T->left) {T = T->right;}
        else if (!T->right) {T = T->left;}
        free(temp);
    }

    return T;
}

/*input_1 <= input_2, key_value = input 인 경우 포함*/
void PrintBetween(int input_1, int input_2, Tree T){

    if (!T) {return;}

    if (T->key_value >= input_1){
        PrintBetween(input_1, input_2, T->left);   
    }
    if (T->key_value <= input_2){
        PrintBetween(input_1, input_2, T->right);
    }

    if (input_1 <= T->key_value && input_2 >= T->key_value){
        printf("%d ", T->key_value);
    }

    return;
}
void PrintByLevel(Tree T){

    if (!T) {return;}

    que temp_que = CreateQue(T);

    int count_1 = 0;
    while (1){
        Tree array[256];

        int count_2 = 0;
        while (1){
            Tree temp = QuePop(temp_que);

            if (!temp) {break;}

            array[count_2] = temp;
            count_2++;
        }

        if (count_2 == 0) {break;}

        printf("[Level %d] : ", count_1);
        for (int i = 0; i < count_2; i++){
            printf("%d ", array[i]->key_value);
            QueInsert(array[i]->left, temp_que);
            QueInsert(array[i]->right, temp_que);
        }
        count_1++;
        printf("\n");
    }
    printf("\n");
}

que CreateQue(Tree T){

    if (!T){
        que header = (que)malloc(sizeof(struct QueForTree));
        que temp = (que)malloc(sizeof(struct QueForTree));
        temp->next = NULL;
        header->next = temp;

        return header;
    }

    que header = (que)malloc(sizeof(struct QueForTree));
    que temp = (que)malloc(sizeof(struct QueForTree));
    temp->PtrToTree = T;
    temp->next = NULL;
    header->next = temp;

    return header;
}
void QueInsert(Tree T, que Q){

    if (!T) {return;}

    if (!Q->next){
        que temp = (que)malloc(sizeof(struct QueForTree));
        temp->PtrToTree = T;
        temp->next = NULL;
        Q->next = temp;
        return;
    }
    que temp_1 = Q->next;

    while (temp_1->next){
        temp_1 = temp_1->next;
    }

    que temp = (que)malloc(sizeof(struct QueForTree));
    temp->PtrToTree = T;
    temp->next = NULL;
    temp_1->next = temp;

}
Tree QuePop(que Q){

    if (!Q->next) {return NULL;}

    que temp_1 = Q->next;
    que temp_2 = temp_1->next;

    Tree result = temp_1->PtrToTree;
    free(temp_1);
    Q->next = temp_2;

    return result;
}

Position FindMax(Tree T){

    if (!T->right) {return T;}

    return FindMax(T->right);
}
Position FindMin(Tree T){

    if (!T->left) {return T;}

    return FindMin(T->left);
}
