#include "BinarySearchTree.h"
#include "Data.h"

typedef struct node Node;
typedef struct tree Tree;

struct node {
    char data[parmCount+1];
    Node *left;
    Node *right;
};


double MainBinarySearchTree( int n, char ** dataTemp, int m, char ** SearchTemp,double * creatTime,double * SearchTime){
    double time=0;
    Node * root=NULL;
    for(int i=0;i<n;++n){
    	*creatTime +=	BinarySearchTreeCreat(&root,dataTemp[i]);
    }
    for(int i=0;i<m;++m){
        *SearchTime += SearchBinarySearchTree(root,SearchTemp[i]);
    }
    //BinarySearchTreeFree(root);
    time+=*creatTime;
    time+=*SearchTime;
    FreeBinarySearchTree(root);
    return time;
}

double SearchBinarySearchTree(Node * T, char * str) {
	clock_t start, finish;
    double diff;
    start = clock();
    if (T==NULL) { // 查找不成功
    	finish = clock();
    	diff  = (double)(finish-start);
    	return diff; 
    } else if (strcmp(str,T->data)==0) 	{ // 查找成功
       finish = clock();
    	diff  = (double) (finish-start);
    	return diff; 
    } else if (strcmp(str,T->data)<0) // 在左子樹中繼續查找
        return SearchBinarySearchTree(T->left,str);
    else // 在右子樹中繼續查找
    {
        return SearchBinarySearchTree(T->right, str);
}
	finish = clock();
    diff  = (double) (finish-start);
    return diff;
}

Node *NewNode(char *str){
    Node *tempNode=malloc(sizeof(Node));
    tempNode->left=NULL;
    tempNode->right=NULL;
    strcpy(tempNode->data,str);
    return tempNode;
}

double BinarySearchTreeCreat(Node **root,char *str){
    clock_t start, finish;
    double diff;
    start = clock();
    Node **ptr=root;
    Node *t;
    while((t=*ptr)!=NULL){
        if(strcmp(str,t->data)>=0){
            ptr=&t->right;
        }else if(strcmp(str,t->data)<0){
            ptr=&t->left;
        }
    }
    *ptr=NewNode(str);
    finish = clock();
    diff  = (double) (finish-start);
    return diff;
}

void FreeBinarySearchTree(Node *root){
    if(root==NULL) return;
    FreeBinarySearchTree(root->left);
    free(root);
    FreeBinarySearchTree(root->right);
}
