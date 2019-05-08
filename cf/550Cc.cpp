#include<stdio.h>
#include<string.h>

int main(){
	int i,j;
	for(i=8;i<=1000;i+=8){
		if(!(i%10))continue;
		if(i>10&&!((i/10)%10))continue;
		if(i%10==8)continue;
		if(i>10&&((i/10)%10)==8)continue;
		if(i%10==2)printf("%d ",i);
	}
	printf("\n");
	for(i=8;i<=1000;i+=8){
		if(!(i%10))continue;
		if(i>10&&!((i/10)%10))continue;
		if(i%10==8)continue;
		if(i>10&&((i/10)%10)==8)continue;
		if(i%10==4)printf("%d ",i);
	}
	printf("\n");
	for(i=8;i<=1000;i+=8){
		if(!(i%10))continue;
		if(i>10&&!((i/10)%10))continue;
		if(i%10==8)continue;
		if(i>10&&((i/10)%10)==8)continue;
		if(i%10==6)printf("%d ",i);
	}
	printf("\n");
	return 0;
}
