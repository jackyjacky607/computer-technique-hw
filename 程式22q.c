#include <stdio.h>
#include<string.h>
int main(){
    char str1[101],str2[101],len1,len2;
    int i,j,count=0;
    printf("Please input the string 1:");
    scanf("%s",str1);
    printf("Please input the string 2:");
    scanf("%s",str2);
    len1=strlen(str1);
    len2=strlen(str2);
    if (len2>len1){
        printf("String 2 is not a substring of string 1");
        return 0;
    }
    for (i=0;i<=len1-len2;i++){
        //printf("%d",i);
        for (j=i;j<i+len2;j++){
            if (str1[j]==str2[j-i])continue;
            else break;
        }
        //printf("%d\n",j);
        if (j>=i+len2){
            count+=1;
        }
    }
    if (count==0)printf("String 2 is not a substring of string 1");
    else {
        printf("String 2 is a substring of string 1\n");
        printf("Repeat %d times",count);
        }
}