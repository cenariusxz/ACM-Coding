#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Mx{
	ll a[2][2];
	void clear(){ memset(a,0,sizeof(a)); }
	void stand(){ clear(); for(int i = 0; i < 2; ++i) a[i][i] = 1;}
	Mx operator * (Mx b){
		Mx c; c.clear();
		for(int k = 0; k < 2; ++k)
		for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			c.a[i][j] += a[i][k] * b.a[k][j];
		return c;
	}
};

ll p,q,n;

Mx Q_pow(int v){
	Mx res; res.stand();
	Mx t; t.clear();
	t.a[0][0] = p,t.a[0][1] = -q;
	t.a[1][0] = 1;
	while(v){
		if(v & 1) res = res * t;
		t = t * t;
		v >>= 1;
	}
	return res;
}

int main(){
	while(scanf("%lld%lld%lld",&p,&q,&n) == 3 && p+q+n){
		//if(p == 0 && q == 0) break;
		if(n == 0){
			printf("2\n");
			continue;
		}
		Mx ans; ans.clear();
		ans.a[0][0] = p;
		ans.a[1][0] = 2;
		ans = Q_pow(n - 1) * ans;
		cout << ans.a[0][0] << endl;
	}
	return 0;
}

