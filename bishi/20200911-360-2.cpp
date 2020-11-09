#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n, m, fin, lout, logg[2][maxn], ans[maxn], cnt = 0;
bool inflag, outflag;

int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		int id, type;
		scanf("%d%d", &id, &type);
		logg[type][id] = 1;
		if(type == 1 && !fin)fin = id;
		if(type == 0)lout = id;
	}
	for(int i = 1 ; i <= n ; ++ i){
		if(!logg[0][i] && !logg[1][i])ans[++cnt] = i;
		if(logg[0][i] && !logg[1][i])inflag = 1;
		if(!logg[0][i] && logg[1][i])outflag = 1;
	}
	if(!inflag && !outflag && fin == lout)ans[++cnt] = fin;
	if(!inflag && outflag && !logg[0][fin])ans[++cnt] = fin;
	if(inflag && !outflag && !logg[1][lout])ans[++cnt] = lout;
	sort(ans + 1, ans + 1 + cnt);
	for(int i = 1 ; i <= cnt ; ++ i){
		printf("%d%c", ans[i], i == cnt ? '\n' : ' ');
	}
	return 0;
}

