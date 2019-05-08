#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 4e5 + 5;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

struct point{
	int x,y;
	bool operator < ( const point a )const{
		if(y==a.y)return x<a.x;
		return y<a.y;
	}
}p[maxn];

int st[maxn<<2];

void build(){
	memset(st,0,sizeof(st));
}

void update(int o,int l,int r,int ind){
	if( l == r ){
		st[o]++;
		return;	
	}
	int m = ( l + ((r - l )>>1) );
	if(ind <= m)update(o<<1,l,m,ind);
	else update(o<<1|1,m+1,r,ind);
	st[o]=st[o<<1]+st[o<<1|1];
	return;
}

int query(int o,int l,int r,int ql,int qr){
	if(ql <= l && qr >= r)return st[o];
	int m = ( l + (( r - l )>>1));
	int ans=0;
	if(ql <= m)ans += query(o<<1,l,m,ql,qr);
	if(qr >= m+1)ans += query(o<<1|1,m+1,r,ql,qr);
	return ans;
}

int ans[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+n+1);
	memset(ans,0,sizeof(ans));
	for(int i = 1 ; i <= n ; ++ i ){
		ans[query(1,0,32001,0,p[i].x)]++;
		update(1,0,32001,p[i].x); 
	}
	for(int i = 0 ; i < n ; ++ i )printf("%d\n",ans[i]);
	return 0;
}

