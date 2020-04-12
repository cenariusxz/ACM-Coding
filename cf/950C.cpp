#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

char s[maxn];
queue<int>q0, q1;
vector<int>v[maxn];

void solve(){
	int ans = 0;
	for(int i = 1 ; s[i] ; ++ i){
		if(s[i] == '0'){
			if(!q1.empty()){
				int id = q1.front(); q1.pop();
				v[id].PB(i);
				q0.push(id);
			}
			else{
				ans ++;
				v[ans].PB(i);
				q0.push(ans);
			}
		}
		else{
			if(!q0.empty()){
				int id = q0.front(); q0.pop();
				v[id].PB(i);
				q1.push(id);
			}
			else{
				printf("-1\n");
				return;
			}
		}
	}
	if(!q1.empty()){
		printf("-1\n");
		return;
	}
	printf("%d\n", ans);
	for(int i = 1 ; i <= ans ; ++ i){
		printf("%d ",v[i].size());
		for(int j = 0 ; j < v[i].size() ; ++ j)printf("%d ", v[i][j]);
		printf("\n");
	}
}

int main(){
	scanf("%s", s+1);
	solve();
	return 0;
}

