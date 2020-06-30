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
int n, sum[maxn];
int ans[maxn], cnt, num;
// 0 L  1 R
void getst(int n){
	for(int i = 1 ; i <= n ; ++ i){
		sum[i] = sum[i-1];
		if(s[i] == 'L')sum[i]--;
		if(s[i] == 'R')sum[i]++;
	}
	int res = 0, pos = 0, mx = 0, mn = 0, pmx = 0, pmn = 0, pos2 = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(abs(sum[i] - mx) > res)res = abs(sum[i] - mx), pos = pmx, pos2 = i;
		if(abs(sum[i] - mn) > res)res = abs(sum[i] - mn), pos = pmn, pos2 = i;
		if(sum[i] > mx)mx = sum[i], pmx = i;
		if(sum[i] < mn)mn = sum[i], pmn = i;
	}
	printf("%d %d %c\n", pos, pos2, s[pos2]);
	ans[++cnt] = pos2;
	if(ans[cnt] < ans[cnt-1])num++;
	s[pos2] = ' ';
	//return pos;
}

void solve(){

}

int main(){
	scanf("%s", s+1);
	n = strlen(s+1);
	for(int i = 1 ; i <= n ; ++ i)getst(n);
	//printf("%d\n", num);
	//for(int i = 1 ; i <= cnt ; ++ i)printf("%d ", ans[i]);
	//printf("\n");
	return 0;
}

