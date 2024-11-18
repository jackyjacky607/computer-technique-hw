#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int num,cur=0,pic;
    srand(time(NULL));
    num=rand()%31+10;
    //num=33;
    printf("N=%d\n",num);
    
    while(cur<num){
        if ((num-cur-1)%4==0){
            pic=rand()%3+1;
        }else pic = (num-cur-1)%4;
        
        printf("Sum=%d, Computer add %d\n",cur,pic);
        cur+=pic;
        if (cur>=num){
            printf("Sum=%d, You win!!\n",cur);
            break;
        }
        printf("Sum=%d, You add: ",cur);
        scanf("%d",&pic);
        cur+=pic;
        if (cur>=num){
            printf("Sum=%d, You lose!!\n",cur);
            break;
        }
    }
}