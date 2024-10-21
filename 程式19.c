#include<stdio.h>
int main(){
    
    int code[26]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
    char input[11],A1,A2;int i,Y,check;
    printf("請輸入身分證字號:");
    scanf("%s",input);

    for(i=1;i<10;i++){
        input[i]=(int)input[i]-(int)'0';
    }
    A1=code[input[0]-'A']/10;
    A2=code[input[0]-'A']%10;
    input[0]=A1;input[10]=A2;
    /*for(i=0;i<11;i++){
        printf("%d ",input[i]);
    }*/
   Y=input[0]+input[1]*8+input[2]*7+input[3]*6+input[4]*5+input[5]*4+input[6]*3+input[7]*2+input[8]*1+input[10]*9;
   if (Y%10==0){
        check=0;
   }
   else{
    check=10-(Y%10);
   }
   if (input[9]==check){
    printf("身份證字號正確!!");
   }
   else{printf("身份證字號錯誤!!");}
}