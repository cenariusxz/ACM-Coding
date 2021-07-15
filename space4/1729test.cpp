#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=2000,maxl=1000,MOD=1e9+7;
 
int n,m,R,X[maxn+5],Y[maxn+5],w[maxn+5],sum[maxl+5][maxl+5];
int S[maxn+5],C[maxn+5][maxn+5],ans;
 
inline int abs(int x) {return x<0?-x:x;}
inline bool check(int i,int j) {return max(abs(X[i]-X[j]),abs(Y[i]-Y[j]))<=R;}
#define ADD(x,y) (((x)+(y))%MOD)
#define MUL(x,y) ((LL)(x)*(y)%MOD)
int Count(int i,int j){
    int A=max(X[i]-R,X[j]-R),B=min(X[i]+R,X[j]+R);
    int C=max(Y[i]-R,Y[j]-R),D=min(Y[i]+R,Y[j]+R);
    if (A<1) A=1;if (B>maxl) B=maxl;
    if (C<1) C=1;if (D>maxl) D=maxl;
    if (A>B || C>D) return 0;
    return sum[B][D]-sum[A-1][D]-sum[B][C-1]+sum[A-1][C-1];
}
int main(){
    scanf("%d%d%d",&n,&m,&R);
    for (int i=1;i<=n;i++) scanf("%d%d%d",&X[i],&Y[i],&w[i]),sum[X[i]][Y[i]]++;
    for (int i=1;i<=maxl;i++) for (int j=1;j<=maxl;j++) sum[i][j]+=sum[i][j-1];
    for (int i=1;i<=maxl;i++) for (int j=1;j<=maxl;j++) sum[i][j]+=sum[i-1][j];
    for (int i=0;i<=n;i++) C[i][0]=1;
    for (int i=1;i<=n;i++) for (int j=1;j<=i;j++) C[i][j]=ADD(C[i-1][j-1],C[i-1][j]);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) S[i]+=check(i,j);
        int cnt=ADD(C[n][m],MOD-C[n-S[i]][m]);
        ans=ADD(ans,MUL(cnt,MUL(w[i],w[i])));
    }
    printf("%d\n",ans);
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++){
            int T=Count(i,j),A=S[i]-T,B=S[j]-T,N=n-(A+B+T);
            printf("%d\n", T);
            int cnt=ADD(C[n][m],C[N][m]);
            cnt=ADD(cnt,MOD-ADD(C[A+N][m],C[B+N][m]));
            ans=ADD(ans,MUL(cnt<<1,MUL(w[i],w[j])));
        }
    printf("%d\n",ans);return 0;
}
