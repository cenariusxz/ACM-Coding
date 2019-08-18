#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e4 + 5;
const int maxm = 1e6 + 5;

struct node{
	int x, y, c;
	bool operator < (const node a)const{
		if(x == a.x)return c > a.c;
		return x < a.x;
	}
	node(){}
	node(int _x, int _y, int _c):x(_x), y(_y), c(_c){}
}nd[maxn];

int y[maxn],n,w,h;
int st[maxn<<2], add[maxn<<2];

void pushdown(int o){
	if(add[o]){
		st[o<<1] += add[o];
		st[o<<1|1] += add[o];
		add[o<<1] += add[o];
		add[o<<1|1] += add[o];
		add[o] = 0;
	}
}

void update(int o,int l,int r,int ql,int qr,int c){
	if(ql <= y[l] && qr >= y[r]){
		st[o] += c;
		add[o] += c;
		return;
	}
	pushdown(o);
	int m = (l+r) >> 1;
	if(ql <= y[m])update(o<<1,l,m,ql,qr,c);
	if(qr >= y[m+1])update(o<<1|1,m+1,r,ql,qr,c);
	st[o] = max(st[o<<1],st[o<<1|1]);
}

int main(){
	while(scanf("%d%d%d",&n,&w,&h)!=EOF){
		w--;h--;
		for(int i = 1 ; i <= n ; ++ i){
			int _x,_y,_c;
			scanf("%d%d%d",&_x,&_y,&_c);
			nd[2*i-1] = node(_x-w, _y, _c);
			nd[2*i] = node(_x, _y, -_c);
			y[2*i-1] = _y;
			y[2*i] = _y-h;
		}
		sort(y+1,y+1+2*n);
		int cnt = unique(y+1,y+1+2*n) - (y+1);
		sort(nd+1,nd+1+2*n);
		int ans = 0;
		for(int i = 1 ; i <= 2*n ; ++ i){
			int y1 = nd[i].y-h, y2 = nd[i].y;
			update(1,1,cnt,y1,y2,nd[i].c);
			ans = max(ans, st[1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

