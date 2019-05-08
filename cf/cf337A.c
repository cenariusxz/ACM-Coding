#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define min(a,b) a<b?a:b
int f[55];

int main(){
	int n,m;
	while(scanf("%d%d",&m,&n)!=EOF){
		int i;
		for(i=1;i<=n;i++){
			scanf("%d",&f[i]);
		}
		int ans=0xFFFFFFF;
		sort(f+1,f+n+1);/*
		for(i=1;i<=n;i++){
			printf("%3d",f[i]);
		}
		printf("\n");*/
		for(i=1;i<=n-m+1;i++){
			ans=min(ans,f[i+m-1]-f[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
