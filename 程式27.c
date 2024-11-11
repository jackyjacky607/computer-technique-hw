//#define max(a,b) ((a)>(b) ? (a):(b))
#include <stdio.h>
static int count;
void towers(int n,char from,char aux,char to){
    if (n==1){
        printf("ring %d: %c => %c\n",n,from,to);
        count++;
        return;}
    towers(n-1,from,to,aux);
    printf("ring %d: %c => %c\n",n,from,to);
    towers(n-1,aux,from,to);
    count++;
}
int main(){
    int n;
    printf("請輸入A柱中的環個數");
    scanf("%d",&n);
    towers(n,'A','B','C');
    printf("%d",count);
}