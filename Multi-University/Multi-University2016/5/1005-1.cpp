#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=1e6+5;
const int mod=1e9+7;

char s[maxn];

bool check(int l,int r){
	while(l<r){
		if(s[l]!=s[r])return 0;
		l++;r--;
	}
	return 1;
}

int main(){
	while(scanf("%s",s+1)!=EOF){
		ll ans=0;
		int n=strlen(s+1);
		for(int i=1;i<n;++i){
			for(int j=i;j<n;++j){
				for(int k=j+1;k<=n;++k){
					if(check(i,j)==1&&check(j+1,k)==1)ans=(ans+i*(ll)k%mod)%mod;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
