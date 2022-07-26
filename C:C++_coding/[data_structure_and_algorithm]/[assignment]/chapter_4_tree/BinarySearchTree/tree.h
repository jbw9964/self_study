#ifndef __BinaryTree_And_Queue__
#define __BinaryTree_And_Queue__

struct Node;
typedef struct Node* Tree;
typedef Tree Position;
typedef Tree NodePtr;

struct QueForTree;
typedef struct QueForTree* que;

struct Node{
    unsigned int key_value;
    NodePtr left;
    NodePtr right;
};

struct QueForTree{
    Tree PtrToTree;
    que next;
};

Tree Create(int input);

Position Find(int input, Tree T);
Position Insert(int input, Tree T);
Position Delete(int input, Tree T);
void PrintBetween(int input_1, int input_2, Tree T);
void PrintByLevel(Tree T);

que CreateQue(Tree T);
void QueInsert(Tree T, que Q);
Tree QuePop(que Q);

Position FindMax(Tree T);
Position FindMin(Tree T);

#endif