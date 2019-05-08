#include<stdio.h>
#include<string.h>
#include<math.h>
#define ll long long
const ll MAXM=50000;
const ll INF=0x3F3F3F3F;
ll a[MAXM*4+5],b[MAXM*4+5][2];
ll c[MAXM*4+5][2];

int main(){
	ll n,w,h;
	while(scanf("%I64d%I64d%I64d",&n,&w,&h)!=EOF){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		ll i,sum=0,ans=INF,cnt=0,j;
		for(i=w+1;i<=n+w;i++){
			scanf("%I64d",&a[i]);
			sum+=a[i];
		}
		if(sum<w*h)ans=-1;
		else{
			ll tmp;
			for(i=1;i<=w+w+n;i++){
				tmp=a[i]-h;
				if(tmp>0)c[i][0]=tmp;
				else c[i][1]=-tmp;
			}/*
			for(i=1;i<=w+n+w;i++){
				printf("%d %d\n",c[i][0],c[i][1]);
			}*/
			for(i=1;i<=w;i++){
				b[w][0]+=c[i][0];
				b[w][1]+=c[i][1];
			}
			ans=(b[w][0]>b[w][1]?b[w][0]:b[w][1]);
		//	printf("%lld %lld\n",b[w][0],b[w][1]);
			for(i=w+1;i<=n+w+w;i++){
				b[i][0]=b[i-1][0]-c[i-w][0];
				b[i][0]+=c[i][0];
				b[i][1]=b[i-1][1]-c[i-w][1];
				b[i][1]+=c[i][1];
				ll tmp=b[i][0]>b[i][1]?b[i][0]:b[i][1];
				if(tmp<ans)ans=tmp;
			}/*
			printf("\n");
			for(i=w;i<=w+n+w;i++){
				printf("%lld %lld\n",b[i][0],b[i][1]);
			}*/
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
