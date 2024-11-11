//#define max(a,b) ((a)>(b) ? (a):(b))
#include <stdio.h>

void towers(int n,char from,char aux,char to){
    if (n==1){
        printf("ring %d: %c => %c\n",n,from,to);
        return;}
    towers(n-1,from,to,aux);
    printf("ring %d: %c => %c\n",n,from,to);
    towers(n-1,aux,from,to);
}
int main(){
    int n;
    scanf("%d",&n);
    towers(n,'A','B','C');
}