#include <bits/stdc++.h>
using namespace std;
vector<string> c, q;
vector<int> x, y;
char s[15];


//////////////////////////////////////////////////////
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
struct node{
	string c;
	int x, y;
}nd[maxn];
map<string, int>M;
vector<string> ans;
vector<int> len;

bool cmp1(node a, node b){
	if(a.x == a.x)return a.y < b.y;
	return a.x < b.x;
}

bool cmp2(node a, node b){
	if(a.y == a.y)return a.x < b.x;
	return a.y < b.y;
}

vector<string> closestStraightCity(vector<string> c, vector<int> x, vector<int> y, vector<string> q){
	int n = c.size(), m = q.size();
	for(int i = 0 ; i < n ; ++ i)nd[i+1] = {c[i], x[i], y[i]};
	for(int i = 0 ; i < m ; ++ i)ans.push_back("NONE"), len.push_back(INF+1);
	sort(nd + 1, nd + 1 + n, cmp1);
	for(int i = 1 ; i <= n ; ++ i)M[nd[i].c] = i;
	for(int i = 0 ; i < m ; ++ i){
		int id = M[q[i]];
		if(id > 1 && nd[id-1].x == nd[id].x){
			int tmp = nd[id].y - nd[id-1].y;
			if(tmp < len[i] || tmp == len[i] && nd[id-1].c < ans[i]){
				len[i] = tmp;
				ans[i] = nd[id-1].c;
			}
		}
		if(id < n && nd[id+1].x == nd[id].x){
			int tmp = nd[id+1].y - nd[id].y;
			if(tmp < len[i] || tmp == len[i] && nd[id+1].c < ans[i]){
				len[i] = tmp;
				ans[i] = nd[id+1].c;
			}
		}
	}
	sort(nd + 1, nd + 1 + n, cmp2);
	for(int i = 1 ; i <= n ; ++ i)M[nd[i].c] = i;
	for(int i = 0 ; i < m ; ++ i){
		int id = M[q[i]];
		if(id > 1 && nd[id-1].y == nd[id].y){
			int tmp = nd[id].x - nd[id-1].x;
			if(tmp < len[i] || tmp == len[i] && nd[id-1].c < ans[i]){
				len[i] = tmp;
				ans[i] = nd[id-1].c;
			}
		}
		if(id < n && nd[id+1].y == nd[id].y){
			int tmp = nd[id+1].x - nd[id].x;
			if(tmp < len[i] || tmp == len[i] && nd[id+1].c < ans[i]){
				len[i] = tmp;
				ans[i] = nd[id+1].c;
			}
		}
	}
	return ans;
}
//////////////////////////////////////////////////////



int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i){
		int tx, ty;
		scanf("%d%d%s", &tx, &ty, s);
		x.PB(tx); y.PB(ty), c.PB(string(s));
	}
	for(int i = 1 ; i <= m ; ++ i){
		scanf("%s", s);
		q.PB(string(s));
	}
	vector<string> res = closestStraightCity(c, x, y, q);
	for(int i = 0 ; i < res.size() ; ++ i)printf("%s\n", res[i].c_str());
	return 0;
}

