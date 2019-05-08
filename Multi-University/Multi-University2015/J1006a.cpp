#include<stdio.h>
#include<string.h>
#include<math.h>
typedef long long ll;
const int mod=2015;

struct mat{
    int r,c;
    int m[51][51];        //经测试最大开成590*590的 ll 型矩阵
    mat(){}
    mat(int r,int c):r(r),c(c){}
};

void clear(mat a){
    memset(a.m,0,sizeof(a.m));
}

mat mul(mat b,mat a){
    mat tmp(b.r,a.c);
    int i,j,k;
    for(i=1;i<=tmp.r;i++){
        for(j=1;j<=tmp.c;j++){
            tmp.m[i][j]=0;
            for(k=1;k<=c;k++){
                tmp.m[i][j]=(tmp.m[i][j]+(b.m[i][k]*a.m[k][j])%mod)%mod;
            }
        }
    }
    return tmp;
}

mat QP(mat a,int n){
    mat ans(a.r,a.r),tmp(a.r,a.r);
    memcpy(tmp.m,a.m,sizeof(tmp.m));
    ans.clear();
    for(int i=1;i<=ans.r;i++){
        ans.m[i][i]=1;
    }
    while(n){
        if(n&1)ans=mul(ans,tmp);
        n>>=1;
        tmp=mul(tmp,tmp);
    }
    return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		mat a(n+1,n+1);

	}
}
