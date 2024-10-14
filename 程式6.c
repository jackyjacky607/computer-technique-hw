#include <stdio.h>
int main(){
	int num1,num2,sum;
	char a='y';
	do{
		sum=0;
		printf("Number 1:");
		scanf("%d",&num1);
		printf("Number 2:");
		scanf("%d",&num2);
		if (num1>num2){
			printf("Error!! Number 1 > Number 2!!\n");
			continue;
		}
		sum= (num1+num2)*(num2-num1+1)/2;
		printf("Sum = %d\n",sum);
		printf("Again(Y/N)??");
		scanf("%*c%c",&a);
		
	}while(a=='Y'||a=='y');
	return 0;
} 

