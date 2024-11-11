#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fact(int n){
    if (n==0)return 1;
    int num=1,i;
    for (i=n;i>0;i--){
        num*=i;
    }
    return num;

}
int count(char a[],char b,int len){
    int i,count=0;
    for(i=0;i<len;i++){
        if (a[i]==b)
        count++;
    }
    return count;
}
int main(){
    //printf("%d",fact(5));
    char a[13],b;
    int i,ans,len,j;
    printf("Please input a string: ");
    scanf("%s",a);
    len=strlen(a);
    ans=fact(len);
    for(i=0;i<len;i++){
        b=a[i];
        for (j=0;j<i;j++){
            if (a[j]==b) break;;
        }
        if (j>=i){
        ans/= fact(count(a,b,len));
        }
    }
    printf("The number of permutations is %d",ans);
}