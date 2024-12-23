#include <stdio.h>
#define min(a,b) (((a)>(b))?(b):(a))
int main(){
    int size[4]={4,7,13,16};
    int price[4]={2500,3800,6400,7500};
    printf("請輸入乘客總人數");
    int a;
    scanf("%d",&a);
    int m=99999999;
    int people=0;
    for(int i=0;i<=a/16+1;i++){
        int p=i*16;
        if (p>a){
            m=min(m,i*7500);

        }
        for (int j=0;j<=(a-people)/13+1;j++){
            int q=p+j*13;
            if (q>a){
                m=min(m,i*7500+j*6400);
            }
            for (int k=0;k<=(a-people)/7+1;j++){
                int r=p+q+k*7;;
                if (r>a){
                    m=min(m,i*7500+j*6400+k*3800);
                }
                for (int l=0;l<=(a-people)/4+1;l++){
                    int s=p+q+r+l*4;
                    if (s>a){
                        m=min(m,i*7500+j*6400+k*3800+l*2500);
                    }
                }
            }
        }
    }
    printf("%d",m);
}