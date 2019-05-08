#include<bits/stdc++.h>
using namespace std;
int a[30],n,r;
void dfs(int s)
{
	if(s==r)
	{
		for(int i=1;i<=r;++i)printf("%3d",a[i]);
		printf("\n");
		return;
	}
	for(int i=a[s]+1;i<=n;++i){
		a[s+1]=i;
		dfs(s+1);
	}
}
int main()
{
	scanf("%d%d",&n,&r);
	dfs(0);
	return 0;
}
