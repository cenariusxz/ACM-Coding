#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<string.h>
using namespace std;
int n,k;
int a[20010],b[20010];
int c[20010];

inline int lowbit(int x)
{
	return x&(-x);
}

void add(int x)
{
	for(int i=x;i<=n;i+=lowbit(i)) c[i]++;
}

int sum(int x)
{
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i)) ans+=c[i];
	return ans;
}

void fuck()
{
	int i;
	long long ans1=0,ans2=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<=(n-1)/k;i++){
		b[i]=i*k+1;
	}
	for(i=1;i<=n;i++){
		a[i]=b[(a[i]-1)/k]++;
		ans2=max(ans2,(long long)fabs((double)i-a[i]));
	}
	//for(i=1;i<=n;i++) cout<<a[i]<<endl;
	memset(c,0,sizeof(c));
	for(i=1;i<=n;i++){
		ans1+=sum(n)-sum(a[i]);
		add(a[i]);
	}
	//cout<<ans1<<endl<<ans2<<endl;
	cout<<(long long)fabs((double)ans1-ans2)<<endl;
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case %d: ",i);
		fuck();
	}
 return 0;
}
