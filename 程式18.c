#include<stdio.h>
int main(){
    int n,i,j,value,x;
    printf("Please input the size of matrix");
    scanf("%d",&n);
    int m1[10][10],m2[10][10];
    printf("Please input matrix1\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&m1[i][j]);
        }
    }
    printf("Please input matrix2\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&m2[i][j]);
        }
    }
    printf("\n");
    /*for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",m1[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",m2[i][j]);
        }
        printf("\n");
    }*/
   printf("matrix1 * matrix2 =\n");
   for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            value=0;
            for(x=0;x<n;x++){
                value+=m1[i][x]*m2[x][j];
            }
            printf("%d ",value);
        }
        printf("\n");
    }
}