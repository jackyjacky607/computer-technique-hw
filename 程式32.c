#include <stdio.h>


int gcd(int n1,int n2){
    while (n1!=0 && n2!=0){
        if (n1>n2)n1-=n2;
        else n2-=n1;
    }
    return (n1>n2?n1:n2);
}
void sort_fraction(int (*arr)[2],int n){
    int i,j,temp[2],a,b,c;
    for(i=0;i<n;i++){
        for(j=0;j<=n-i-2;j++){
            if ((*(arr+j)[0])*(*(arr+j+1)[1])>(*(arr+j)[1])*(*(arr+j+1)[0])){
                temp=*(arr+j);
                *(arr+j)=*(arr+j+1);
                *(arr+j+1)=temp;
            }
        }
    }
}

int main(){
    printf("Please input a number: ");
    int n,i,j,frac[100][2],a=0;
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        for (j=1;j<i+2;j++){
            frac[a][0]=j;
            frac[a][1]=i+2;
            a++;
        }
    }
    /*for(i=0;i<a;i++){
        printf("%d %d\n",frac[i][0],frac[i][1]);
    }*/
   sort_fraction(frac,a);
    for(i=0;i<a;i++){
        printf("%d %d\n",frac[i][0],frac[i][1]);
    }
}