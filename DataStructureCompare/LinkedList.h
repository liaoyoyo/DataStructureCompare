#ifndef DATASTRUCTURECOMPARE_LINKEDLIST_H
#define DATASTRUCTURECOMPARE_LINKEDLIST_H
typedef struct list List;

double MainLinklist(int n, char ** dataTemp, int m, char ** SearchTemp,double * creatTime,double * SearchTime);
double LinklistCreat(int n,char * str,List * begin,List * end);
double LinklistSearch(List * begin,char *str);
void FreeLinklist(List * begin);


#endif //DATASTRUCTURECOMPARE_LINKEDLIST_H
