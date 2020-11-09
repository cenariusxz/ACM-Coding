#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

struct mat{
    int r,c;
    ll m[34][34];
    mat(){}
    mat(int r,int c):r(r),c(c){}
}ans, T;

void clear(mat &a){
    memset(a.m,0,sizeof(a.m));
}

mat mul(mat a,mat b){
    mat tmp(a.r,b.c);
    int i,j,k;
    for(i=0;i<tmp.r;i++){
        for(j=0;j<tmp.c;j++){
            tmp.m[i][j]=0;
            for(k=0;k<a.c;k++){
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
    for(int i=0;i<ans.r;i++){
        ans.m[i][i]=1;
    }
    while(n){
        if(n&1)ans=mul(ans,tmp);
        n>>=1;
        tmp=mul(tmp,tmp);
    }
    return ans;
}

int n, m, bit[10], nxt[10];

void dfs(int t, int id){
	if(t == m-1){
		int tmp = 0;
		for(int i = 0 ; i < m ; ++ i)tmp = tmp * 2 + nxt[i];
		T.m[id][tmp] ++;
		return;
	}
	if(bit[t+1] == 1){
		nxt[t+1] = 0;
		dfs(t+1, id);
		return;
	}
	nxt[t+1] = 0;
	dfs(t+1, id);
	if(t+2 < m && bit[t+2] == 0){
		nxt[t+1] = nxt[t+2] = 1;
		dfs(t+2, id);
		nxt[t+1] = nxt[t+2] = 0;
	}
}

int main(){
	scanf("%d%d", &n, &m);
	T.r = T.c = ans.r = (1<<m);
	ans.c = 1;
	for(int i = 0 ; i < (1 << m) ; ++ i){
		for(int p = 0 ; p < m ; ++ p){
			if(i & (1 << p))bit[p] = 1;
			else bit[p] = 0;
		}
		dfs(-1, i);
	}
	ans.m[0][0] = 1;
	mat res = mul(ans, QP(T, n));
	printf("%lld\n", res.m[0][0]);
    return 0;
}
