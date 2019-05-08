#include<stdio.h>
#include<string.h>
#define ll long long
const ll MAXM=100000;

struct app{
	ll a,b;
}p[MAXM+5];

int num[MAXM+5];

int main(){
	ll n,m,k;
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	ll i,t;
	for(i=1;i<=n;i++){
		scanf("%I64d",&t);
		p[t].a=(i-1)/k;
		p[t].b=i-p[t].a*k;
		num[i]=t;
	}
	ll ans=0;
	for(i=1;i<=m;i++){
		scanf("%I64d",&t);
		ans+=p[t].a+1;
		ll q=p[t].a*k+p[t].b;
		if(q-1){
			ll a1=t,a2=num[q-1];
			app tmp=p[a1];
			p[a1]=p[a2];
			p[a2]=tmp;
			num[q]=a2;
			num[q-1]=a1;
		}
	}
	printf("%I64d\n",ans);
}
