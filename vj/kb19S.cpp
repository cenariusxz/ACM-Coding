#include<stdio.h>
#include<string.h>
typedef long long ll;
const int mod=1000000007;

struct mat{
    int r,c;
    ll m[590][590];
    void clear(){
        for(int i=1;i<=r;i++)memset(m[i],0,sizeof(m[i]));
    }
};

mat MatMul(mat &m1,mat &m2){
    mat tmp;
    tmp.r=m1.r;
    tmp.c=m2.c;
    int i,j,k;
    for(i=1;i<=tmp.r;i++){
        for(j=1;j<=tmp.c;j++){
            ll t=0;
            for(k=1;k<=m1.c;k++){
                t=(t+(m1.m[i][k]*m2.m[k][j])%mod)%mod;
            }
            tmp.m[i][j]=t;
        }
    }
    return tmp;
}

mat MatQP(mat &a,ll n){
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

int main(){
	ll n;
	mat a;
	a.r=5,a.c=1;
	mat tmp;
	tmp.c=tmp.r=5;
	ll a0,b0,ax,ay,bx,by;
	while(scanf("%lld",&n)!=EOF){
		scanf("%lld%lld%lld%lld%lld%lld",&a0,&ax,&ay,&b0,&bx,&by);
		a0%=mod;
		ax%=mod;
		ay%=mod;
		b0%=mod;
		bx%=mod;
		by%=mod;
		a.clear();
		a.m[1][1]=0;
		a.m[2][1]=(a0*b0)%mod;
		a.m[3][1]=b0;
		a.m[4][1]=a0;
		a.m[5][1]=1;
		tmp.clear();
		tmp.m[1][1]=tmp.m[1][2]=tmp.m[5][5]=1;
		tmp.m[2][2]=(ax*bx)%mod;
		tmp.m[2][3]=(ay*bx)%mod;
		tmp.m[2][4]=(ax*by)%mod;
		tmp.m[2][5]=(ay*by)%mod;
		tmp.m[3][3]=bx;
		tmp.m[3][5]=by;
		tmp.m[4][4]=ax;
		tmp.m[4][5]=ay;
//		tmp.m[1][3]=tmp.m[1][4]=tmp.m[1][5]=tmp.m[2][1]=tmp.m[3][1]=tmp.m[3][2]=tmp.m[3][4]=tmp.m[4][1]=tmp.m[4][2]=tmp.m[4][3]=tmp.m[5][1]=tmp.m[5][2]=tmp.m[5][3]=tmp.m[5][4]=0;
		tmp=MatQP(tmp,n%(mod-1));
		a=MatMul(tmp,a);
		printf("%lld\n",a.m[1][1]);
	}
    return 0;
}
