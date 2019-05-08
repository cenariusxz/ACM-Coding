#include<stdio.h>
#include<string.h>
#include<math.h>
typedef long long ll;
const int mod=1e9+7;

struct mat{
    int r,c;
    ll m[4][4];
    mat(){}
    mat(int r,int c):r(r),c(c){}
};

void clear(mat &a){
    memset(a.m,0,sizeof(a.m));
}

mat mul(mat a,mat b){
    mat tmp(a.r,b.c);
    int i,j,k;
    for(i=1;i<=tmp.r;i++){
        for(j=1;j<=tmp.c;j++){
            tmp.m[i][j]=0;
            for(k=1;k<=a.c;k++){
                tmp.m[i][j]=(tmp.m[i][j]+(a.m[i][k]*b.m[k][j])%mod)%mod;
            }
        }
    }
    return tmp;
}

mat QP(mat a,int n){
    mat ans(a.r,a.r),tmp(a.r,a.r);
    memcpy(tmp.m,a.m,sizeof(tmp.m));
    clear(ans);
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

int n,m;

int main(){
    scanf("%d%d",&n,&m);
    if(m == 1){
        if(n == 0)printf("1\n");
        else printf("0\n");
        return 0;
    }
    mat M(2,2), T(2,1);
    M.m[1][1] = m-2;
    M.m[1][2] = 1;
    M.m[2][1] = m-1;
    M.m[2][2] = 0;
    T.m[1][1] = 0;
    T.m[2][1] = 1;
    mat ans = mul(QP(M,n), T);
    printf("%lld\n",ans.m[2][1]);
    return 0;
}
