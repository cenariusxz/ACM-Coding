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

int m,n;
int vis[maxn];
queue<int>q;

int main(){
	scanf("%d%d",&m,&n);
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		int a;
		scanf("%d",&a);
		if(vis[a])continue;
		ans ++;
		if(q.size() < m){
			q.push(a);
			vis[a] = 1;
		}
		else{
			int u = q.front();
			q.pop();
			vis[u] = 0;
			q.push(a);
			vis[a] = 1;	
		}
	}
	printf("%d\n",ans);
	return 0;
}


