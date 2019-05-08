#include<stdio.h>
#include<string.h>
#define min(a,b) a<b?a:b

int a[150005];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int i,j;
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		a[i]=a[i-1]+t;
	}
	int ans=0xFFFFFFF,m;
	for(i=0;i<=n-k;i++){
		int t=a[i+k]-a[i];
		if(t<ans){
			ans=t;
			m=i+1;
		}
	}
	printf("%d\n",m);
	return 0;
}
