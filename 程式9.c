#include <stdio.h>
int main(){
	int a,i,j;
	printf("Please input a number:");
	scanf("%d",&a);
	int numbers,space;
	for(i=1;i<a+1;i++){
		numbers=i*2-1;
		for(space=0;space<a-i;space++)
			printf(" ");
		for(j=1;j<=numbers/2;j++){
			printf("%d",j%10);
		}
		printf("%d",i%10);
		for(j=numbers/2;j>0;j--){
			printf("%d",j%10);
		}
		printf("\n");
	}
}


