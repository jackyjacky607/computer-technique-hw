#include <stdio.h>
#include <string.h>
int main(){
    int max;
    FILE* filein;
    FILE* fileout;
    printf("enter width: ");
    scanf("%d%*c",&max);
    filein=fopen("t12.txt","r");
    fileout=fopen("t13.txt","w");
    int currentsize=0;
    char word[100][101];
    int n=0;
    while (fscanf(filein,"%s",word[n])==1)
    {
        //printf("%s\n",word[n]);
        int len=strlen(word[n]);
        //printf("%d ",len);
        if (currentsize+len>=max){
            //printf("max\n");
            int i;
            for(i=0;i<n;i++){
                fprintf(fileout,"%s ",word[i]);
            }
            if(n==0) fprintf(fileout,"%s ",word[0]);
            int left=max-currentsize;
            
            for(int j=0;j<left;j++){
                fprintf(fileout,"%c",word[i][j]);
            }
            fprintf(fileout,"\n");
            currentsize=len-left;
            n=0;
            
            continue;
        }
        else
        {
            currentsize+=len;
            n++;
            if (currentsize+1>max){
                for(int i=0;i<n;i++){
                    fprintf(fileout,"%s ",word[i]);
                }
                if(n==0) fprintf(fileout,"%s ",word[0]);
                fprintf(fileout,"\n ");

                currentsize=1;
                n=0;
                continue;
            }
            else
            {
                currentsize+=1;
                continue;
            }
        }
    }
    for(int i=0;i<n;i++){
        fprintf(fileout,"%s ",word[n]);
    }
    fclose(filein);
    fclose(fileout);
}