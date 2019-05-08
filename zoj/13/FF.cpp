#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

struct seg{
	int l,r;
	bool operator < (const seg a)const{
		if(l==a.l)return r<a.r;
		return l<a.l;
	}
}s[25],tmp[25];

int n,k,m,cnt;
int vis[25],ans;

void Pre(){
	sort(tmp+1,tmp+n+1);
	cnt=1;
	s[1]=tmp[1];
	for(int i=2;i<=n;++i){
		if(tmp[i].l>s[cnt].r+1){
			++cnt;
			s[cnt]=tmp[i];
		}
		else if(tmp[i].r>s[cnt].r)s[cnt].r=tmp[i].r;
	}
	n=cnt;
}

void solve(int bin){
	
	for(int i=1)
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&k,&m);
		for(int i=1;i<=n;++i)scanf("%d%d",&tmp[i].l,&tmp[i].r);
		Pre();
		ans=-1;
		for(int i=0;i<(1<<n);++i){
			solve(i);
		}
	}
	return 0;
}
