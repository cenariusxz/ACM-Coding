#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 5e3 + 5;
const int maxm = 1e6 + 5;

int n,q;
int cnt[maxn], del[maxn][maxn];
int idx[maxn][3];

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1 ; i <= q ; ++ i){
		int l,r;
		scanf("%d%d", &l, &r);
		for(int j = l ; j <= r ; ++ j){
			cnt[j] ++;
			if(cnt[j] <= 2)idx[j][cnt[j]] = i;
		}
	}
	int sum = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(cnt[i])sum ++;
	}
	for(int i = 1 ; i <= n ; ++ i){
		if(cnt[i] == 1){
			int now = idx[i][1];
			for(int j = 1 ; j <= q ; ++ j)del[now][j] ++, del[j][now] ++;
		}
		else if(cnt[i] == 2){
			int now1 = idx[i][1], now2 = idx[i][2];
			del[now1][now2]++;
			del[now2][now1]++;
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= q ; ++ i){
		for(int j = 1 ; j <= q ; ++ j){
			if(i == j)continue;
			ans = max(ans, sum - del[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}

