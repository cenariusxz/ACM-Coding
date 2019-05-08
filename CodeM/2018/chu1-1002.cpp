#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define PUB push_back
#define PUF push_front
#define POB pop_back
#define POF pop_front
#define MP make_pair
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

vector<deque<int> >V;
vector<int> T;

int n,q;
int id[150005];
int type,u,v,val,w,cnt=0;

void read(int &x){
	char ch = getchar();x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >='0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}

int ans;

int get(int u,int w){		//w == 0 qian
	if(id[u] == -1 || V[id[u]].size() == 0)return -1;
	if(T[id[u]] ^ w){
		ans = V[id[u]].back();
		V[id[u]].POB();
	}
	else{
		ans = V[id[u]].front();
		V[id[u]].POF();
	}
	return ans;
}

void solve1(){
	read(w);read(val);
	if(id[u] == -1){
		deque<int>qq;
		V.PUB(qq);
		cnt++;
		T.PUB(0);
		id[u] = cnt-1;
	}
	if(T[id[u]] ^ w)V[id[u]].PUB(val);
	else V[id[u]].PUF(val);
}

void solve2(){
	read(w);
	printf("%d\n",get(u,w));
}

void solve3(){
	read(v);read(w);
	if(id[u] == -1){
		deque<int>qq;
		V.PUB(qq);
		cnt++;
		T.PUB(0);
		id[u] = cnt-1;
	}
	if(id[v] == -1){
		return;
	}
	if(w == 1)T[id[v]]^=1;
	int used = v, target = u, p;
	bool f = 0;
	if(V[id[u]].size() < V[id[v]].size()){
		T[id[u]]^=1;T[id[v]]^=1;
		swap(u,v);
		f = 1;
	}
	if(T[id[u]] == 0){
		while((p=get(v,0)) != -1){
			V[id[u]].PUB(p);
		}
	}
	else{
		while((p=get(v,0)) != -1){
			V[id[u]].PUF(p);
		}
	}
	if(f)T[id[u]] ^= 1;
	int idu = id[u],idv = id[v];
	id[target] = idu;
	id[used] = idv;
}

void solve(){
	while(q--){
		read(type);read(u);
		if(type == 1)solve1();
		else if(type == 2)solve2();
		else solve3();
	}
}

int main(){
	while(scanf("%d%d",&n,&q)!=EOF){
		V.clear();T.clear();cnt = 0;
		memset(id,-1,sizeof(id));
		solve();
	}
	return 0;
}
