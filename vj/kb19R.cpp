#include<stdio.h>
#include<string.h>
typedef long long ll;
const int mod=1000000007;
const int mmod=1000000006;
struct mat{
    int r,c;
    ll m[5][5];
	void clear(){
		for(int i=1;i<=r;i++)memset(m[i],0,sizeof(m[i]));
	}
};

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

mat MatMul(mat &m1,mat &m2){
    mat tmp;
    tmp.r=m1.r;
    tmp.c=m2.c;
    int i,j,k;
    for(i=1;i<=tmp.r;i++){
        for(j=1;j<=tmp.c;j++){
            ll t=0;
            for(k=1;k<=m1.c;k++){
                t=(t+(m1.m[i][k]*m2.m[k][j])%mmod)%mmod;
            }
            tmp.m[i][j]=t;
        }
    }
    return tmp;
}

mat MatQP(mat &a,int n){
    mat ans,tmp=a;
    ans.r=ans.c=a.r;
    memset(ans.m,0,sizeof(ans.m));
    for(int i=1;i<=ans.r;i++){
        ans.m[i][i]=1;
    }
    while(n){
        if(n&1)ans=MatMul(ans,tmp);
        n>>=1;
        tmp=MatMul(tmp,tmp);
    }
    return ans;
}

ll QP(ll a,ll n){
    ll tmp=a,ans=1;
    while(n){
        if(n&1)ans=ans*tmp%mod;
        tmp=tmp*tmp%mod;
        n>>=1;
    }
    return ans%mod;
}

int main(){
	int x,y,n;
	mat t,tmp;
	t.r=2;t.c=2;
	t.clear();
	t.m[1][2]=t.m[2][1]=t.m[2][2]=1;
	mat a;
	a.r=2;
	a.c=1;
	a.m[1][1]=0;
	a.m[2][1]=1;
	ll ans;
	while(scanf("%d%d%d",&x,&y,&n)!=EOF){
		if(n==0)printf("%d\n",x);
		else{
			tmp=MatQP(t,n-1);
			tmp=MatMul(tmp,a);
			ans=QP(x,tmp.m[1][1])*QP(y,tmp.m[2][1])%mod;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
