#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=2e5+5;

struct peo{
	int x,y;
}p[maxn];

bool cmp1(peo a,peo b){
	return a.x<b.x;
}
bool cmp2(peo a,peo b){
	if(a.y==b.y)return a.x<b.x;
	return a.y<b.y;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	sort(p+1,p+n+1,cmp1);
	ll ans1=0,ans2=0,ans=0;
	ll cnt=1;
	for(int i=2;i<=n;++i){
		if(p[i].x==p[i-1].x)cnt++;
		else{
			ans1+=(cnt-1)*cnt/2;
			cnt=1;
		}
	}
	ans1+=(cnt-1)*cnt/2;
	cnt=1;
	sort(p+1,p+n+1,cmp2);
	for(int i=2;i<=n;++i){
		if(p[i].y==p[i-1].y)cnt++;
		else{
			ans2+=(cnt-1)*cnt/2;
			cnt=1;
		}
	}
	ans2+=(cnt-1)*cnt/2;
	cnt=1;
	ans=ans1+ans2;
	ans1=0;
	for(int i=2;i<=n;++i){
		if(p[i].x==p[i-1].x&&p[i].y==p[i-1].y)cnt++;
		else{
			ans1+=(cnt-1)*cnt/2;
			cnt=1;
		}
	}
	ans1+=(cnt-1)*cnt/2;
	ans-=ans1;
	printf("%I64d\n",ans);
	return 0;
}
