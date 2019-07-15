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

int n;
int a[15],id[15];
int ans = 100;

void dfs(int group, int pre, int sum){
	if(group >= ans)return;
	if(sum == n){
		ans = min(ans,group);
		return;
	}
	for(int i = pre+1 ; i <= n ; ++ i){
		if(id[i])continue;
		bool flag = 1;
		for(int j = 1 ; j <= pre ; ++ j){
			if(id[j] == group && __gcd(a[i],a[j]) != 1){
				flag = 0;
				break;
			}
		}
		if(!flag)continue;
		id[i] = group;
		dfs(group, i, sum+1);
		id[i] = 0;
	}
	for(int i = 1 ; i <= n ; ++ i){
		if(id[i])continue;
		id[i] = group + 1;
		dfs(group+1, i, sum+1);
		id[i] = 0;
		break;	
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	id[1] = 1;
	dfs(1,1,1);
	printf("%d\n",ans);
	return 0;
}

