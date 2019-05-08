#include<stdio.h>
#include<string.h>
const int mod=1e9+7;
typedef long long ll;

int read(){
	char c;
	int x=0;
	c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

ll c[105],a[105];
bool vis[105];

void init(){
	int i;
	c[1]=0;
	c[2]=1;
	a[1]=1;
	a[2]=2;
	for(i=3;i<=102;i++){
		c[i]=(a[i-2]*(i*(i-1)/2)*(i*(i-1)/2))%mod;
		a[i-1]=(a[i-2]*(i-1)%mod);
	}
}

int main(){
	init();
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,j,k;
		ll tmp1=0,tmp2,ans=0,tmp,tmp3;
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++){
			int b=read();
			tmp2=0;
			tmp=tmp1;
			for(j=1;j<b;j++){
				if(!vis[j]){
					tmp2++;
					tmp3=0;/*
					for(k=j+1;k<=n;k++){
						if(vis[k])tmp++;
					}*/
					for(k=1;k<j;k++){
						if(!vis[k])tmp3++;
					}
					ans=(ans+tmp*a[n-i]%mod)%mod;
					ans=(ans+tmp3*a[n-i]%mod)%mod;
				}
			}
			ans=(ans+tmp2*c[n-i]%mod)%mod;
			for(j=1;j<b;j++){
				if(!vis[j])tmp1++;
			}
			vis[b]=1;
	//		if(i==1)printf("%lld\n",tmp1);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
