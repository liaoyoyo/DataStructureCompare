#ifndef DATASTRUCTURECOMPARE_BINARYSEARCHTREE_H
#define DATASTRUCTURECOMPARE_BINARYSEARCHTREE_H

double MainBinarySearchTree( int n, char ** dataTemp, int m, char ** SearchTemp,double * creatTime,double * SearchTime);
double BinarySearchTreeCreat(Node **root,char *str);
double SearchBinarySearchTree(Node * T, char * str);
Node *NewNode(char *str);
void FreeBinarySearchTree(Node *root);

typedef struct node Node;
typedef struct tree Tree;

struct node {
    char data[parmCount+1];
    Node *left;
    Node *right;
};
#endif //DATASTRUCTURECOMPARE_BINARYSEARCHTREE_H
