
//x+y=num1
//x+2y=num2/2
#include <stdio.h>
#define true 1
int main(){
	
	int num1=1,num2,c,r;
	
	
	while(true){
		printf("總數量+總腳數:");
		scanf("%d+%d",&num1,&num2);
		if (num1==0&&num2==0)
			break;
		if ((num2%2)!=0){
			printf("無解\n");
			continue;}
		r=(num2/2-num1);
		c=num1-r;
		if (r>=0 && c>=0){
			printf("雞 %d 隻   兔子 %d 隻\n",c,r);
			continue;}
		else{
			printf("無解\n");
			continue;}
		}
}

