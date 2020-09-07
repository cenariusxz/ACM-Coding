#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

struct node{
	string s;
	int cnt;
}nd[maxn];

int n, k, m;
char s[maxn];
map<string, int> M;

bool cmp1(node a, node b){
	if(a.cnt == b.cnt)return a.s < b.s;
	return a.cnt > b.cnt;
}

bool cmp2(node a, node b){
	if(a.cnt == b.cnt)return a.s < b.s;
	return a.cnt < b.cnt;
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%s", s);
		int id = M[string(s)];
		if(id)nd[id].cnt ++;
		else{
			id = M[string(s)] = ++m;
			nd[id].s = string(s);
			nd[id].cnt = 1;
		}
	}
	sort(nd + 1, nd + 1 + m, cmp1);
	for(int i = 1 ; i <= k ; ++ i)printf("%s %d\n", nd[i].s.c_str(), nd[i].cnt);
	sort(nd + 1, nd + 1 + m, cmp2);
	for(int i = 1 ; i <= k ; ++ i)printf("%s %d\n", nd[i].s.c_str(), nd[i].cnt);
	return 0;
}

