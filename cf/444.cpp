#include<stdio.h>
#include<string.h>
typedef long long ll;

int s[10005];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int i,j;
		memset(s,0,sizeof(s));
		ll ans=0;
		for(i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			s[a]++;
			s[b]++;
		}
		for(i=1;i<=n;i++){
			ans+=(ll)s[i]*s[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
