#ifndef DATASTRUCTURECOMPARE_LINKEDLIST_H
#define DATASTRUCTURECOMPARE_LINKEDLIST_H
#include "Data.h"
typedef struct list List;

double MainLinklist(int n, char ** dataTemp, int m, char ** SearchTemp,double * creatTime,double * SearchTime);
double LinklistCreat(int n,char * str,List * begin,List * end);
double LinklistSearch(List * begin,char *str);
void FreeLinklist(List * begin);

struct list{
    char data[dataLen+1];
    List * next;
};
#endif //DATASTRUCTURECOMPARE_LINKEDLIST_H
