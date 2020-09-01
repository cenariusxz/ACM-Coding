#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x7fffffff;	// fix
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

struct node{
	int time, id, sum;
	node(int _t, int _id, int _sum):time(_t), id(_id), sum(_sum){}	
};

stack<node>st;

void solve(){
	int t, id, type, n, ansid = INF, ans = 0;
	while(!st.empty())st.pop();
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d%d%d", &t, &id, &type);
		if(type == 0){
			st.push(node(t, id, 0));
			continue;
		}
		node tmp = st.top(); st.pop();
		int res = t - tmp.time - tmp.sum;
		//printf("id:%d sum:%d\n", tmp.id, res);
		if(res > ans)ans = res, ansid = tmp.id;
		else if(res == ans && tmp.id < ansid)ans = res, ansid = tmp.id;
		if(!st.empty()){
			node fa = st.top(); st.pop();
			fa.sum += t - tmp.time;
			st.push(fa);
		}
	}
	printf("%d\n", ansid);
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)solve(); 
	return 0;
}

