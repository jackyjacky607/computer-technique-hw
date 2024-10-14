
#include <stdio.h>
int main(){
	int num1,num2;
	printf("Please input two integers:");
	scanf("%d %d",&num1,&num2);
	while(num1>0 && num2>0)
	{
		if (num1>num2){
			while(num1>num2){
				num1-=num2;
				if (num1==0){
					printf("GCD is %d",num2);
					num1=-1;
				}
			}
		}
		else if (num1==num2){
			printf("GCD is %d",num1);
			num1=-1;
		}
		else{
			while(num2>num1){
				num2-=num1;
				if (num2==0){
					printf("GCD is %d",num2);
					num1=-1;
				}
		}
		
	}
	
}
//printf("%d",num1);
//printf("%d",num2);
if (num1!=-1 && num2!=-1)
		printf("GCD is 1");
}

