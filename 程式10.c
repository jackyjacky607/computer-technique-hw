
#include <stdio.h>
int main(){
	int j,i,k,total=0;
	printf("Please input a number:");
	scanf("%d",&i);
	for(j=2;j<=i;j++){
		for (k=2;k<j;k++)
			if(j%k==0)
			break;
		if (k*k>j){
		
			printf("%d ",j);
			total+=1;}
		
	}
	printf("\nTotal is %d",total);
	
}

