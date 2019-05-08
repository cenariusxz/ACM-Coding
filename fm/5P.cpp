#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=4e5+5;

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}

int ori[1005],cha[1005];
int pnum[50],num;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		int cnt=0;
		while(m--){
			int f;
			scanf("%d",&f);
			if(f==1){
				int x,y,p;
				scanf("%d%d%d",&x,&y,&p);
				int tmp=p;
				num=0;
				for(int i=2;i*i<=tmp;++i){
					if(!(tmp%i)){
						pnum[++num]=i;
						tmp/=i;
						while(!(tmp%i))tmp/=i;
					}
				}
				if(tmp>1)pnum[++num]=tmp;
				ll ans=0;
				for(int i=1;i<(1<<num);++i){
					int bit=0;
					ll mul=1;
					for(int j=1;j<=num;++j){
						if(i&(1<<(j-1))){
							bit++;
							mul*=pnum[j];
						}
					}
					ll tmp=y/mul-(x-1)/mul;
					ll l=((x-1)/mul+1)*mul,r=y/mul*mul;
					tmp=(l+r)*tmp/2;
					if(bit%2)ans+=tmp;
					else ans-=tmp;
				}
				ans=(x+y)*(ll)(y-x+1)/2-ans;
				for(int i=1;i<=cnt;++i){
					if(ori[i]>=x&&ori[i]<=y){
						int gcd1=gcd(ori[i],p),gcd2=gcd(cha[i],p);
						if(gcd1==1&&gcd2>1)ans-=ori[i];
						else if(gcd1>1&&gcd2==1)ans+=cha[i];
						else if(gcd1==1&&gcd2==1)ans=ans-ori[i]+cha[i];
					}
				}
				printf("%lld\n",ans);
			}
			else{
				int x,c;
				scanf("%d%d",&x,&c);
				bool f=1;
				for(int i=1;i<=cnt;++i){
					if(ori[i]==x){
						cha[i]=c;
						f=0;
						break;
					}
				}
				if(f){
					++cnt;
					ori[cnt]=x;
					cha[cnt]=c;
				}
			}
		}
	}
	return 0;
}
