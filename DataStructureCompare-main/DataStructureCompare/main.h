#ifndef DATASTRUCTURECOMPARE_MAIN_H
#define DATASTRUCTURECOMPARE_MAIN_H

#define parmCount 7

void init(int ,char **);
double creatData(char ** );
void SWAP(char ** ,int ,int );
double creatSearch(char ** );
void WriteToFile(char ** , char * , int);
void runStructure(char ** ,char **);
void printTime();
void freeAll(char ** ,char ** );
#endif //DATASTRUCTURECOMPARE_MAIN_H
