#include <stdio.h>

int main(){
	int a;
	
	printf("Please input the nmuber of integers:");
	scanf("%d",&a);
	int min,max,num,sum,i;float average;
	printf("Integer #1 ..... ");
	scanf("%d",&num);
	min=num;
	max=num;
	sum=num;
	for(i=2;i<a+1;i++){
		printf("Integer #%d ..... ",i);
		scanf("%d",&num);
		sum+=num;
		if (num<min)
			min=num;
		if (num>max)
			max=num;
		
	}
	average=(float)sum/a;
	printf("The average is %.2f\n",average);
	printf("The maximum is %d\n",max);
	printf("The minimum is %d\n",min);
	return 0;
}
