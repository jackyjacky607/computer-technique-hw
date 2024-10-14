#include <stdio.h>
int main(){
	int N,i,j,k,minus,total;
	printf("N = ");
	scanf("%d",&N);
	for(i=1;i<N;i++){
		for (j=i+1;j<N;j++){
			for (k=j+1;k<N;k++){
				minus=N-i-j-k;
				if (minus>k&&minus<N &&minus!=i&&minus!=j&&minus!=k){
					total+=1;
					//printf("(%d %d %d %d)",i,j,k,minus);
				}
				
			}
		}
		
	}
	printf("Total is %d.",total);
}
