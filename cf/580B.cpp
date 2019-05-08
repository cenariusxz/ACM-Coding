#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;

struct peo{
	int m;
	ll f;
	bool operator < (const peo a)const{
		return m<a.m;
	}
}p[maxn];

int main(){
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;++i){
		scanf("%d%I64d",&p[i].m,&p[i].f);
	}
	sort(p+1,p+n+1);
	int pre=1;
	ll tmp=p[1].f;
	ll maxx=p[1].f;
	int minn=p[1].m;
	for(int i=2;i<=n;++i){
		if(p[i].m>=minn+d){
			while(pre<=i){
				minn=p[pre].m;
				if(p[i].m<minn+d){
					break;
				}
				tmp-=p[pre].f;
				pre++;
			}
		}
		tmp+=p[i].f;
		if(tmp>maxx)maxx=tmp;
	}
	printf("%I64d\n",maxx);
	return 0;
}
