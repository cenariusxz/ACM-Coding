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

int n,T;
int r[maxn];

int main(){
	scanf("%d%d",&n,&T);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&r[i]);
	r[0] = -1;
	while(T--){
		int id = 0;
		for(int i = 1 ; i <= n ; ++ i){
			if(r[i] > r[id])id = i;	
		}
		printf("%d\n",id);
		int p = r[id]/(n-1), q = r[id]%(n-1);
		r[id] = 0;
		for(int i = 1 ; i <= n ; ++ i){
			if(i == id)continue;
			r[i] += p;
			if(q)q--, r[i]++;	
		}
	}
	return 0;
	
}


