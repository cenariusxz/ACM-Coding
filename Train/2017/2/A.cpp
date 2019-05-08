#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

int n,m;
int pnum[2200];
int num[2200];
int bit[2200];
int cnt=0;

void init(){
	cnt=0;
	for(int i=1;i<=2016;++i){
		if(2016%i==0)num[++cnt]=i;
	}
}

ll get(int tmp){
	int c=0;
	ll ans=0;
	for(int i=2;i*(ll)i<=tmp;++i){
		if(!(tmp%i)){
			pnum[++c]=i;
			while(!(tmp%i))tmp/=i;
		}
	}
	if(tmp>1)pnum[++c]=tmp;
	for(int i=1;i<(1<<c);++i){
		int bit=0;
		int mul=1;
		for(int j=1;j<=c;++j){
			if(i&(1<<(j-1))){
				bit++;
				mul*=pnum[j];
			}
		}
		if(bit%2)ans+=n/mul;
		else ans-=n/mul;
	}
	return ans;
}

int main(){
	init();
	while(scanf("%d%d",&n,&m)!=EOF){
//		printf("%lld\n",get(2016));
		if(n>m)swap(n,m);
		ll ans=0;
		for(int i=1;i<=cnt;++i){
			int tmp=2016/num[i];
			ll sum=get(tmp);
			int tmp2=2016/tmp;
			ll s2=m/tmp2;
			printf("%d %lld %d %lld\n",tmp,sum,tmp2,s2);
			ans+=sum*s2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
