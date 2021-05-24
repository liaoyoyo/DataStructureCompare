#include "BinarySearchTree.h"
#include "Data.h"

typedef struct node Node;
typedef struct tree Tree;

struct node {
    int data;
    Node *left;
    Node *right;
};

struct tree {
    Node *root;
};

double MainBinarySearchTree( int n, char ** dataTemp, int m, char ** SearchTemp,double * creatTime,double * SearchTime){
    double time=0;
    
    time+=*creatTime;
    time+=*SearchTime;
    return time;
}

double BinarySearchTreeCreat(struct node tree, ElemType e) {
    if (!T) {
    s = new BiTNode;
    s->data = e;
    s->lchild = s->rchild = NULL;
    T = s; // 被插節点*s为新的根结点
    } else if (e.key == T->data.key)
    return false;// 关键字等于e.key的数据元素，返回錯誤
    if (e.key < T->data.key)
    InsertBST(T->lchild, e);  // 將 e 插入左子樹
    else
    InsertBST(T->rchild, e);  // 將 e 插入右子樹
    return true;
}

double SearchBinarySearchTree(struct node T, KeyType key, BiTree f, BiTree &p) {
    if (!T) { // 查找不成功
        p = f;
    return false;
    } else if (key == T->data.key) { // 查找成功
        p = T;
        return true;
    } else if (key < T->data.key) // 在左子樹中繼續查找
        return SearchBST(T->lchild, key, T, p);
    else // 在右子樹中繼續查找
        return SearchBST(T->rchild, key, T, p);
}