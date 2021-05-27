#include "LinkedList.h"
#include "Data.h"
struct list{
    char data[dataLen+1];
    List * next;
};
double MainLinklist(int n, char ** dataTemp, int m, char ** SearchTemp,double * creatTime,double * SearchTime){
   double time=0;
   List * begin = NULL;
   List * end = NULL;
   //begin = end;

    for(int i= 0;i<n;++i){
        *creatTime += LinklistCreat(n,dataTemp[i],&begin,end);
   }
    clock_t start, finish;
    double diff;
    start = clock();
   for(int i= 0;i<m;++i){
        *SearchTime += LinklistSearch(begin,SearchTemp[i]);
   }
    finish = clock();
    *SearchTime  = (double) (finish-start);

    time+=*creatTime;
   time+=*SearchTime;
   FreeLinklist(begin);
   return time;
}

double LinklistCreat(int n,char * str,List **begin,List * end){
    clock_t start, finish;
    double diff;
    start = clock();
    List * tempList = end;
    if(tempList != NULL){
        tempList = tempList->next;
        end->next = tempList;
    }
    tempList = malloc(sizeof(List));
    strcpy(tempList->data,str);
    tempList -> next = NULL;
    if(*begin == NULL) *begin = tempList;
    finish = clock();
    diff  = (double) (finish-start);
    return diff;
}
double LinklistSearch(List * begin,char *str){
    clock_t start, finish;
    double diff;
    start = clock();

    while (begin!= NULL){
        printf("%s",begin->data);
        if(strcmp(begin->data,str)==0){
            finish = clock();
            diff  = (double) (finish-start);
            return diff;
        }
        else
            begin = begin->next;
    }

    finish = clock();
    diff  = (double) (finish-start);
    return diff;
}

void FreeLinklist(List * begin){
    while(begin != NULL){
        List * tempList = begin;
        begin = begin->next;
        free(tempList);
    }
}
