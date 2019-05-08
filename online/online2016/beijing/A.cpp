#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;

int n;
char s[110];

struct Book{
	vector<string> V;
}B[40];

void Read(int p){
	B[p].V.clear();
	string tmp = "";
	int len = strlen(s + 1);
	for(int i = 1; i <= len; ++i){
		if(s[i] == '/'){
			B[p].V.PB(tmp);
			tmp = "";
		}
		else tmp += s[i];
	}
	B[p].V.PB(tmp);
}

bool cmp(Book a,Book b){
	int len = min(a.V.size(),b.V.size());
	for(int i = 0; i < len; ++i){
		if(a.V[i] < b.V[i]) return true;
		if(a.V[i] > b.V[i]) return false;
	}
	return a.V.size() < b.V.size();
}

bool Check(Book a,Book b){
	if(a.V.size() != b.V.size()) return true;
	for(int i = 0; i < a.V.size(); ++i){
		if(a.V[i] != b.V[i]) return true;
	}
	return false;
}

int tot;

struct Node{
	map<string,int> mp;
	map<string,int> mpb;
	string name;
}nd[1010];

void Insert(int p){
	int now = 0;
	for(int i = 0; i < B[p].V.size(); ++i){
		string cur = B[p].V[i];
		if(i == B[p].V.size() - 1){
			if(nd[now].mpb[cur] == 0){
				nd[now].mpb[cur] = ++tot;
			}
			int id = nd[now].mpb[cur];
			nd[id].name = cur;
			now = id;
		}
		else{
			if(nd[now].mp[cur] == 0){
				nd[now].mp[cur] = ++tot;
			}
			int id = nd[now].mp[cur];
			nd[id].name = cur;
			now = id;
		}
	}
}

void Delete(){
	for(int i = 0; i <= tot; ++i){
		nd[i].mp.clear();
		nd[i].mpb.clear();
	}
}

void Dfs(int p,int d){
	for(int i = 1; i <= 4 * d; ++i) printf(" ");
	printf("%s\n",nd[p].name.c_str());
	map<string,int>::iterator it;
	for(it = nd[p].mp.begin(); it != nd[p].mp.end(); ++it){
		Dfs((*it).second,d + 1);
	}
	for(it = nd[p].mpb.begin(); it != nd[p].mpb.end(); ++it){
		Dfs((*it).second,d + 1);
	}
}

int main(){
	int tt = 0;
	while(gets(s + 1) != NULL){
		n = 0;
		while(!(s[1] == '0' && s[2] == '\0')){
			++n;
			Read(n);
			gets(s + 1);
		}
		sort(B + 1,B + n + 1,cmp);
		int sz = 1;
		for(int i = 2; i <= n; ++i){
			if(Check(B[i],B[sz])) B[++sz] = B[i];
		}
		n = sz;
		tot = 0;
		for(int i = 1; i <= n; ++i){
			Insert(i);
		}
		//for(int i = 1; i <= n; ++i){
		//	for(int j = 0; j < B[i].V.size(); ++j){
		//		printf("%s ",B[i].V[j].c_str());
		//	}
		//	puts("");
		//}
		++tt;
		printf("Case %d:\n",tt);
		map<string,int>::iterator it;
		for(it = nd[0].mp.begin(); it != nd[0].mp.end(); ++it){
			Dfs((*it).second,0);
		}
		for(it = nd[0].mpb.begin(); it != nd[0].mpb.end(); ++it){
			Dfs((*it).second,0);
		}
		Delete();
	}
	return 0;
}
