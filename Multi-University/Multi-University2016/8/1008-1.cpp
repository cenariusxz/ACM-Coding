#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define getmid(l,r) ((l) + ((r) - (l)) / 2)

typedef long long ll;
const int MAXN = 100010;

int T,n,m,A[MAXN],ql,qr,qx;
ll ans,tsum[MAXN << 2],tadd[MAXN << 2],teq[MAXN << 2];
int SQRT[100010];

inline void Read(int &x){
	x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
}

void Build(int p,int l,int r){
	tadd[p] = 0;
	if(l == r){
		tsum[p] = A[l];
		teq[p] = A[l];
		return;
	}
	int mid = getmid(l,r);
	Build(p << 1,l,mid);
	Build(p << 1|1,mid + 1,r);
	tsum[p] = tsum[p << 1] + tsum[p << 1|1];
	teq[p] = (teq[p << 1] == teq[p << 1|1]) ? teq[p << 1] : 0;
}

inline void Push_down(int &p,int Ll,int Lr){
	if(teq[p]){
		if(teq[p << 1] != teq[p]){
			teq[p << 1] = teq[p];
			tsum[p << 1] = teq[p] * Ll;
			tadd[p << 1] = 0;
		}
		if(teq[p << 1|1] != teq[p]){
			teq[p << 1|1] = teq[p];
			tsum[p << 1|1] = teq[p] * Lr;
			tadd[p << 1|1] = 0;
		}
	}
	else if(tadd[p]){
		tadd[p << 1] += tadd[p];
		tsum[p << 1] += (ll)tadd[p] * Ll;
		if(teq[p << 1]) teq[p << 1] += tadd[p];
		tadd[p << 1|1] += tadd[p];
		tsum[p << 1|1] += (ll)tadd[p] * Lr;
		if(teq[p << 1|1]) teq[p << 1|1] += tadd[p];
		tadd[p] = 0;
	}
}

inline void Push_up(int &p){
	tsum[p] = tsum[p << 1] + tsum[p << 1|1];
	teq[p] = (teq[p << 1] == teq[p << 1|1]) ? teq[p << 1] : 0;
	if(teq[p]) tadd[p] = 0;
}

void Update(int p,int l,int r){
	if(ql <= l && r <= qr){
		if(teq[p]) teq[p] += qx;
		else tadd[p] += qx;
		tsum[p] += (r - l + 1) * (ll)qx;
		return;
	}
	int mid = getmid(l,r);
	Push_down(p,mid - l + 1,r - mid);
	if(ql <= mid) Update(p << 1,l,mid);
	if(qr > mid)  Update(p << 1|1,mid + 1,r);
	Push_up(p);
}

void Rezero(int p,int l,int r){
	//printf("p : %d , [%d , %d]\n",p,l,r);
	if(ql <= l && r <= qr && teq[p]){
		if(teq[p] > 1){
			if(teq[p] > 100000) teq[p] = sqrt(0.5 + (double)teq[p]);
			else teq[p] = SQRT[teq[p]];
			tsum[p] = (r - l + 1) * teq[p];
		}
		return;
	}
	int mid = getmid(l,r);
	Push_down(p,mid - l + 1,r - mid);
	if(ql <= mid) Rezero(p << 1,l,mid);
	if(qr > mid)  Rezero(p << 1|1,mid + 1,r);
	Push_up(p);
}

void Query(int p,int l,int r){
	if(ql <= l && r <= qr){
		ans += tsum[p];
		return;
	}
	int mid = getmid(l,r);
	Push_down(p,mid - l + 1,r - mid);
	if(ql <= mid) Query(p << 1,l,mid);
	if(qr > mid)  Query(p << 1|1,mid + 1,r);
}

int main(){
	for(int i = 1; i <= 100000; ++i) SQRT[i] = sqrt(0.5 + i);
	Read(T);
	while(T--){
		Read(n),Read(m);
		for(int i = 1; i <= n; ++i) Read(A[i]);
		Build(1,1,n);
		for(int o = 1; o <= m; ++o){
			int f;
			Read(f),Read(ql),Read(qr);
			if(f == 1){
				Read(qx);
				Update(1,1,n);
				/*for(int i = 1; i <= 9; ++i){
				  printf("%d , sum : %lld , teq : %lld , %lld\n",i,tsum[i],teq[i],tadd[i]);
				  }*/
			}
			else if(f == 2){
				Rezero(1,1,n);
				/*for(int i = 1; i <= 9; ++i){
				  printf("%d , sum : %lld , teq : %lld , %lld\n",i,tsum[i],teq[i],tadd[i]);
				  }*/
			}
			else{
				ans = 0;
				Query(1,1,n);
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}

