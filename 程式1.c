#include <stdio.h> 
#include <stdlib.h>

int main(){
	char a[10];
	char b;
	int c,d;
	float average;
	printf("Please input your name.... ");
	
	scanf("%s%*c",a);
	printf("Please input your department.... (a:資工 b:電機 c:電子)");
	scanf("%c%*c",&b);

	

	printf("Please input your score on test 1.... ");
	scanf("%d%*c",&c);

	printf("Please input your score on test 2.... ");
	scanf("%d%*c",&d);
	average = ((float)c+d)/2;
	printf("%s\n",a);
	printf("|-------------------------------------------|\n");
	printf("|   Name   |Department|Test 1|Test 2|Average|\n");
	printf("|-------------------------------------------|\n");
	printf("|%-10s|%-10c|%6d|%6d|%7.2f|\n",a,b,c,d,average);
	printf("|-------------------------------------------|");
	
}

