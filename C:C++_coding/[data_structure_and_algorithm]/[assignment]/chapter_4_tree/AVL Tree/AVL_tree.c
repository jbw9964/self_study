#include <stdio.h>
#include <stdlib.h>

#include "AVL_tree.h"

AVLTree Create(int input){
    AVLTree temp = (AVLTree)malloc(sizeof(struct AVLNode));
    temp->key_value = input;
    temp->height = 0;
    temp->left = temp->right = NULL;
    return temp;
}

Position Insert(int input, AVLTree T){

    if (!T){
        AVLTree temp = (AVLTree)malloc(sizeof(struct AVLNode));
        temp->key_value = input;
        temp->height = 0;
        temp->left = temp->right = NULL;

        return temp;
    }

    if (input < T->key_value){                  // L insert
        T->left = Insert(input, T->left);

        if (Height(T->left) - Height(T->right) == 2){
            if (input < T->left->key_value){    // LL insert
                T = SingleLeft(T);
            }   else{                           // LR insert
                T = DoubleLeft(T);
            }
        }

    }   else if (input > T->key_value){         // R insert
        T->right = Insert(input, T->right);

        if (Height(T->left) - Height(T->right) == -2){
            if (input > T->right->key_value){   // RR insert
                T = SingleRight(T);
            }   else{                           // RL insert
                T = DoubleRight(T);
            }
        }
    }

    T->height = Max(Height(T->left), Height(T->right)) + 1;

    return T;
}

Position SingleLeft(AVLTree T){     // LL insert

    Position T1 = T;
    Position T2 = T->left;
    Position temp = T2->right;

    T2->right = T1;
    T1->left = temp;

    T1->height = Max(Height(T1->left), Height(T1->right)) + 1;
    T2->height = Max(Height(T2->left), Height(T2->right)) + 1;

    return T2;
}
Position SingleRight(AVLTree T){    // RR insert

    Position T1 = T;
    Position T2 = T->right;
    Position temp = T2->left;

    T2->left = T1;
    T1->right = temp;

    T1->height = Max(Height(T1->left), Height(T1->right)) + 1;
    T2->height = Max(Height(T2->left), Height(T2->right)) + 1;

    return T2;
}
Position DoubleLeft(AVLTree T){     // LR insert

    T->left = SingleRight(T->left);
    T = SingleLeft(T);

    return T;
}
Position DoubleRight(AVLTree T){    // RL insert

    T->right = SingleLeft(T->right);
    T = SingleRight(T);

    return T;
}

Position EfficientDoubleLeft(AVLTree T){   // LR insert

    Position T1 = T;
    Position T2 = T1->left;
    Position T3 = T2->right;
    Position temp_1 = T3->left;
    Position temp_2 = T3->right;

    T3->right = T1;
    T3->left = T2;
    T2->right = temp_1;
    T1->left = temp_2;

    T1->height = Max(Height(T1->left), Height(T1->right)) + 1;
    T2->height = Max(Height(T2->left), Height(T2->right)) + 1;
    T3->height = Max(Height(T3->left), Height(T3->right)) + 1;

    return T3;
}
Position EfficientDoubleRight(AVLTree T){   // RL insert

    Position T1 = T;
    Position T2 = T1->right;
    Position T3 = T2->left;
    Position temp_1 = T3->left;
    Position temp_2 = T3->right;

    T3->left = T1;
    T3->right = T2;
    T1->right = temp_1;
    T2->left = temp_2;

    T1->height = Max(Height(T1->left), Height(T1->right)) + 1;
    T2->height = Max(Height(T2->left), Height(T2->right)) + 1;
    T3->height = Max(Height(T3->left), Height(T3->right)) + 1;

    return T3;
}

int Height(AVLTree T){
    if (!T) {return -1;}
    return T->height;
}
int Max(int input_1, int input_2){
    if (input_1 >= input_2) {return input_1;}
    return input_2;
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
