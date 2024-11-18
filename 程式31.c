#include <stdio.h>
#include<string.h>
void check_ISBN10(char *arr){
    int i,sum=0;
    for (i=0;i<9;i++){
        sum+=(*(arr+i)-'0')*(10-i);
    }
    sum+=(*(arr+i)=='X'?10:*(arr+i)-'0');
    //printf("%d",sum);
    if (sum%11==0) printf("The ISBN code is correct!!\n");
    else printf("The ISBN code is wrong!!\n");
}

void check_ISBN13(char *arr){
    int i,sum=0,a=1;
    for (i=0;i<12;i++){
        sum+=(*(arr+i)-'0')*a;
        //printf("%d ",sum);
        a=(a==1?3:1);
    }
    //printf("%d ",*(arr+i)-'0');
    //printf("%d",10-(sum%10));
    if ((10-(sum%10))%10==*(arr+i)-'0')printf("The ISBN code is correct!!\n");
    else printf("The ISBN code is wrong!!\n");
}
int main(){
    char input[14];
    printf("Please input an ISBN code: ");
    scanf("%s",input);
    while (strlen(input)==13 || strlen(input)==10){
        if (strlen(input)==13)check_ISBN13(input);
        else check_ISBN10(input);
        printf("Please input an ISBN code: ");
        scanf("%s",input);
    }    
    printf("Error!");
    return 0;
}