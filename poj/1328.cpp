#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e4 + 5;
const int maxm = 1e6 + 6;

struct node{
	int x,y;
	double pos;
	bool operator < (const node a)const{
		return pos < a.pos;
	}
}nd[maxn];

int n,d;

double solve(int id){
	return nd[id].x + sqrt( d*1.0*d - nd[id].y*1.0*nd[id].y );
}

double cal(int id, double x){
	return nd[id].y*1.0*nd[id].y + (x-nd[id].x)*(x-nd[id].x);
}

int main(){
	int cnt = 0;
	while(scanf("%d%d",&n,&d) != EOF){
		if(n == 0 && d == 0)break;
		for(int i = 1 ; i <= n ; ++ i)scanf("%d%d",&nd[i].x,&nd[i].y);
		printf("Case %d: ",++cnt);
		int ans = 1;
		for(int i = 1 ; i <= n ; ++ i){
			if(nd[i].y > d){
				ans = -1;
				break;
			}
			nd[i].pos = solve(i);
		}
		if(ans == -1){
			printf("-1\n");
			continue;
		}
		sort(nd+1, nd+1+n);
		int pre = 1;
		for(int i = 2 ; i <= n ; ++ i){
			if(cal(i, nd[pre].pos) > d*1.0*d){
				pre = i;
				ans ++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
