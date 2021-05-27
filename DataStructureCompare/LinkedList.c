#include "LinkedList.h"
#include "Data.h"
struct list{
    char data[dataLen+1];
    List * next;
};
double MainLinklist(int n, char ** dataTemp, int m, char ** SearchTemp,double * creatTime,double * SearchTime){
   double time=0;
   List * begin = NULL;
   List *  end=NULL;

    for(int i= 0;i<n;++i){
        *creatTime += LinklistCreat(dataTemp[i],&begin);

    }
    clock_t start, finish;
    double diff;
    start = clock();

    for(int i= 0;i<m;++i){
        *SearchTime += LinklistSearch(&begin,SearchTemp[i]);
   }
    finish = clock();
    *SearchTime  = (double) (finish-start);
    printf("3l");

    time+=*creatTime;
   time+=*SearchTime;
   FreeLinklist(begin);
   return time;
}

double LinklistCreat(char * str,List ** begin){
    clock_t start, finish;
    double diff;
    start = clock();
    List ** tempList = begin;
    List * t;
    while(t=*tempList){
        if(strcmp(t->data,str)==0){
            finish = clock();
            diff  = (double) (finish-start);
            return diff;
        }
        tempList=&t->next;
    }
    *tempList = malloc(sizeof(List));
    strcpy((*tempList)->data,str);
    (*tempList) -> next = NULL;
    finish = clock();
    diff  = (double) (finish-start);
    return diff;
}

double LinklistSearch( List ** begin,char *str){
    clock_t start, finish;
    double diff;
    start = clock();
    List ** t = begin;
    List *s;
    while (s=*t){
        if(strcmp(s->data,str)==0){
            finish = clock();
            diff  = (double) (finish-start);
            return diff;
        }

          t   = &s->next;
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
