#ifndef DATASTRUCTURECOMPARE_LINKEDLIST_H
#define DATASTRUCTURECOMPARE_LINKEDLIST_H

double MainLinklist(int n, char ** dataTemp, int m, char ** SearchTemp,double * creatTime,double * SearchTime);
double LinklistCreat(int n,char * str,List * begin,List * end);
double LinklistSearch(List * begin,char *str);
void FreeLinklist(List * begin);
typedef struct list List;

struct list{
    char data[parmCount+1];
    List * next;
};
#endif //DATASTRUCTURECOMPARE_LINKEDLIST_H
