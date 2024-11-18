#include <stdio.h>

void sort(int *arr,int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=0;j<=n-i-2;j++){
            if (*(arr+j)>*(arr+j+1)){
                temp=*(arr+j);
                *(arr+j)=*(arr+j+1);
                *(arr+j+1)=temp;
            }
        }
    }
}

int main(){
    int n,i;
    printf("請輸入整數的個數: ");
    scanf("%d",&n);
    int num[n];
    for(i=1;i<=n;i++){
        printf("請輸入第%d個數: ",i);
        scanf("%d",&num[i-1]);
    }
    sort(num,n);
    printf("排序結果:");
    for(i=0;i<n;i++){
        printf("%d ",num[i]);
    }
    
}