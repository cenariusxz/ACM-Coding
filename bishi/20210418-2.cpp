#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

char s[2005], t[2005];
int n, m, pos[2][2005][26];

void init(){
	n = strlen(s+1);
	m = strlen(t+1);
	memset(pos, -1, sizeof(pos));
	for(int i = n ; i >= 1 ; -- i){
		for(int j = 0 ; j < 26 ; ++ j){
			pos[0][i][j] = pos[0][i+1][j];
		}
		pos[0][i][s[i] - 'a'] = i;
	}
	for(int i = m ; i >= 1 ; -- i){
		for(int j = 0 ; j < 26 ; ++ j){
			pos[1][i][j] = pos[1][i+1][j];
		}
		pos[1][i][t[i] - 'a'] = i;
	}
}

int solve(int a, int b){
	int ans = 0;
	for(int i = 0 ; i < 26 ; ++ i){
		if(pos[0][a][i] == -1)continue;
		int sfirst = pos[0][a][i];
		int tfirst = INF;
		for(int j = i + 1 ; j < 26 ; ++ j){
			if(pos[1][b][j] == -1)continue;
			tfirst = min(tfirst, pos[1][b][j]);
		}
		if(tfirst == INF)continue;
		ans = max(ans, n - sfirst + 1 + m - tfirst + 1);
	}
	return ans;
}

int main(){
	int q;
	scanf("%s%s%d", s+1, t+1, &q);
	init();
	while(q--){
		int i, j;
		scanf("%d%d", &i, &j);
		int ans = m - j + 1;
		printf("%d\n", max(ans, solve(i, j)));
	}
	return 0;
}

