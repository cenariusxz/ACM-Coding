#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e6 + 5;

int a[maxn],id[maxn],id2[maxn];
int live[maxn];		// 1 live  -1 die  0 unknown  solve_min
int n;

void topo(){
	int ans_min = 0, ans_max = n;
	queue<int>q;
	for(int i = 1 ; i <= n ; ++ i){
		if(id[i] == 0){		// 必存活、指向必死 
			ans_max --;
			q.push(i);
			live[i] = 1;
		}
	}
	while(!q.empty()){
		int u = q.front(); q.pop();
		int point = a[u];
		if(live[point] != -1){
			live[point] = -1;
			ans_min ++;
			int ppoint = a[point];
			id[ppoint] --;
			if(id[ppoint] == 0){
				live[ppoint] = 1;
				q.push(ppoint);
			}
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		if(live[i] == 0){		// 环 
			bool no_in = 1;		// 判纯环 
			int cnt = 0, pos = i;	// 环长、起点 
			while(live[pos] == 0){
				if(id2[pos] != 1)no_in = 0;
				cnt ++;
				live[pos] = 2;
				pos = a[pos];
			}
			ans_min += (cnt+1)/2;
			if(no_in && cnt > 1)ans_max--;	// 纯环且链长>1，则会留一人 
		}
	}
	printf("%d %d\n", ans_min, ans_max);
}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d",&a[i]);
		id[a[i]]++;
		id2[a[i]]++;
	}
	topo();
	return 0;
}

