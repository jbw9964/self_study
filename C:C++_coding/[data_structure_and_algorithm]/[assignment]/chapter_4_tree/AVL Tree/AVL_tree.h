#ifndef __AVL_Tree__
#define __AVL_Tree__

struct AVLNode;
typedef struct AVLNode* Position;
typedef struct AVLNode* AVLTree;
typedef Position Tree;


struct AVLNode{

    int key_value;
    int height;
    Position left;
    Position right;

};

AVLTree Create(int input);

Position Insert(int input, AVLTree T);

Position SingleLeft(AVLTree T);
Position SingleRight(AVLTree T);
Position DoubleLeft(AVLTree T);
Position DoubleRight(AVLTree T);

Position EfficientDoubleLeft(AVLTree T);
Position EfficientDoubleRight(AVLTree T);

int Height(AVLTree T);
int Max(int input_1, int input_2);



struct QueForTree;
typedef struct QueForTree* que;
struct QueForTree{
    Tree PtrToTree;
    que next;
};
que CreateQue(Tree T);
void QueInsert(Tree T, que Q);
Tree QuePop(que Q);
void PrintByLevel(Tree T);


#endif