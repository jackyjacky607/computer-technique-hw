#include <stdio.h>
int main(){
	int c,mod;
	printf("輸入一個整數");
	scanf("%d",&c);
	if (c<0)
	printf("%d is not a positive integer!!",c);
	else
		if (c<10)
		printf("%d is a small integar.",c);
		else{
		
			if (c<100){
			
			printf("%d 的十位數是%d\n",c,c/10 );
			printf("%d 的個位數是%d",c,c%10 );
			}
			else{
			
			mod=c%5;
				switch(mod){
				
					case 0:
						printf("%d is a large integer\n",c);
						printf("%d is divisible by 5",c);
						break;
					case 1:
						printf("%d is a large integer\n",c);
						printf("%d+5=%d",c,c+5);
						break;
					case 2:
						printf("%d is a large integer\n",c);
						printf("%d-5=%d",c,c-5);
						break;
					case 3:
						printf("%d is a large integer\n",c);
						printf("%d*5=%d",c,c*5);
						break;
					case 4:
						printf("%d is a large integer\n",c);
						printf("%d/5=%.2f",c,(float)c/5);
						break;
				}
			}
}}

