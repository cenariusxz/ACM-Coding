#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int m;

int main(){
	scanf("%d",&m);
	ll pos = 2;
	for(int i = 1 ; i < m ; ++ i){
		while((i + pos) * (pos - i + 1) / 2 < m)pos++;
		if( (i + pos) * (pos - i + 1) / 2 == m )printf("%d %d\n",i,pos);
	}
	return 0;
}


