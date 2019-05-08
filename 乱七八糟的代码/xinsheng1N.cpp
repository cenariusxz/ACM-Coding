#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=5e5+5;
typedef long long ll;

char ss[7]={'I','E','A','O','U','Y'};
char s[maxn];

int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	ll sum=0;
	for(int i=1;s[i];++i){
		for(int j=0;j<6;++j)if(s[i]==ss[j])sum++;
	}
	double ans=0;
	ll tmp=0;
	for(int i=1;s[i]&&i<=n-i+1;++i){
		tmp+=sum;
		ans+=tmp*1.0/i;
		if(i!=n-i+1)ans+=tmp*1.0/(n-i+1);
		for(int j=0;j<6;++j){
			if(s[i]==ss[j])sum--;
			if(s[n-i+1]==ss[j])sum--;
		}
	}
	printf("%.7lf\n",ans);
	return 0;
}
