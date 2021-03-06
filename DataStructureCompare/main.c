#include "main.h"
#include "Data.h"
#include "Array.h"
#include "ArrayWithBinarySearch.h"
#include "BinarySearchTree.h"
#include "LinkedList.h"
#include "Hash.h"

int n=0,m=0;
const char parm[parmCount][6] = {"-d","-q","-bst","-bs","-arr","-ll","-hash"};
double parmTag [parmCount-2][3] = {
    // use 0/1, building time: XXXX.XX sec, query time: XXXX.XX sec
    {0,0,0},
    {0,0,0},
    {0,0,0},
    {0,0,0},
    {0,0,0}
};
int main(int argc,char ** argv) {
    init(argc,argv);
    char ** dataTemp= malloc(sizeof(char * )*n);
    char ** SearchTemp= malloc(sizeof(char * )*m);
    creatData(dataTemp);
    creatSearch(SearchTemp);
    runStructure(dataTemp,SearchTemp);
    printTime();
    freeAll(dataTemp,SearchTemp);
    return 0;
}

void freeAll(char ** dataTemp,char ** SearchTemp){
    for (int i = 0; i < n; ++i) {
        free(dataTemp[i]);
    }
    for (int i = 0; i < m; ++i) {
        free(SearchTemp[i]);
    }
    free(dataTemp);
    free(SearchTemp);
}

void init(int argc,char ** argv){
    for (int i = 1; i < argc; ++i) {
        if(argv[i][0] == '-' && argv[i][1] != '\0' ){
            int j= 0;
            for (; j < parmCount; ++j) {
                if(strcmp(argv[i],parm[j]) == 0) {
                    if(j == 0 && i+1 < argc){
                        if(!sscanf(argv[i+1],"%d",&n))fprintf(stderr,"%s is not -d command",argv[i+1]);
                        i++;
                    }else if(j == 1  && i+1 < argc){
                        if(!sscanf(argv[i+1],"%d",&m))fprintf(stderr,"%s is not -q command",argv[i+1]);
                        i++;
                    }else if (j > 1 && j < parmCount){
                        parmTag[j-2][0]=1;
                    }else{
                        fprintf(stderr,"%s format is error",argv[i]);;
                    }
                    break;
                }
            }
            if( j >= parmCount){
                fprintf(stderr,"'%s' is not command",argv[i+1]);
            }
        }
    }
};

void runStructure(char ** dataTemp,char ** SearchTemp){
    int printRound = parmCount-2 ;
    for (int i = 0; i < printRound; ++i) {
        if(parmTag[i][0] !=0 ){
            switch (i) {
                case 0:
                    MainBinarySearchTree(n,dataTemp,m,SearchTemp,&parmTag[i][1],&parmTag[i][2]);
                    break;
                case 1:
                    MainWithBinarySearch(n,dataTemp,m,SearchTemp,&parmTag[i][1],&parmTag[i][2]);
                    break;
                case 2:
                    MainArray(n,dataTemp,m,SearchTemp,&parmTag[i][1],&parmTag[i][2]);
                    break;
                case 3:
                    MainLinklist(n,dataTemp,m,SearchTemp,&parmTag[i][1],&parmTag[i][2]);
                    break;
                case 4:
                    MainHash(n,dataTemp,m,SearchTemp,&parmTag[i][1],&parmTag[i][2]);
                    break;
            }
        }
    }
}

void printTime(){
    int printRound = parmCount-2 ;
    for (int i = 0; i < printRound; ++i) {
        if(parmTag[i][0]!=0){
            printf("%s:\n",&parm[i+2][1]);
            printf("building time: %g sec\n",parmTag[i][1]/1000);
            printf("query time: %g sec\n",parmTag[i][2]/1000);
            printf("\n");
        }
    }
}

double creatData(char ** dataTemp){
    clock_t start, finish;
    double diff;
    start = clock();
    srand(srandCount);
    char format[10];
    sprintf(format,"%%%dd\n",dataLen);
    for (int i = 0; i < n; ++i) {
        dataTemp[i] = malloc(sizeof(char)*dataLen+1);
        sprintf(dataTemp[i],format,i);
    }
    /*for (int i = 0; i < n; ++i) {
        printf("%s",dataTemp[i]);
    }*/
    for (int i = 0; i < n-1; ++i) {
        int x=(int)round((long long)n * (long long)rand()/ (long long)(RAND_MAX + 1.0));
        SWAP(dataTemp,x,n-1-i);
    }
    /*for (int i = 0; i < n; ++i) {
        printf("%s",dataTemp[i]);
    }*/
    //ArrayWriteToFile(dataTemp,"./IntData.txt",n);
    finish = clock();
    diff  = (double) (finish-start);
    return diff;
}

void SWAP(char ** strArray,int n1,int n2){
    char * temp = malloc(sizeof(char)*dataLen+1);
    strcpy(temp,strArray[n1]);
    strcpy(strArray[n1],strArray[n2]);
    strcpy(strArray[n2],temp);
    free(temp);
}

double creatSearch(char ** SearchTemp){
    clock_t start, finish;
    double diff;
    start = clock();
    srand( srandCount );
    for (int i = 0; i < m; ++i) {
        SearchTemp[i] = malloc(sizeof(char)*dataLen+1);
        for (int j = 0; j < dataLen; ++j) {
            SearchTemp[i][j] = (char)('0'+(rand()%10));
        }
        SearchTemp[i][dataLen]='\n';
    }
    /*for (int i = 0; i < n; ++i) {
    printf("%s",SearchTemp[i]);
    }*/
    //ArrayWriteToFile(dataTemp,"./IntSearch.txt",m);
    finish = clock();
    diff  = (double) (finish-start);
    return diff;
}

void WriteToFile(char ** dataTemp , char * path, int n){
    FILE * setIntData;
    setIntData = fopen(path,"w");
    for (int i = 0; i < n; ++i) {
        fprintf(setIntData,"%s",dataTemp[i]);
    }
    fclose(setIntData);
}
