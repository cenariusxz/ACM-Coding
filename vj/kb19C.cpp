#include<stdio.h>
#include<string.h>
typedef long long ll;
int mod;
struct mat{
	int r,c;
	ll m[5][5];
	void clear(){
		for(int i=1;i<=r;i++)memset(m[i],0,sizeof(m[i]));
	}
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
	mat a;
	a.r=3;a.c=1;
	a.m[1][1]=0;
	a.m[2][1]=1;
	a.m[3][1]=1;
	mat t;
	t.r=3;
	t.c=3;
	t.clear();
	t.m[1][1]=4;
	t.m[1][3]=2;
	t.m[2][1]=8;
	t.m[2][3]=5;
	t.m[3][3]=1;
	int n;
	while(scanf("%d%d",&n,&mod)!=EOF){
		mat tmp=MatQP(t,n/2);
		tmp=MatMul(tmp,a);
		printf("%lld\n",tmp.m[n%2+1][1]);
	}
	return 0;
}
