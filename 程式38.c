#include <stdio.h>
#include<string.h>
int main(){
    char word[2000][20];
    char compare[2000][20];
    int n=0,i;
    FILE *datain;
    FILE *dataout;
    datain=fopen("t10.txt","r");
    dataout=fopen("t11.txt","r");
    if(datain != NULL && dataout != NULL){
        while (fscanf(datain,"%s",word[n])==1){
             if (!(word[n][strlen(word[n]) - 1] >= 'a' && word[n][strlen(word[n]) - 1] <= 'z')) {
                word[n][strlen(word[n]) - 1] = '\0';
            }
            if (word[n][strlen(word[n])-1]>='A' && word[n][strlen(word[n])-1]<='Z')
                word[n][0]+=32;
            n++;
        }
        int len1=n;
        /*for (i=0;i<n;i++){
            printf("%s ",word[i]);
        }*/
        n=0;
        while (fscanf(dataout,"%s",compare[n])==1){
            if (!(compare[n][strlen(compare[n]) - 1] >= 'a' && compare[n][strlen(compare[n]) - 1] <= 'z')) {
                compare[n][strlen(compare[n]) - 1] = '\0';
            }
            if (compare[n][strlen(compare[n])-1]>='A' && compare[n][strlen(compare[n])-1]<='Z')
                compare[n][0]+=32;
            n++;
        }
        int len2=n;
        int j=0;
        int a;
        int ans=0;
        for (i=0;i<n;i++){
            //printf("%s ",compare[i]);
            for (j=0;j<len1;j++){
                if (strcmp(compare[i],word[j])==0){
                    for (a=1;a<7;a++){
                        if (!(strcmp(compare[i+a],word[j+a])==0))break;
                    }
                    if (a==7){
                        a++;
                        while(strcmp(compare[i+a],word[j+a])==0){
                            a++;
                        }
                        a--;
                        ans+=a;
                        i+=a;
                        break;
                    }
                }
            }
        }
        printf("%d/%d = %.2f",ans,len1,ans/len1);
    }
}