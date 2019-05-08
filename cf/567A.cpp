#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int a[100005];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int maxx=0;
		int minn=0x7fffffff;
		if(i-1>=1)minn=min(minn,a[i]-a[i-1]);
		if(i+1<=n)minn=min(minn,a[i+1]-a[i]);
		if(i!=1)maxx=max(maxx,a[i]-a[1]);
		if(i!=n)maxx=max(maxx,a[n]-a[i]);
		printf("%d %d\n",minn,maxx);
	}
	return 0;
}
