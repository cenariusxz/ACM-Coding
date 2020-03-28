#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 3e5 + 5;
const int maxm = 1e6 + 5;

char s[maxn];
char c[maxn];
int num[maxn], cnt;

int solve(){
	if((cnt & 1) == 0 || num[cnt/2 + 1] < 2)return 0;
	for(int i = 1 , j = cnt ; i < j ; ++ i , -- j){
		if(c[i] != c[j] || num[i] + num[j] < 3)return 0;
	}
	return num[cnt/2 + 1] + 1;
}

int main(){
	scanf("%s", s);
	for(int i = 0 ; s[i] ; ++ i){
		if(i == 0 || s[i] != s[i-1]){
			c[++cnt] = s[i];
			num[cnt] = 1;
		}
		else num[cnt] ++;
	}
	printf("%d\n", solve());
	return 0;
}

