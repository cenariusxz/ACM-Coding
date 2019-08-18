#include <stdio.h>
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

// K - &   A - |   N - !   C - !|   E - ==
// pqrst - 'p'
char s[maxn];
int pos;

bool dfs(int state){
	if(s[pos] >= 'p' && s[pos] <= 't'){
		return state & (1 << (s[pos++] - 'p'));
	}
	if(s[pos] == 'K'){
		pos++;
		bool left = dfs(state);
		bool right = dfs(state);
		return left & right;
	}
	if(s[pos] == 'A'){
		pos++;
		bool left = dfs(state);
		bool right = dfs(state);
		return left | right;
	}
	if(s[pos] == 'N'){
		pos++;
		return !dfs(state);	
	}
	if(s[pos] == 'C'){
		pos++;
		bool left = dfs(state);
		bool right = dfs(state);
		return !left|right;
	}
	if(s[pos] == 'E'){
		pos++;
		bool left = dfs(state);
		bool right = dfs(state);
		return left == right;	
	}
}

void solve(){
	for(int i = 0 ; i < (1<<5) ; ++ i){
		pos = 1;
		if(!dfs(i)){
			printf("not\n");
			return;
		}
	}
	printf("tautology\n");
}

int main(){
	while(scanf("%s",s+1)!=EOF){
		if(s[1] == '0')break;
		solve();
	}
	return 0;
}

