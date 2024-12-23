#include <stdio.h>
#include <string.h>

int check(const char *s,int l, int r){
    while (l<r){
        if(s[l]!=s[r]){
            return 0;
        }
        l++;
        r--;

    }
    return 1;
}
void find(char *s,FILE*dataout){
    int n = strlen(s);
    int maxlength =1;
    int count =0;
    int list[100][2];
    for (int i=0; i<n;i++){
        for (int j=i;j<n;j++){
            int currentLength = j-i+1;
            if (check(s,i,j)){
                    if (currentLength>maxlength){
                        maxlength=currentLength;
                        count=0;
                        list[count][0]=i;
                        list[count][1]=j;
                        count++;
                    }
                    else if(currentLength == maxlength){
                        list[count][0]=i;
                        list[count][1]=j;
                        count++;
                    }
            }
        }
        
    }
    
    fprintf(dataout,"%d,%d\n",maxlength,count);
    //printf("最長回文為:");
        /*for (int i=0;i<count;i++){
            int start = list[i][0];
            int end = list[i][1];
            for (int k=start; k<=end;k++){
                putchar(s[k]);
            }
            if(i==count-1)break;
            printf(",");
        }*/
}
int main(){
    char a[101];
    FILE *datain;
    FILE *dataout;
    dataout=fopen("t8.txt","w");
    datain = fopen("t7.txt","r");
    while (fscanf(datain,"%s",a)==1)
    {
        find(a,dataout);
    }
    fclose(datain);
    fclose(dataout);
    //printf("請輸入一個字串:");
    //scanf("%s",a);
    
    return 0;
}