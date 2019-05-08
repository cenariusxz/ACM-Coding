#include<bits/stdc++.h>
using namespace std;
int n,t;
int x[510],y[510];

void fuck()
{
	int i;
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++) scanf("%d",&x[i]);
	for(i=1;i<=n;i++) scanf("%d",&y[i]);
	sort(x+1,x+n+1);
	sort(y+1,y+n+1);
	long long ans=0;
	for(i=1;i<=n;i++)
		if(x[i]+y[n-i+1]>t)
			ans+=x[i]+y[n-i+1]-t;
	cout<<ans<<endl;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}
