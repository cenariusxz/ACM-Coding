#include <bits/stdc++.h>
using namespace std;
#define PB push_back
const int maxn = 1e6 + 5;

vector<int> V;
vector<char> C;
char s[maxn];

int	solve(){
	scanf("%s", s);
	V.clear(); C.clear();
	int cnt = 0;
	for(int i = 0 ; s[i] ; ++ i){
		if(i == 0 || s[i] != C[cnt - 1])V.PB(1), C.PB(s[i]), cnt++;
		else V[cnt - 1] ++;
	}
	if(cnt == 1)return V[cnt-1];
	int ans = 0;
	for(int i = 0 ; i < cnt ; ++ i){
		ans = max(ans, V[i] + 1);
		if(V[i] == 1 && i != 0 && i != cnt-1 && C[i-1] == C[i+1]){
			ans = max(ans, V[i-1] + V[i+1] + 1);
		}
	}
	return ans;
}

int main(){
	int m;
	scanf("%d", &m);
	while(m--)printf("%d\n", solve());
	return 0;
}

