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
        printf("%s\n",word[n]);
        int len=strlen(word[n]);
        //printf("%d ",len);
        if (currentsize+len>max){
            printf("max\n");
            for(int i=0;i<n;i++){
                fprintf(fileout,"%s ",word[n]);
            }
            currentsize=0;
            fprintf(fileout,"\n");
            continue;
        }
        else
        {
            currentsize+=len;
            n++;
            if (currentsize+1>max){
                for(int i=0;i<n;i++){
                    fprintf(fileout,"%s ",word[n]);
                }
                currentsize=0;
                fprintf(fileout,"\n");
                continue;
            }
            else
            {
                currentsize+=1;
                continue;
            }
        }
        
        /*char space;
        if (fscanf(filein,"%c",space)==1&& space!= EOF){
            if (currentsize+1>max){
                for(int i=0;i<n;i++){
                    fprintf(fileout,"%s ",word[n]);
                }
                currentsize=0;
                fprintf(fileout,"\n");
                continue;
            }
            else
            {
                currentsize+=1;
                continue;
            }
        }
        else
        {
            for(int i=0;i<n;i++){
                fprintf(fileout,"%s ",word[n]);
            }
            break;
        }*/
        
    }
    for(int i=0;i<n;i++){
        fprintf(fileout,"%s ",word[n]);
    }
    fclose(filein);
    fclose(fileout);
}