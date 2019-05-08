#include<stdio.h>
#include<string.h>
typedef long long ll;
int mod;
struct mat{
    int r,c;
    ll m[3][3];
};

mat MatMul(mat m1,mat m2){
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

mat MatQP(mat a,int n){
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
	int T;
	scanf("%d",&T);
	int x,y,n,m;
	mat t;
	t.r=2;t.c=2;
	t.m[1][1]=t.m[2][1]=1;
	t.m[1][2]=1;
	t.m[2][2]=0;
	while(T--){
		scanf("%d%d%d%d",&x,&y,&n,&m);
		int i;
		mod=1;
		for(i=1;i<=m;i++)mod*=10;
		if(n==0)printf("%d\n",((x%mod)+mod)%mod);
		else{
			mat a;
			a.r=2;a.c=1;
			a.m[1][1]=y;
			a.m[2][1]=x;
			mat tmp=MatQP(t,n-1);
			a=MatMul(tmp,a);
			printf("%lld\n",((a.m[1][1]%mod)+mod)%mod);
		}
	}
	return 0;
}
