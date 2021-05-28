#include "Hash.h"
#include "Data.h"

double MainHash(int n, char ** dataTemp, int m, char ** SearchTemp,double * creatTime,double * SearchTime){
	double time=0;
	char ** ArrayData = malloc(sizeof(char * ) *n);
	*creatTime = HashCreat(n,dataTemp,ArrayData);
	*SearchTime = HashSearch(m,SearchTemp);
	time = *creatTime + *SearchTime;
	ArrayFree(n,ArrayData);
	return time;
}

double HashCreat(int n, char ** dataTemp,char ** ArrayData){
	clock_t start, finish;
    double diff;
    start = clock();
    for(int i=0;i<n;++i){
    	ArrayData[i] = malloc(sizeof(char ) * dataLen +1);
    }
    for(int i=0;i<n;++i){
    	strcpy(ArrayData[atoi(dataTemp[i])],dataTemp[i]);
    }
    finish = clock();
    diff  = (double)(finish-start);
    return diff;
}

double HashSearch(int m, char ** SearchTemp){
    clock_t start, finish;
    double diff;
    start = clock();
    for(int i=0;i<m;++i){
        if(atoi(SearchTemp[i])<=n){ //find
        	
   		 }else{	 //not find
        	
    	}
    }
    finish = clock();
    diff  = (double) (finish-start);
    return diff;
}
