#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long LL;
const int Maxn=100010;
const LL MOD=998244353;
LL Q[Maxn],P[Maxn];
LL num[Maxn];
LL GetQ(LL x)
{
    LL ans=(LL)x*x*3-x;
    return (ans/2)%MOD;
}
void _init()
{
    Q[0]=0;
    for(int i=1;i<Maxn;i++)
    {
        if(i&1) Q[i]=GetQ(i/2+1);
        else Q[i]=GetQ(i/2*(-1));
    }
    P[0]=P[1]=1;
    for(int i=2;i<Maxn;i++)
    {
        for(int j=1;;j++)
        {
            if(Q[j]>i) break;
            int t=j;
            if(t&1) t=t/2+1;
            else t=t/2;
            if(t&1)
                P[i]=(P[i]+P[i-Q[j]]);
            else
                P[i]=(P[i]-P[i-Q[j]]);
            if(P[i]>=MOD) P[i]%=MOD;
            if(P[i]<0) P[i]+=MOD;
        }
    }
}
LL solved(LL n,LL k)
{
    LL ans=0;
    for(int i=0;;i++)
    {
        if(Q[i]*k>n) break;
        int t=i;
        if(t&1) t=t/2+1;
        else t=t/2;
        if(t&1) ans=(ans-P[n-Q[i]*k]);
        else ans=(ans+P[n-Q[i]*k]);
        if(ans>=MOD) ans%=MOD;
        if(ans<0) ans+=MOD;
    }
	return ans;
}

void init()
{
    _init();
    LL k=2;
	num[0]=1;
    for(int i=1;i<=100001;i++){
        num[i]=num[i-1]+solved(i,k);
	}
}

int main(){
	init();
	int T;
	while(scanf("%d",&T)!=EOF){
		while(T--){
			int n,c,l,r;
			scanf("%d%d%d%d",&n,&c,&l,&r);
			l-=c;
			r-=c;
			if(l==0)printf("%lld\n",num[r]%MOD);
			else printf("%lld\n",(num[r]-num[l-1])%MOD);
		}
	}
	return 0;
}
