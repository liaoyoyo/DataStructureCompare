#include <stdio.h>
#include <string.h>
int main(int argc,char * argv[]) {
    char parm[7][5] = {"-d","-q","-bst","-bs","-arr","-ll","-hash"};
    int n=0,m=0;
    int parmTag [5][3] = {
            // use 0/1, building time: xxxx sec, query time: xxxx sec
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0}
    };
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

    return 0;
}
