#ifndef DATASTRUCTURECOMPARE_ARRAY_H
#define DATASTRUCTURECOMPARE_ARRAY_H
double MainArray( int n, char ** dataTemp, int m, char ** SearchTemp,double * creatTime,double * SearchTime);
double ArrayDataCreat( int n, char ** dataTemp,char ** ArrayData);
double ArrayDataSearch( int n,char ** ArrayData,int m, char ** SearchTemp);
void ArrayFree( int n,char ** ArrayData);
#endif //DATASTRUCTURECOMPARE_ARRAY_H
