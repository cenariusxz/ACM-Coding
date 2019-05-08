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
const int MAXN = 300010;

int N,Q;
int sum[MAXN];
int C[MAXN];
int tmax[MAXN << 2],add[MAXN << 2];
char s[MAXN];
set<int> st;
set<int>::iterator it;

void Add(int x,int d){
	while(x <= N){
		C[x] += d;
		x += x & (-x);
	}
}

int Get(int x){
	int res = 0;
	while(x){
		res += C[x];
		x -= x & (-x);
	}
	return res;
}

void Build(int p,int l,int r){
	add[p] = 0;
	if(l == r){
		tmax[p] = sum[l];
		add[p] = 0;
		return;
	}
	int mid = getmid(l,r);
	Build(p << 1,l,mid);
	Build(p << 1|1,mid + 1,r);
	tmax[p] = max(tmax[p << 1],tmax[p << 1|1]);
}

void Push_down(int p){
	if(add[p] != 0){
		add[p << 1] += add[p];
		tmax[p << 1] += add[p];

		add[p << 1|1] += add[p];
		tmax[p << 1|1] += add[p];

		add[p] = 0;
	}
}

void Update(int a,int b,int c,int p,int l,int r){
	if(a <= l && r <= b){
		tmax[p] += c;
		add[p] += c;
		return;
	}
	Push_down(p);
	int mid = getmid(l,r);
	if(a <= mid) Update(a,b,c,p << 1,l,mid);
	if(b > mid) Update(a,b,c,p << 1|1,mid + 1,r);
	tmax[p] = max(tmax[p << 1],tmax[p << 1|1]);
}

int Query(int a,int b,int p,int l,int r){
	if(a <= l && r <= b){
		return tmax[p];
	}
	Push_down(p);
	int mid = getmid(l,r);
	int res = 0;
	if(a <= mid) res = max(res,Query(a,b,p << 1,l,mid));
	if(b > mid) res = max(res,Query(a,b,p << 1|1,mid + 1,r));
	tmax[p] = max(tmax[p << 1],tmax[p << 1|1]);
	return res;
}

int Solve(int p,int l,int r){
	if(l == r){
		return l;
	}
	Push_down(p);
	int mid = getmid(l,r);
	if(tmax[p << 1] >= 2) return Solve(p << 1,l,mid);
	else return Solve(p << 1|1,mid + 1,r);
}

void Init(){
	memset(C,0,sizeof(C));
}

int main(){
	while(scanf("%d%d",&N,&Q) != EOF){
		Init();
		scanf("%s",s + 1);
		sum[0] = 0;
		st.clear();
		for(int i = 1; i <= N; ++i){
			if(s[i] == '(') sum[i] = sum[i - 1] + 1;
			else{
				sum[i] = sum[i - 1] - 1;
				st.insert(i);
				Add(i,1);
			}
		}
		Build(1,1,N);
		for(int i = 1; i <= Q; ++i){
			int a;
			scanf("%d",&a);
			if(a == 1){
				printf("1\n");
				continue;
			}
			if(s[a] == '('){
				// ( -> )
				if(st.empty()){
					// 改自身
					printf("%d\n",a);
				}
				else{
					it = st.begin();
					if((*it) < a){
						int ans = (*it);
						st.erase(ans);
						Add(ans,-1);
						Update(ans,a - 1,2,1,1,N);
						s[a] = ')';
						s[ans] = '(';
						st.insert(a);
						Add(a,1);
						printf("%d\n",ans);
					}
					else{
						printf("%d\n",a);
					}
				}
			}
			else{
				// s[a] == ')'
				// ) -> (
				if(a == N){
					printf("%d\n",a);
					continue;
				}
				int cnt_r = Get(N) - Get(a);
				int cnt_l = N - a - cnt_r;
				if(cnt_r <= cnt_l){
					printf("%d\n",a);
					continue;
				}
				int res = Query(1,a - 1,1,1,N);
				int ans;
				if(res >= 2){
					ans = Solve(1,1,N);
					printf("%d\n",ans);
					st.erase(a);
					Add(a,-1);
					Update(ans,a - 1,-2,1,1,N);
					st.insert(ans);
					Add(ans,1);
					s[a] = '(';
					s[ans] = ')';
				}
				else{
					printf("%d\n",a);
				}
			}
		}
	}
	return 0;
}
