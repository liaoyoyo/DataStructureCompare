#include "LinkedList.h"
#include "Data.h"
struct list{
    char data[dataLen+1];
    List * next;
};
double MainLinklist(int n, char ** dataTemp, int m, char ** SearchTemp,double * creatTime,double * SearchTime){
   double time=0;
    List * begin=NULL;
     List *  end=NULL;
    clock_t start, finish;
    start = clock();
    for(int i= 0;i<n;++i){

        List* t = malloc(sizeof(List));
        strcpy(t->data,dataTemp[i]);
        t -> next = NULL;
        if(end){
            end -> next = t;
        }
        end = t;
        if(!begin){
            begin = t;
        }
        //printf("%s",end->data);
    }
    finish = clock();
    *creatTime  = (double) (finish-start);

    for(int i= 0;i<m;++i){
        *SearchTime += LinklistSearch(&begin,SearchTemp[i]);
    }

    time+=*creatTime;
   time+=*SearchTime;
   FreeLinklist(begin);
   return time;
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
