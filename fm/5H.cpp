#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

inline int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int num[15];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		n--;
		for(int i=1;i<=m;++i){
			scanf("%d",&num[i]);
			if(!num[i]){
				i--;
				m--;
			}
		}
		ll ans=0;
		for(int i=1;i<(1<<m);++i){
			int bit=0;
			int tmp=1;
			for(int j=1;j<=m;++j){
				if(i&(1<<(j-1))){
					bit++;
					tmp=tmp/gcd(tmp,num[j])*num[j];
				}
			}
			if(bit%2)ans+=n/tmp;
			else ans-=n/tmp;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
