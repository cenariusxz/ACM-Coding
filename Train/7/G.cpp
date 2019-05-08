#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 300010;

int m,n,A,B,qmax;
int a,b,C,M;
int L[MAXN];
int c[MAXN];
int BB[MAXN];

struct Node{
	int x,y,z;
	int dp,id;
}Q[MAXN];

int tmp[MAXN];

int r(){
	a = 36969 * (a & M) + (a >> 16);
	b = 18000 * (b & M) + (b >> 16);
	return (C & ((a << 16) + b)) % 1000000;
}

bool cmp_x(Node t1,Node t2){
	if(t1.x != t2.x) return t1.x < t2.x;
	return t1.z < t2.z;
}

bool cmp_y(Node t1,Node t2){
	if(t1.y != t2.y) return t1.y < t2.y;
	return t1.z < t2.z;
}

void Magic(int &a,int b){
	if(a < b) a = b;
}

void Update(int x,int d){
	while(x <= m + n){
		Magic(c[x],d);
		x += x & (-x);
	}
}

void Getmax(int x){
	while(x){
		Magic(qmax,c[x]);
		x -= x & (-x);
	}
}

void Clear(int x){
	while(x <= m + n){
		c[x] = 0;
		x += x & (-x);
	}
}

void CDQ(int l,int r){
	if(l == r) return;
	int mid = (l + r) / 2;
	CDQ(l,mid);
	int xmid = Q[mid].x;
	for(int i = l; i <= r; ++i){
		if(Q[i].x <= xmid) L[Q[i].id] = 1;
		else L[Q[i].id] = 0;
	}
	sort(Q + l,Q + r + 1,cmp_y);
	int tmp_cnt = 0;
	int pre = l;
	for(int i = l; i <= r; ++i){
		if(L[Q[i].id]){
		//	tmp[++tmp_cnt] = Q[i].z;
		//	Update(Q[i].z,Q[i].dp);
		}
		else{
			while(pre < i && Q[pre].y < Q[i].y){
				if(L[Q[pre].id]){
					tmp[++tmp_cnt] = Q[i].z;
					Update(Q[pre].z,Q[pre].dp);
				}
				pre++;
			}
			qmax = 0;
			Getmax(Q[i].z - 1);
			qmax++;
			Magic(Q[i].dp,qmax);
		}
	}
	for(int i = 1; i <= tmp_cnt; ++i){
		Clear(tmp[i]);
	}
	sort(Q + l,Q + r + 1,cmp_x);
	CDQ(mid + 1,r);
}

int main(){
	while(scanf("%d%d%d%d",&m,&n,&A,&B) != EOF){
		if(m + n + A + B == 0) break;
		memset(c,0,sizeof(c));
		a = A;
		b = B;
		C = ~(1 << 31);
		M = (1 << 16) - 1;
		for(int i = 1; i <= m; ++i){
			scanf("%d%d%d",&Q[i].x,&Q[i].y,&Q[i].z);
			Q[i].x++;
			Q[i].y++;
			Q[i].z++;
			Q[i].dp = 1;
			Q[i].id = i;
			BB[i] = Q[i].z;
		}
		for(int i = 1; i <= n; ++i){
			Q[m + i].x = r() + 1;
			Q[m + i].y = r() + 1;
			Q[m + i].z = r() + 1;
			Q[m + i].dp = 1;
			Q[m + i].id = m + i;
			BB[m + i] = Q[m + i].z;
		}
		sort(BB + 1,BB + m + n + 1);
		int sz = unique(BB + 1,BB + m + n + 1) - BB - 1;
		for(int i = 1; i <= m + n; ++i){
			Q[i].z = lower_bound(BB + 1,BB + sz + 1,Q[i].z) - BB;
		}
		//for(int i = 1; i <= m + n; ++i){
		//	printf("%d : (%d , %d , %d)\n",i,Q[i].x,Q[i].y,Q[i].z);
		//}
		sort(Q + 1,Q + m + n + 1,cmp_x);
		CDQ(1,m + n);
		int ans = 0;
		for(int i = 1; i <= m + n; ++i) ans = max(ans,Q[i].dp);
		printf("%d\n",ans);
	}
	return 0;
}
