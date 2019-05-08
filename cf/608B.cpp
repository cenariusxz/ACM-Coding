#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<bitset>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=2e5+5;

char s1[maxn],s2[maxn];

int main(){
	scanf("%s%s",s1,s2);
	int n1=strlen(s1),n2=strlen(s2);
	ll ans=0;
	ll pre=0;
	for(int i=0;i<=n2-n1;++i)if(s2[i]=='1')pre++;
	if(s1[0]=='0')ans=pre;
	else ans=n2-n1+1-pre;
	for(int i=1;i<n1;++i){
		if(s2[i-1]=='1')pre--;
		if(s2[i+n2-n1]=='1')pre++;
		if(s1[i]=='0')ans+=pre;
		else ans+=n2-n1+1-pre;
	}
	printf("%I64d\n",ans);
	return 0;
}
