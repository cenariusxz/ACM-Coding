#include<iostream>
#include<stdio.h>
#include<algorithm>
#define MAXN 100010
using namespace std;
int n,k;
int t[MAXN];

bool check(int x)
{
	long long sum=0;
	int i;
	for(i=1;i<=n;i++){
		if(x-t[i]>k){
			sum-=x-t[i];
			sum=max(sum,0);
		}
		else{
			sum-=x-t[i];
			sum=max(sum,0);
			sum+=k-(x-t[i]);
		}
	}
}

int main()
{
	int i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&t[i]);
	}
	sort(t+1,t+n+1,greater<int>());
	int l=1,r=1e7,m,ans;
	while(l<=r){
		m=(l+r)>>1;
		if(check(m)){
			ans=m;
			r=m-1;
		}
		else l=m+1;
	}
 return 0;
 }
