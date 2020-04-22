#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

char s[10][10];

void solve(){
	int w = 0, b = 0;
	for(int i = 1 ; i <= 8 ; i ++){
		for(int j = 1 ; j <= 8 ; j ++){
			if(s[i][j] == 'Q')w += 9;
			if(s[i][j] == 'q')b += 9;
			if(s[i][j] == 'R')w += 5;
			if(s[i][j] == 'r')b += 5;
			if(s[i][j] == 'B')w += 3;
			if(s[i][j] == 'b')b += 3;
			if(s[i][j] == 'N')w += 3;
			if(s[i][j] == 'n')b += 3;
			if(s[i][j] == 'P')w += 1;
			if(s[i][j] == 'p')b += 1;
		}
	}
	if(w > b)printf("White\n");
	else if(w < b)printf("Black\n");
	else printf("Draw\n");
}

int main(){
	for(int i = 1 ; i <= 8 ; ++ i)scanf("%s", s[i]+1);
	solve();
	return 0;
}
