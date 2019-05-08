#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=2e5+5;
const int mod=1e9+7;
const int maxm=1<<16;

int n,d;

ll tmp[maxm],s[maxm],p[maxm],ans[maxn];
int a[maxn];

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*2+c-'0';
		c=getchar();
	}
	return x;
}

int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;++i)a[i]=read();
	int l=(int)sqrt(d*(2<<(d+1)));
	int cnt=0;
	int pre=1;
//	for(int i=1;i<=n;++i)printf("%d ",a[i]);
//	printf("\n");
//	printf("%d\n",l);
	for(int i=1;i<=n;++i){
		ll num=s[a[i]]+1;
		for(int j=pre;j<i;++j){
			if(!(a[j]&(~a[i]))){
				num+=ans[j];
				if(num>mod)num-=mod;
			}
		}
		ans[i]=num;
//		printf("%lld\n",ans[i]);
		tmp[a[i]]+=num;
		if(p[a[i]]>mod)p[a[i]]-=mod;
		cnt=(cnt+1)%l;
		if(!cnt){
			for(int j=0;j<(1<<d);++j){
				p[j]+=tmp[j];
				if(p[j]>=mod)p[j]-=mod;
			}
			memset(tmp,0,sizeof(tmp));
			for(int j=0;j<(1<<d);++j)s[j]=p[j];
			for(int k=0;k<=d-1;++k){
				for(int j=0;j<(1<<d);++j){
					if(!(j&(1<<k))){
						s[j+(1<<k)]+=s[j];
						if(s[j+(1<<k)]>=mod)s[j+(1<<k)]-=mod;
					}
				}
			}
		}
	}
	for(int j=0;j<(1<<d);++j){
		p[j]+=tmp[j];
		if(p[j]>=mod)p[j]-=mod;
	}
	ll res=0;
	for(int i=0;i<(1<<d);++i){
		res+=p[i];
		if(res>=mod)res-=mod;
	}
	printf("%lld\n",res);
	return 0;
}
