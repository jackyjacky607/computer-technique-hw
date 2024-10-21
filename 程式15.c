#include <stdio.h>
int main(){
	int j,i,k,total=0,n=0,count=0;
	printf("Please input a number:");
	scanf("%d",&i);
	for(j=2;j<=i;j++){
		for (k=2;k*k<=j;k++)
			if(j%k==0)
			break;
        
		if (k*k>j){
			//printf("%d ",j);
            n=0;
			total+=1;
            continue;
            }
        n+=1;
		if (n>=4){
            printf("(%d,%d,%d,%d)",j-3,j-2,j-1,j);
            count+=1;
        }
	}
	printf("\nTotal is %d",count);
	getchar();
    return 0;
}