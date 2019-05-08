#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=1e6+5;

int a[maxn];

int main(){
	int x,n;
	while(scanf("%d",&x)!=EOF){
		scanf("%d",&n);
		x*=10000000;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int pos1=1,pos2=n;
		int ans1=-1,ans2=x+1;
		while(pos1<pos2){
			ll s=a[pos1]+(ll)a[pos2];
			if(s==x){
				ans1=a[pos1];
				ans2=a[pos2];
				break;
			}
			else if(s>x)pos2--;
			else if(s<x)pos1++;
		}
		if(ans1==-1)printf("danger\n");
		else printf("yes %d %d\n",ans1,ans2);
	}
	return 0;
}
