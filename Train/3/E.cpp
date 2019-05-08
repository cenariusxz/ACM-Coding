#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 3010;
const int MAXT = 1000010;

int N,P,L;
int L[MAXN],R[MAXN];
int t[MAXT << 2],tp[MAXT << 2];
vector<int> V[MAXN];
vector<int> P[MAXT];

void Push_up(int p){
	if(t[p << 1] < t[p << 1|1]){
		t[p] = t[p << 1];
		tp[p] = tp[p << 1];
	}
	else{
		t[p] = t[p << 1|1];
		tp[p] = tp[p << 1|1];
	}
}

int Update(int a,int c,int p,int l,int r){
	if(l == r){
		t[p] = c;
		tp[p] = l;
		return;
	}
	int mid = (l + r) / 2;
	if(a <= mid) Update(a,c,p << 1,l,mid);
	else Update(a,c,p << 1|1,mid + 1,r);
	Push_up(p);
}

int main(){
	while(scanf("%d%d%d",&N,&P,&L) != EOF){
		memset(t,0,sizeof(t));
		int pos = 0;
		for(int i = 1; i <= N; ++i){
			int len;
			scanf("%d",&len);
			L[i] = pos;
			R[i] = pos + len;
			pos += len;
		}
		int Lsum = pos;
		int top_cnt = Lsum / P + (Lsum % P) ? 1 : 0;
		for(int i = 1; i <= N; ++i) V[i].clear();
		for(int i = 1; i <= top_cnt; ++i) P[i].clear();
		// pieces[i] -> [(i - 1) * P , i * P]
		pos = 0;
		int cnt = 1;
		for(int i = 1; i <= N; ++i){
			int top = pos + len;
			if(pos >= top){
				V[i].push_back(cnt);
			}
			while(pos < top){
				V[i].push_back(cnt);
				cnt++;
				pos += P;
			}
			for(int j = 0; j < V[i].size(); ++j){
				P[V[i][j]].push_back(i);
			}
		}
		for(int i = 1; i <= cnt; ++i){
			Update(i,P[i].size(),1,1,cnt);
		}
		top_cnt = min(top_cnt,cnt);
		for(int i = 1; i <= top_cnt; ++i){
			
		}
		
	}
	return 0;
}
