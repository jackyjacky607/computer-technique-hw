#include <stdio.h>

int find(int f1,int f2,int f){
    while (f1%f!=0){
        f1++;
    }
    while (f2%f!=0){
        f2--;
    }
    return (f2-f1)/f+1;
}
int main(){
    int y1,y2,m1,m2,d1,d2;
    printf("請輸入西元開始日期(yyyy/mm/dd)為...");
    scanf("%d/%d/%d",&y1,&m1,&d1);
    //printf("%d %d %d",y1,m1,d1);
    printf("請輸入西元結束日期(yyyy/mm/dd)為...");
    scanf("%d/%d/%d",&y2,&m2,&d2);
    int f,h,fh,ans=0;
    if ((y1%4==0 && y1%100!=0)||y1%400==0){
        if(m1>2) ans--;
    }
    if ((y2%4==0 && y2%100!=0)||y2%400==0){
        if(m2<=2) ans--;
    }
    //printf("%d\n",ans);
    f=find(y1,y2,4);
    h=find(y1,y2,100);
    fh=find(y1,y2,400);
    ans+=f-h+fh;
    printf("%d\n",ans);
}