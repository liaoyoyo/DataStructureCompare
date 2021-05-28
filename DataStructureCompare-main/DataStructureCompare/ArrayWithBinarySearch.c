#include "ArrayWithBinarySearch.h"
#include "Data.h"
#include "Array.h"

double MainWithBinarySearch( int n, char ** dataTemp, int m, char ** SearchTemp,double * creatTime,double * SearchTime){
    double time=0;
    char ** ArrayData = malloc(sizeof(char * ) *n);
    *creatTime = ArrayDataCreat(n,dataTemp,ArrayData);
    *creatTime += ArrayWithBinarySearchSort(n,ArrayData);
    *SearchTime = ArrayWithBinarySearchDataSearch(n,ArrayData,m,SearchTemp);
    time+=*creatTime;
    time+=*SearchTime;
    ArrayFree(n,ArrayData);
    return time;
}

double ArrayWithBinarySearchDataSearch( int n,char ** ArrayData,int m, char ** SearchTemp){
    clock_t start, finish;
    double diff;
    start = clock();
    for (int i = 0; i < m; ++i) {
        binary_search(ArrayData,0,n,SearchTemp[i]);
    }
    finish = clock();
    diff  = (double) (finish-start);
    return diff;
}

double ArrayWithBinarySearchSort(int n,char ** ArrayData){
    clock_t start, finish;
    double diff;
    start = clock();
    qsort(ArrayData,n,sizeof(ArrayData[0]),compare);
    finish = clock();
    diff  = (double) (finish-start);
    return diff;
}

int compare( const void *a, const void *b)
{
    return( strcmp((char *)a,(char *)b) );
}

void binary_search(char ** arr, int start, int end, char * key) {
    if (start > end)
        return ;  //with finded

    int mid = start + (end - start) / 2;
    if (strcmp(key,arr[mid]) > 0 )
        return binary_search(arr, start, mid - 1, key);
    else if (strcmp(key,arr[mid]) < 0)
        return binary_search(arr, mid + 1, end, key);
    else
        return ; //with finded
}


