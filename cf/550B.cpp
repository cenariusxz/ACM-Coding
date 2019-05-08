#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int c[16],tmp[16];

int main(){
	int n,l,r,x;
	scanf("%d%d%d%d",&n,&l,&r,&x);
	int i,j;
	for(i=1;i<=n;i++)scanf("%d",&c[i]);
	int ans=0;
	for(i=3;i<1<<n;i++){
		int cnt=0,maxx=0,minn=0x3f3f3f3f,sum=0;
		for(j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				++cnt;
				if(c[j]>maxx)maxx=c[j];
				if(c[j]<minn)minn=c[j];
				sum+=c[j];
			}
		}
//		printf("%d %d %d %d\n",cnt,maxx,minn,sum);
		if(cnt<=1)continue;
		if(maxx-minn>=x&&sum>=l&&sum<=r)ans++;
	}
	printf("%d\n",ans);
}
