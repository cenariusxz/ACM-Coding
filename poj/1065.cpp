#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

struct node{
	int l,w;
	bool operator < (const node a)const{
		if(l == a.l)return w < a.w;
		return l < a.l;	
	}
}nd[maxn];

int n;
int f[maxn];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; ++ i)scanf("%d%d",&nd[i].l,&nd[i].w);
		sort(nd + 1 , nd + 1 + n);
		int ans = 0;
		f[0] = INF;	// 尽量少的单调非降序列，求最长的单调降序列长度 
		for(int i = 1 ; i <= n ; ++ i){
			int l = 0, r = ans, pos = 0;
			while(l <= r){
				int mid = (l+r) >> 1;
				if(f[mid] > nd[i].w){
					pos = max(pos,mid);
					l = mid + 1;	
				}
				else r = mid - 1;
			}
			if(pos + 1 > ans)ans = pos + 1;
			f[pos + 1] = nd[i].w;
		}
		printf("%d\n",ans);
	}
	return 0;
}

