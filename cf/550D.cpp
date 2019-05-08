#include<stdio.h>
#include<string.h>

int main(){
	int k,i,j;
	scanf("%d",&k);
	if(k%2){
		if(k==1){
			printf("YES\n2 1\n1 2\n");
		}
		else{
			int n=2*k+4,m=k*(k+1)+k;
			printf("YES\n%d %d\n",n,m);
			for(i=1;i<k+1;i++){
				for(j=i+1;j<=k+1;j++){
					if(j==i+1||j+i!=k+2){
						printf("%d %d\n%d %d\n",i,j,i+k+1,j+k+1);
					}
					else{
						printf("%d %d\n%d %d\n%d %d\n%d %d\n",i,2*k+3,j,2*k+3,i+k+1,2*k+4,j+k+1,2*k+4);
					}
				}
			}
			printf("%d %d\n",2*k+3,2*k+4);
		}
	}
	else{
		printf("NO\n");
	}
	return 0;
}
