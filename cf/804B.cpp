#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
 
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
 
ll num[maxn];
char s[maxn];
 
void init(){
	num[1]=1;
	for(int i=2;i<maxn;++i){
		num[i]=2*num[i-1]%mod+1;
		if(num[i]>=mod)num[i]-=mod;
	}
}
 
int main(){
	init();
	scanf("%s",s);
	int cnt=0;
	ll ans=0;
	for(int i=0;s[i];++i){
		if(s[i]=='a')cnt++;
		else{
			ans+=num[cnt];
			if(ans>=mod)ans-=mod;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
