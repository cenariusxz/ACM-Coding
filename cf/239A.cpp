#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int y,k,n,i;
	int pos=-1;
	scanf("%d%d%d",&y,&k,&n);
	bool f=0;
	for(i=0;i<=n;i+=k){
		if((!(i%k))&&(i>y)){
			printf("%d ",i-y);
			f=1;
		}
	}
	if(!f)printf("-1");
		printf("\n");
	return 0;
}
