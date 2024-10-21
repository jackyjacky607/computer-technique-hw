#include <stdio.h>
int main(){
    int num,n=1,temp,cur;
    printf("Please input a number: ");
    scanf("%d",&num);
    temp=2;
    printf("1");
    while(n<num){
        cur=temp;
        while(temp%2==0)temp/=2;
        while(temp%3==0)temp/=3;
        while(temp%5==0)temp/=5;
        if (temp==1){
        printf(",%d",cur);
        n+=1;
        }
        temp=cur+1;
    }
}