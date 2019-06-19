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

int n, m;
char s[maxn][15];
int flag[maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < n ; ++ i)scanf("%d%s", &flag[i], s[i]);
	int pos = 0;
	while(m--){
		int d,a;
		scanf("%d%d", &d, &a);
		if(d == flag[pos])pos = ((pos-a)%n+n)%n;
		else pos = (pos+a)%n;
	}
	printf("%s\n",s[pos]);
	return 0;
}


