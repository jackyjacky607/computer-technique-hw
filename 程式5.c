#include <stdio.h>
int main(){
	int a,i;
	printf("Please input a number:");
	scanf("%d",&a);
	int numbers,space;
	for(i=1;i<a+1;i++){
		numbers=i*2-1;
		for(space=0;space<a-i+1;space++)
			printf(" ");
		for(space=0;space<numbers;space++)
			printf("%d",i%10);
		for(space=0;space<a;space++)
			printf(" ");
		printf("\n");
	}
}
