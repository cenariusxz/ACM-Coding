#include<stdio.h>
#include<string.h>
typedef long long ll;
const int maxm=100005;

int a[maxm];
ll c[37],sum[maxm];

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int main(){
	c[0]=1;
	for(int i=1;i<=35;++i)c[i]=c[i-1]*2;
	int T=read();
	while(T--){
		int n=read();
		int i;
		for(i=1;i<=n;++i)a[i]=read();
		ll ans=0;
		sum[n+1]=0;
		for(i=n;i>=1;--i){
			sum[i]=sum[i+1]+i;
			ans+=(ll)i*(n-i+1)+sum[i];
		}
		for(int k=1;k<=35;k++){
			ll s=0;
			int j=1;
			for(i=1;i<=n;++i){
				while(j<=n&&s<c[k])s+=a[j++];
				if(s>=c[k])ans+=(ll)i*(n-j+2)+sum[j-1];
				else break;
				s-=a[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;	
}
