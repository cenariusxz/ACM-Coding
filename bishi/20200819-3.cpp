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

char ss[15], tt[15];
int s[maxn], t[maxn], tmp[maxn], n, m;

int check(int st){
	memcpy(tmp, s, (n+5) * sizeof(int));	// 复制 s 数组到 tmp 数组 
	int mx = 0, mx2 = 0;
	for(int i = 1 ; i <= m ; ++ i){
		tmp[st + i - 1] += t[i];
		mx2 = max(mx2, tmp[st + i - 1]);
	}
	for(int i = 1 ; i <= n ; ++ i)mx = max(mx, tmp[i]);
	int cnt = 0;
	
	for(int j = 1 ; j <= mx ; ++ j){
		bool flag = 0;		// 0 满   1 未满 
		for(int i = 1 ; i <= n && !flag ; ++ i){
			if((i < st || i > st + i - 1) && j > s[i])flag = 1;
			if((i >= st && i <= st + i - 1) && ((j > s[i] && j <= mx2-(tmp[i]-s[i])) || j > mx2))flag = 1;
		}
		if(flag)++ cnt;
	}
	
	return cnt;
}

int main(){
	scanf("%s%s", ss+1, tt+1);
	n = strlen(ss+1), m = strlen(tt+1);
	for(int i = 1 ; ss[i] ; ++ i)s[i] = ss[i] - '0';		// 转int数组 
	for(int i = 1 ; tt[i] ; ++ i)t[i] = tt[i] - '0';
	int mn = 10, mx = 0;
	for(int i = 1 ; i <= n ; ++ i)mn = min(mn, s[i]);
	for(int i = 1 ; i <= n ; ++ i)s[i] -= mn;
	for(int i = 1 ; i <= n ; ++ i)mx = max(mx, s[i]);
	int ans = 100;
	for(int i = 1 ; i + m - 1 <= n ; ++ i)ans = min(ans, check(i));
	printf("%d\n", ans);
	return 0;
}

