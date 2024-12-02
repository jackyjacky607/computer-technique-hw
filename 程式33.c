//#define max(a,b) ((a)>(b) ? (a):(b))
#include <stdio.h>
static int count=0;
void towers(int n,char from,char aux,char to){
    if (n==1){
        printf("ring %d: %c => %c\n",n,from,to);
        count++;
        return;}
    towers(n-1,from,to,aux);
    printf("ring %d: %c => %c\n",n,from,to);
    towers(n-1,aux,from,to);
    count++;
    return;
}

void doublehanoi(int n,char from,char aux,char to){
    if (n==2){
        printf("ring 1: %c => %c\n",from,aux);
        printf("ring 2: %c => %c\n",from,to);
        count+=2;
        return;
    }
    if(n==4){
        towers(3,from,to,aux);
        printf("ring 4: %c => %c\n",from,to);
        printf("ring 1: %c => %c\n",aux,from);
        printf("ring 2: %c => %c\n",aux,to);
        printf("ring 1: %c => %c\n",from,aux);
        count+=4;
        return;
    }
    towers(n-1,from,to,aux);
    printf("ring %d: %c => %c\n",n,from,to);
    towers(n-3,aux,to,from);
    printf("ring %d: %c => %c\n",n-2,from,to);
    towers(n-4,from,aux,to);
    printf("ring %d: %c => %c\n",n-3,from,aux);
    
    if (n>6)towers(n-6,to,aux,from);
    printf("ring %d: %c => %c\n",n-5,from,to);
    if (n>6) doublehanoi(n-6,from,aux,to);
    count+=4;
}
int main(){
    int n;
    printf("請輸入A柱中的環個數");
    scanf("%d",&n);
    doublehanoi(n,'A','B','C');
    printf("共需%d個步驟",count);
}