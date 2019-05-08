#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;
const int mod = 1e9 + 7;
const int MAXN = 5010;

int fac[MAXN],afac[MAXN];

int Q_pow(int x,int y){
	int res = 1;
	while(y){
		if(y & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return res % mod;
}

void Pre(){
	fac[0] = afac[0] = 1;
	for(int i = 1; i <= 5000; ++i)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	afac[5000] = Q_pow(fac[5000],mod - 2);
	for(int i = 5000; i > 1; --i){
		afac[i - 1] = 1ll * afac[i] * i % mod;
	}
}

int Comb(int n,int m){
	if(n == 0 || m == 0) return 1;
	return 1ll * fac[n] * afac[n - m] % mod * afac[m] % mod;
}

int n,t;
int A[MAXN];
int num[MAXN],sum[MAXN];

int main(){
	Pre();
	while(scanf("%d%d",&n,&t) != EOF){
		memset(num,0,sizeof(num));
		for(int i = 1; i <= n; ++i){
			scanf("%d",&A[i]);
			num[A[i]]++;
		}
		sum[0] = 0;
		for(int i = 1; i <= 5000; ++i){
			sum[i] = sum[i - 1] + num[i];
		}
		int ans = 0;
		int x,pos,Q1,Q2;
		scanf("%d%d",&x,&pos);
		int val = A[x];
		Q1 = pos - 1;
		Q2 = t - pos;
		for(int i = 1; i <= num[val]; ++i){
			int rem = i - 1;
			int base = Comb(num[val] - 1,rem);
			for(int j = 0; j <= rem; ++j){
				// j 个放前面
				int tj = rem - j;
				int front = sum[val - 1];
				int rear = n - sum[val];
				if(j + front < Q1) continue;
				if(j > Q1) continue;
				if(tj + rear < Q2) continue;
				if(tj > Q2) continue;
				ans = (ans + 1ll * base * Comb(front,Q1 - j) % mod
						* Comb(rear,Q2 - tj) % mod) % mod;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
