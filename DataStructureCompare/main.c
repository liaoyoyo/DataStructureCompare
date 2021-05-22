#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void init(int ,char **);
void runStructure();
void creatData();

int n=0,m=0;
int dataLen=8;
const char parm[7][5] = {"-d","-q","-bst","-bs","-arr","-ll","-hash"};
int parmTag [5][3] = {
    // use 0/1, building time: xxxx sec, query time: xxxx sec
    {0,0,0},
    {0,0,0},
    {0,0,0},
    {0,0,0},
    {0,0,0}
};
int main(int argc,char ** argv) {

    init(argc,argv);
    creatData();

    runStructure();


    return 0;
}

void init(int argc,char ** argv){
    for (int i = 1; i < argc; i++) {
        if(argv[i][0] == '-' && argv[i][1] != '\0' ){
            int j= 0;
            for (; j < 7; j++) {
                if(strcmp(argv[i],parm[j]) == 0) {
                    if(j == 0 && i+1 < argc){
                        if(!sscanf_s(parm[i+1],"%g",&n))fprintf(stderr,"%s is not -d command",argv[i+1]);
                        i++;
                    }else if(j == 1  && i+1 < argc){
                        if(!sscanf_s(parm[i+1],"%g",&m))fprintf(stderr,"%s is not -q command",argv[i+1]);
                        i++;
                    }else if (j > 1 && j < 7){
                        parmTag[j-2][0]=1;
                    }else{
                        fprintf(stderr,"%s format is error",argv[i]);;
                    }
                    break;
                }
            }
            if( j >= 7){
                fprintf(stderr,"'%s' is not command",argv[i+1]);
            }
        }
    }
};

void creatData(){
    char ** dataTemp= malloc(sizeof(char * )*n);
    srand( time(NULL) );
    for (int i = 0; i < n; i++) {
        dataTemp[i] = malloc(sizeof(char)*dataLen+1);
        for (int j = 0; j < dataLen; j++) {
            dataTemp[i][j] = (char)('0'+(rand()%10));
        }
        dataTemp[i][dataLen]='\n';
    }
    FILE * setIntData;
    setIntData = fopen("./IntData.txt","w");
    for (int i = 0; i < n; i++) {
        sprintf(setIntData,"%s",dataTemp[i]);
        free(dataTemp[i]);
    }
    free(dataTemp);
    fclose(setIntData);
}

void creatSearch(){
    char ** dataTemp= malloc(sizeof(char * )*m);
    srand( time(NULL) );
    for (int i = 0; i < m; i++) {
        dataTemp[i] = malloc(sizeof(char)*dataLen+1);
        for (int j = 0; j < dataLen; j++) {
            dataTemp[i][j] = (char)('0'+(rand()%10));
        }
        dataTemp[i][dataLen]='\n';
    }
    FILE * setIntData;
    setIntData = fopen("./IntSearch.txt","w");
    for (int i = 0; i < m; i++) {
        sprintf(setIntData,"%s",dataTemp[i]);
        free(dataTemp[i]);
    }
    free(dataTemp);
    fclose(setIntData);
}

void runStructure(){
    for (int i = 0; i < 5; i++) {
        if(parmTag[i][0] !=0 ){
            switch (i) {
                case 0:

                    break;
                case 1:

                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:

                    break;
            }
        }
    }
}
