#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct mat{
    int r,c;
    ll m[45][45];
    mat(){}
    mat(int r,int c):r(r),c(c){}
};

void clear(mat &a){
    memset(a.m,0x3f,sizeof(a.m));
}

inline ll min(ll a, ll b){return a <= b ? a : b ;}

mat mul(mat a,mat b){
    mat tmp(a.r,b.c);
    clear(tmp);
    int i,j,k;
    for(i=0;i<tmp.r;i++){
        for(j=0;j<tmp.c;j++){
            for(k=0;k<a.c;k++){
                tmp.m[i][j]=min(tmp.m[i][j], a.m[i][k] + b.m[k][j]);
            }
        }
    }
    return tmp;
}

mat QP(mat a,int n){
    mat ans(a.r,a.r),tmp(a.r,a.r);
    memcpy(tmp.m,a.m,sizeof(tmp.m));
    clear(ans);
    for(int i=0;i<ans.r;i++){
        ans.m[i][i]=0;
    }
    while(n){
        if(n&1)ans=mul(ans,tmp);
        n>>=1;
        tmp=mul(tmp,tmp);
    }
    return ans;
}

void print(mat a){
    for(int i=0;i<a.r;++i){
        for(int j=0;j<a.c;++j){
            printf("%lld",a.m[i][j]);
            if(j==a.c-1)printf("\n");
            else printf(" ");
        }
    }
}

ll dp[25][25][45];
int n,m;
int a[25],b[25];

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&b[i]);
    memset(dp,0x3f,sizeof(dp));
    dp[1][0][n+1] = a[1];
    dp[1][1][n-1] = b[1];
    for(int i = 1 ; i < n ; ++ i){
        for(int j = 0 ; j <= n ; ++ j){
            for(int k = -i ; k <= i ; ++ k){
                dp[i+1][max(j,-(k+1))][n+k+1] = min(dp[i+1][max(j,-(k+1))][n+k+1], dp[i][j][n+k] + a[i+1]);
                dp[i+1][max(j,-(k-1))][n+k-1] = min(dp[i+1][max(j,-(k-1))][n+k-1], dp[i][j][n+k] + b[i+1]);
            }
        }
    }
    mat M(2*n,2*n), T(2*n,1);
    clear(M);
    clear(T);
    for(int i = 0 ; i < 2 * n ; ++ i){
        for(int j = 0 ; j < 2 * n ; ++ j){
            int p = i - j;
            if(abs(p) > n)continue;
            for(int k = 0 ; k <= j ; ++ k){
                M.m[i][j] = min(M.m[i][j], dp[n][k][n+p]);
            }
        }
    }
    T.m[0][0] = 0;
    mat ans = mul(QP(M,m), T);
    printf("%lld\n",ans.m[0][0]);
    return 0;
}
