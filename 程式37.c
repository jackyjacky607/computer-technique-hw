#include<stdio.h>

int main(){
    int i,j=2,num[100][2],n=0;
    printf("Plese input a number n(1<n<10000000000)");
    scanf("%d",&i);
    printf("%d = ",i);
    while (i!=1){
        if (i%j==0){
            num[n][0]=j;
            num[n][1]=1;
            i/=j;
            while(i%j==0){
                i/=j;
                num[n][1]++;
            }
            n++;
        }
        j++;
    }
    
    /*for(i=0;i<n;i++){
        printf("%d %d ",num[i][0],num[i][1]);
    }*/

    for(i=0;i<n;i++){
        for (j=0;j<num[i][1];j++){
            printf("%d ",num[i][0]);
            if (i<n-1 || j!=num[i][1]-1)printf("* ");
        }
    }
}