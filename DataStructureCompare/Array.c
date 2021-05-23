#include "Array.h"
#include "Data.h"

double MainArray( int n, char ** dataTemp, int m, char ** SearchTemp,double * creatTime,double * SearchTime){
    double time=0;
    char ** ArrayData = malloc(sizeof(char * ) *n);
    *creatTime = ArrayDataCreat(n,dataTemp,ArrayData);
    *SearchTime = ArrayDataSearch(n,ArrayData,m,SearchTemp);
    time+=*creatTime;
    time+=*SearchTime;
    ArrayFree(n,ArrayData);
    return time;
}

void ArrayFree( int n,char ** ArrayData){
    for (int i = 0; i < n; ++i) {
        free(ArrayData[i]);
    }
    free(ArrayData);
}

double ArrayDataCreat( int n, char ** dataTemp,char ** ArrayData){
    clock_t start, finish;
    double diff;
    start = clock();
    for (int i = 0; i < n; ++i) {
        ArrayData[i] =  malloc(sizeof(char ) * dataLen+1);
    }
    for (int i = 0; i < n; ++i) {
        strcpy(ArrayData[i],dataTemp[i]);
    }
    finish = clock();
    diff  = (double) (finish-start);
    printf("%lf\n",diff);
    return diff;
}


double ArrayDataSearch( int n,char ** ArrayData,int m, char ** SearchTemp){
    clock_t start, finish;
    double diff;
    start = clock();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(strcmp(SearchTemp[i],ArrayData[j]) == 0)
                break;
        }
    }
    finish = clock();
    diff  = (double) (finish-start);
    printf("%lf\n",diff);
    return diff;
}


