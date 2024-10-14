
#include <stdio.h>
#include<math.h>
int main(){
	int num,i,sum,j,length,total=0;
	printf("Please input a number:");
	scanf("%d",&num);
	
	for (i=0;i<=num;i++){
		sum=0;
		j=i;
		length=(i==0)?1:(int)log10(i)+1;
		//printf("%d\n",j);
		while (j!=0){
			//printf("%d ",j);
			sum+=pow((j%10),length);
			j/=10;
			
		}
		//printf("%d %d \n",sum,i);
		if (sum==i){
		
			printf("%d, ",i);
			total+=1;}
	
}
	printf("\nTotal is %d",total);
    getchar();
} 

