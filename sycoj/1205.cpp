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

int n,m;
int a[maxm];
int vis[maxn];

int main(){
	scanf("%d%d",&n,&m);
	int ansl = 1, ansr = n;
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	for(int i = 1 ; i <= n ; ++ i)vis[a[i]] ++;
	for(int i = 1 ; i <= m ; ++ i){
		if(!vis[i])while(1){}
	}
	memset(vis,0,sizeof(vis));
	int pos = 0, cnt = 0;
	for(int i = 1 ; i <= n ; ++ i){
		while(cnt != m && pos < n){
			pos ++;
			vis[a[pos]] ++;
			if(vis[a[pos]] == 1)cnt++;
		}
		if(cnt == m){
			if(pos - i + 1 < ansr - ansl + 1)ansl = i, ansr = pos;
		}
		vis[a[i]] --;
		if(vis[a[i]] == 0)cnt--;
	}
	printf("%d %d\n",ansl, ansr);
	return 0;
}


