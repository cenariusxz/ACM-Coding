#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;

int a[maxn], sum[maxn], res[maxn], vis[maxn], ans, g, n = 1;
double avg = 0;
char s[maxn];

int cal(){
	double ss = 0;
	for(int i = 1 ; i <= g ; ++ i)ss += (sum[i] - avg) * (sum[i] - avg);
	return ss;
}

void dfs(int t, int pos){	//at t groups, last choose pos
	if(t == g){
		for(int i = 1 ; i <= n ; ++ i)if(!vis[i])sum[g] += a[i];
		int tmp = cal();
		if(tmp < ans){
			ans = tmp;
			for(int i = 1 ; i <= g ; ++ i)res[i] = sum[i];
		}
		for(int i = 1 ; i <= n ; ++ i)if(!vis[i])sum[g] -= a[i];
		return;
	}
	// 1, continue choose t group
	for(int i = pos+1 ; i <= n ; ++ i){
		if(vis[i])continue;
		vis[i] = 1;
		sum[t] += a[i];
		dfs(t, i);
		vis[i] = 0;
		sum[t] -= a[i];
	}
	
	// 2, finish t and start t+1
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i])continue;
		vis[i] = 1;
		sum[t+1] += a[i];
		dfs(t+1, i);
		vis[i] = 0;
		sum[t+1] -= a[i];
		break;
	}
}

int main(){
	string s;
	getline(cin, s);
	cin >> g;
	for(int i = 0 ; i < s.length() ; ++ i){
		if(s[i] == ' ')continue;
		if(s[i] == ','){
			++ n;
			continue;
		}
		a[n] = a[n] * 10 + s[i] - '0';
	}
	for(int i = 1 ; i <= n ; ++ i)avg += a[i];
	avg /= n;
	ans = INF;
	dfs(0, n+1);
	sort(res + 1, res + 1 + g, greater<int>());
	for(int i = 1 ; i <= g ; ++ i){
		cout << res[i];
		if(i == g)cout << endl;
		else cout << ",";
	}
	return 0;
}

