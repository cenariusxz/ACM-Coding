#include <bits/stdc++.h>
#include <strstream>
using namespace std;
#define PB push_back
const int maxn = 2e5 + 5;
string s;
int vis[maxn], match[maxn], m;
vector<int> b, V[maxn];
int dfs(int s){
	for(int i = 0 ; i < V[s].size() ; ++ i){
		int j = V[s][i];
		if(!vis[j]){
			vis[j] = 1;
			if(match[j] == -1 || dfs(match[j])){
				match[j] = s;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	memset(match, -1, sizeof(match));
	getline(cin, s);
	istrstream sin(s.c_str());
	int id;
	while(sin >> id)b.PB(id);
	getline(cin, s);
	cin >> m;
	while(m --){
		int a, b;
		cin >> a >> b;
		V[a].PB(b);
		V[b].PB(a);
	}
	int ans = 0;
	for(int i = 0 ; i < b.size() ; ++ i){
		id = b[i];
		memset(vis, 0, sizeof(vis));
		if(dfs(id))ans++;
	}
	cout << ans << endl;
	return 0;
}

