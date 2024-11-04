#include <stdio.h>

int main(){
    int year,i,week,month[12]={31,28,31,30,31,30,31,31,30,31,30,31},j,this,count=0;
    printf("Please input the century: ");
    scanf("%d",&year);
    for (i=100*year-99;i<=100*year;i++){
        month[1]=28;

        if ((i%4==0)){
            if (i%100==0){
                if(i%400==0){
                    month[1]=29;
                }
            }
            else month[1]=29;
        }



        week=(i+(int)((i-1)/4)-(int)((i-1)/100)+(int)((i-1)/400))%7;
        //printf("%d ",week);
        for (j=0;j<12;j++){
            this=(week+12)%7;
            if (this==5) count++;
            week=(week+month[j])%7;
        }
    }
    printf("%d times!!",count);
}