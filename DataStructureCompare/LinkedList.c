#include "LinkedList.h"
#include "Data.h"

double MainLinklist(int n, char ** dataTemp, int m, char ** SearchTemp,double * creatTime,double * SearchTime){
   double time=0;
   List * begin = NULL;
   List * end = NULL;
   //begin = end;
   for(int i= 0;i<n;++i){
        *creatTime += LinklistCreat(n,dataTemp[i],begin,end);
   }
   
   for(int i= 0;i<m;++i){
        *SearchTime += LinklistSearch(begin,SearchTemp[i]);
   }
   	
   time+=*creatTime;
   time+=*SearchTime;
   FreeLinklist(begin);
   
   return time;
}

double LinklistCreat(int n,char * str,List * begin,List * end){
   clock_t start, finish;
   double diff;
   start = clock();
   List * tempList = end;
   if(end != NULL)end = end->next;
   end = malloc(sizeof(List));
   strcpy(tempList->data,str);
   tempList->next = end;
   if(begin == NULL) begin = tempList;
   finish = clock();
   diff  = (double) (finish-start);
   return diff;
}

double LinklistSearch(List * begin,char *str){
    clock_t start, finish;
    double diff;
    start = clock();
    if(begin == NULL){
       finish = clock();
    	diff  = (double) (finish-start);
    	return diff;
    }
    else if(strcmp(begin->data,str)==0){
       finish = clock();
    	diff  = (double) (finish-start);
    	return diff;
    }
    else
    	begin = begin->next;
}

void FreeLinklist(List * begin){
    while(begin != NULL){
        List * tempList = begin;
        begin = begin->next;
        free(tempList);
    }
}
