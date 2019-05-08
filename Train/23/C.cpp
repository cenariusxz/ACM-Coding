#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;

int a[10];

bool sum(int x,int y,int z){
	return (a[x]+a[y]+a[z])%1024==0;
}

int get(int x,int y){
	int s=a[x]+a[y];
	while(s>1024)s-=1024;
	return s;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n<=3){
			for(int i=1;i<=n;++i)scanf("%d",&a[0]);
			printf("1024\n");
			continue;
		}
		a[0]=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		if(n==4){
			if(sum(1,2,3)||sum(1,2,4)||sum(1,3,4)||sum(2,3,4)){
				printf("1024\n");
				continue;
			}
			else{
				int ans=0;
				ans=max(ans,get(1,2));
				ans=max(ans,get(1,3));
				ans=max(ans,get(1,4));
				ans=max(ans,get(2,3));
				ans=max(ans,get(2,4));
				ans=max(ans,get(3,4));
				printf("%d\n",ans);
				continue;
			}
		}
		else{
			int ans=0;
			if(sum(1,2,3))ans=max(ans,get(4,5));
			if(sum(1,2,4))ans=max(ans,get(3,5));
			if(sum(1,2,5))ans=max(ans,get(3,4));
			if(sum(1,3,4))ans=max(ans,get(2,5));
			if(sum(1,3,5))ans=max(ans,get(2,4));
			if(sum(1,4,5))ans=max(ans,get(2,3));
			if(sum(2,3,4))ans=max(ans,get(1,5));
			if(sum(2,3,5))ans=max(ans,get(1,4));
			if(sum(2,4,5))ans=max(ans,get(1,3));
			if(sum(3,4,5))ans=max(ans,get(1,2));
			printf("%d\n",ans);
		}
	}
	return 0;
}
