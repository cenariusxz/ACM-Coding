#include<stdio.h>
#include<string.h>
#include<math.h>
typedef long long ll;
int mod;
int n,d,k;

ll t[550],tmp[550],ans[550];

void Mul(ll a[],ll b[]){
	memset(t,0,sizeof(t));
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			int c=(j+i-1)%n;
			if(c==0)c=n;
			t[i]+=((a[j]*b[c])%mod);
		}
	}
	for(i=1;i<=n;i++){
		b[i]=t[i]%mod;
	}
}

int main(){
	while(scanf("%d%d%d%d",&n,&mod,&d,&k)!=EOF){
		int i,j;
		memset(tmp,0,sizeof(tmp));
		for(j=1-d;j<=1+d;j++){
			int t=(j+n)%n;
			if(t==0)t=n;
			tmp[t]=1;
		}
		for(i=1;i<=n;i++)scanf("%lld",&ans[i]);
		while(k){
			if(k&1)Mul(tmp,ans);
			k>>=1;
			Mul(tmp,tmp);
		}
		for(i=1;i<=n;i++){
			printf("%lld",ans[i]);
			if(i==n)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
