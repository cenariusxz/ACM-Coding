#include<stdio.h>
typedef long long ll;
const int maxn=1e5+5;

ll a[maxn],s[maxn];

int main(){
	int T,n,m,l,r;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%I64d",&a[i]);
		for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
		while(m--){
			scanf("%d%d",&l,&r);
			printf("%I64d\n",s[r]-s[l-1]);
		}
	}
	return 0;
}
