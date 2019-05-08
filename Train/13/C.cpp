#include <bits/stdc++.h>
using namespace std;
struct node{
	int c,d;
}a[510];
int n,m;

bool cmp(const node& x,const node& y)
{
	return x.c<y.c;
}

void fuck()
{
	int i,ans=n+1;
	for(i=1;i<=m;i++){
		scanf("%d%d",&a[i].c,&a[i].d);
		if(a[i].c>a[i].d){
			i--;m--;
		}
	}
	sort(a+1,a+m+1,cmp);
	int l=1,r=1;
	for(i=1;i<=m;i++){
		if(a[i].c>r){
			ans+=2*(r-l);
			l=a[i].c;
			r=a[i].d;
		}
		else{
			r=max(r,a[i].d);
		}
	}
	ans+=2*(r-l);
	printf("%d\n",ans);
}

int main()
{
	while(~scanf("%d%d",&n,&m))
		fuck();
 return 0;
}
