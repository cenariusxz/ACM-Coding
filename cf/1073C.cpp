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

//U 0 D 1 L 2 R 3
//U y +1  D y -1  L x -1  R x +1
int n,x,y, sumx[maxn], sumy[maxn];
char s[maxn];

bool check(int len){
	for(int i = 1 ; i + len - 1 <= n ; ++ i){
		int j = i + len - 1;
		int delx = sumx[n] - (sumx[j] - sumx[i-1]);
		int dely = sumy[n] - (sumy[j] - sumy[i-1]);
		int needx = abs(x - delx), needy = abs(y - dely);
		if(len >= needx + needy && (len - needx - needy) % 2 == 0)return 1;
	}
	return 0;
}

int solve(){
	if(n < abs(x) + abs(y) || (n - abs(x) - abs(y)) % 2 == 1)return -1;
	for(int i = 1 ; s[i] ; ++ i){
		sumx[i] = sumx[i-1];
		sumy[i] = sumy[i-1];
		if(s[i] == 'U')sumy[i] ++;
		if(s[i] == 'D')sumy[i] --;
		if(s[i] == 'L')sumx[i] --;
		if(s[i] == 'R')sumx[i] ++;
	}
	if(sumx[n] == x && sumy[n] == y)return 0;
	int l = 1, r = n , ans = INF;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(check(mid))ans = min(ans, mid), r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}

int main(){
	scanf("%d%s%d%d", &n, s+1, &x, &y);
	printf("%d\n", solve());
	return 0;
}


