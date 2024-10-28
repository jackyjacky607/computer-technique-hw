#include <stdio.h>
#include <string.h>
int main(){
    printf("Please input a decimal number: ");
    int num;
    scanf("%d", &num);
    
    char binary[64];  
    int index = 0;

    if (num == 0) {
        printf("0");
    }


    while (num > 0) {
        binary[index++] = (num % 2) + '0';  
        num /= 2;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%c", binary[i]);
    }
    printf("\n");
    printf("Please input a binary number: ");
    int cur=1;
    char a[33];
    int j=1,i,len;
    scanf("%s",a);
    int b=0;
    len=strlen(a);

    for (i=len-1;i>=0;i--){
        b+=(a[i]-'0')*j;
        j*=2;
        //printf("%d",a[i]);
    }
    printf("%d",b);
}