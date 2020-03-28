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

int n;
char s[maxn];
char col[3];
int num[3][3];

int main(){
	col[0] = 'R'; col[1] = 'G'; col[2] = 'B';
	scanf("%d%s",&n,s);
	for(int i = 0 ; s[i] ; ++ i){
		if(s[i] == col[0])num[i%3][0] ++;
		if(s[i] == col[1])num[i%3][1] ++;
		if(s[i] == col[2])num[i%3][2] ++;
	}
	int ans = INF;
	char ans0, ans1, ans2;
	for(int i = 0 ; i <= 2 ; ++ i){	// 0 pos  i color
		for(int j = 0 ; j <= 2 ; ++ j){	// 1 pos  j color
			if(i == j)continue;
			for(int k = 0 ; k <= 2 ; ++ k){	// 2 pos  k color
				if(i == k || j == k)continue;
				int res = num[0][j] + num[0][k] + num[1][i] + num[1][k] + num[2][i] + num[2][j];
				if(res < ans)ans = res, ans0 = col[i], ans1 = col[j], ans2 = col[k];
			}
		}
	}
	printf("%d\n", ans);
	for(int i = 0 ; i < n ; ++ i){
		int p = i % 3;
		if(p == 0)putchar(ans0);
		if(p == 1)putchar(ans1);
		if(p == 2)putchar(ans2);
	}
	putchar('\n');
	return 0;
}

