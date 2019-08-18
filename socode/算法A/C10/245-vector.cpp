#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

vector<int> V[maxn];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; ++ i){
		int type;
		scanf("%d",&type);
		if(type == 1){
			int x,y;
			scanf("%d%d",&x,&y);
			V[x].PB(y);
		}
		else{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",V[a][b-1]);
		}
	}
	return 0;
}

