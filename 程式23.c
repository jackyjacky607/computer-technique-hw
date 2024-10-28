#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char a[51], b[51],ch;
    int c[26]={0},d[26]={0},i,len1,len2;
    printf("Please input string #1:");
    scanf("%[^\n]",a);
    scanf("%*c");
    printf("Please input string #2:");
    scanf("%[^\n]",b);
    scanf("%*c");
    len1=strlen(a);
    len2=strlen(b);
    for(i=0;i<len1;i++){
        if ((a[i]>'A'&& a[i]<'Z') || (a[i]>'a'||a[i]<'z')){
            c[tolower(a[i])-'a']+=1;
        }
    }
    for(i=0;i<len2;i++){
        if ((a[i]>'A'&& a[i]<'Z') || (a[i]>'a'||a[i]<'z')){
            d[tolower(b[i])-'a']+=1;
        }
    }
    /*for (i=0;i<26;i++){
        printf("%d ",c[i]);
    }
    printf("\n");
    for (i=0;i<26;i++){
        printf("%d ",d[i]);
    }*/
    printf("\n");
   for (i=0;i<26;i++){
        if (c[i]==d[i]) continue;
        else break;
    }
    if (i>=26) printf("Yes");
    else printf("No");
}