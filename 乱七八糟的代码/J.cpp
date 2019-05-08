#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1000010;
const int R = 1e6 - 1;
const int mod = 1e9 + 7;

int T,N;
int a_two,a_six,a_four;
int tsum[4][MAXN << 2],add[4][MAXN << 2];

int Q_pow(int x,int y){
	int res = 1;
	while(y){
		if(y & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return res;
}

inline int Cal(int id,int l,int r,int c){
	if(id == 0){
		return 1ll * (r - l + 1) * c % mod;
	}
	if(id == 1){
		return 1ll * c * (l + r) % mod * (r - l + 1) % mod
			* a_two % mod;
	}
	if(id == 2){
		int sr = 1ll * r * (r + 1) % mod * (r + r + 1) % mod
			* a_six % mod;
		int sl = 1ll * (l - 1) * l % mod * (l + l - 1) % mod
			* a_six % mod;
		return 1ll * c * (sr - sl) % mod;
	}
	if(id == 3){
		int sr = 1ll * r * r % mod * (r + 1) % mod * (r + 1) % mod
			* a_four % mod;
		int sl = 1ll * l * l % mod * (l - 1) % mod * (l - 1) % mod
			* a_four % mod;
		return 1ll * c * (sr - sl) % mod;
	}
}

inline void Push_down(int id,int p,int l,int mid,int r){
	if(add[id][p]){
		add[id][p << 1] = (1ll * add[id][p << 1] + add[id][p]) % mod;
		tsum[id][p << 1] = (1ll * tsum[id][p << 1] + Cal(id,l,mid,add[id][p])) % mod;

		add[id][p << 1|1] = (1ll * add[id][p << 1|1] + add[id][p]) % mod;
		tsum[id][p << 1|1] = (1ll * tsum[id][p << 1|1] + Cal(id,mid + 1,r,add[id][p])) % mod;

		add[id][p] = 0;
	}
}

void Update(int id,int a,int b,int c,int p,int l,int r){
	if(a <= l && r <= b){
		add[id][p] = (1ll * add[id][p] + c) % mod;
		tsum[id][p] = (1ll * tsum[id][p] + Cal(id,l,r,c)) % mod;
		return;
	}
	int mid = (l + r) >> 1;
	Push_down(id,p,l,mid,r);
	if(a <= mid) Update(id,a,b,c,p << 1,l,mid);
	if(b > mid) Update(id,a,b,c,p << 1|1,mid + 1,r);
	tsum[id][p] = (1ll * tsum[id][p << 1] + tsum[id][p << 1|1]) % mod;
}

int Query(int id,int a,int b,int p,int l,int r){
	if(a <= l && r <= b){
		return tsum[id][p];
	}
	int mid = (l + r) >> 1;
	Push_down(id,p,l,mid,r);
	int res = 0;
	if(a <= mid) res = (1ll * res + Query(id,a,b,p << 1,l,mid)) % mod;
	if(b > mid) res = (1ll * res + Query(id,a,b,p << 1|1,mid + 1,r)) % mod;
	return res;
}

inline void Solve(int l,int r,int a,int b,int c,int d){
	Update(3,l,r,a,1,0,R);
	Update(2,l,r,b,1,0,R);
	Update(1,l,r,c,1,0,R);
	Update(0,l,r,d,1,0,R);
}

void Init(){
	memset(tsum,0,sizeof(tsum));
	memset(add,0,sizeof(add));
}

int main(){
	a_two = Q_pow(2,mod - 2);
	a_four = Q_pow(4,mod - 2);
	a_six = Q_pow(6,mod - 2);
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		Init();
		printf("Case #%d:\n",tt);
		scanf("%d",&N);
		for(int i = 1; i <= N; ++i){
			char s[5];
			int X1,X2,a,b,c,d;
			scanf("%s%d%d%d%d%d%d",s,&X1,&X2,&a,&b,&c,&d);
			if(s[0] == 'p'){
				Solve(X1,X2,a,b,c,d);
			}
			else{
				int E = 0;
				for(int i = 0; i < 4; ++i){
					E = (1ll * E + Query(i,X1,X2,1,0,R)) % mod;
				}
				if(E < 0) E += mod;
				printf("%d\n",E);
				int r1 = 1ll * E * X1 % 1000000;
				int r2 = 1ll * E * X2 % 1000000;
				if(r1 > r2) swap(r1,r2);
				Solve(r1,r2,a,b,c,d);
			}
		}
	}
	return 0;
}

