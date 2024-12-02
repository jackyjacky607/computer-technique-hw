#include <stdio.h>
#include <ctype.h>
#include<string.h>
int main()
 {
    char ch,word[100][20],record[100][20];
    int count[100]={1};  
    FILE *DataIn;
    FILE *DataOut;
    int n=0,i,j=0;
    DataIn=fopen("t3.txt","r"); 
    DataOut=fopen("t4.txt","w");
    if (DataIn != NULL && DataOut != NULL){
         while(fscanf(DataIn,"%s",word[n]) == 1){
            if (!(word[n][strlen(word[n])-1]>='A' && word[n][strlen(word[n])-1]<='Z'))word[n][strlen(word[n])-1]='\0';
            for (i=0;i<n;i++){
                if (strcmp(word[i],word[n]))break;
            }
            if (i==n){
                strcpy(record[j],word[n]);
                j++;
            }
            else{
                for (i=0;i<j;i++){
                    if (strcmp(record[i],word[n])==0) count[i]++;
                }
            }
           
           n++;
           
        }
        
    }
    for (i=0;i<n;i++){
        printf("%s",record[i]);
         fprintf(DataOut,"%s: %d\n",record[i],count[i]);
    }
    fclose(DataIn);
    fclose(DataOut);
    return 0;
}