#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char c[101];
    int a[9],b=9,len,d[3],i,new[3];
    printf("Please input a 3*3 key matrix (9 integers): ");
    while (b)
    {
        scanf("%d",&a[9-b]);
        //printf("%d ",a[9-b]);
        b-=1;
    }
    scanf("%*c");
    printf("Please input a string: ");
    scanf("%s",c);
    len=strlen(c);
    for(b=0;b<len;b+=3){
        for(i=0;i<3;i++){
            d[i]=(c[b+i]-'A');
            //printf("%d ",d[i]);
        }
        for(i=0;i<3;i++){
            new[i]=(d[0]*a[3*i]+d[1]*a[3*i+1]+d[2]*a[3*i+2])%26;
            //printf("%d ",new[i]);
            c[b+i]='A'+new[i];
            printf("%c",c[b+i]);
        }
    }
}