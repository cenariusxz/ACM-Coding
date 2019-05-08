#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int a[100005],ans[100005];

int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	int maxx=0,cnt=0;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(j=0;j<=31;j++){
			if(i&(1<<j))break;
		}
		if(j>maxx)maxx=j;
	}
	for(i=1;i<=n;i++){
		bool f=1;
		for(j=0;j<maxx&&f;j++){
			if(i&(1<<j))f=0;
		}
		if(f)ans[++cnt]=i;
	}
	printf("%d\n",cnt);
	for(i=1;i<=cnt;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
