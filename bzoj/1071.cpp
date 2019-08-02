#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e3+5;

struct node{
	int h,v;
	ll s;
	bool operator < (const node a)const{
		return s < a.s;
	}
}nd[maxn];

struct node2{
	int h,v;
	ll s;
	bool operator < (const node2 a)const{
		return v < a.v;
	}
}nd2[maxn];

int n;
ll A,B,C;

int main(){
	scanf("%d%lld%lld%lld",&n,&A,&B,&C);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d",&nd[i].h,&nd[i].v);
	for(int i = 1 ; i <= n ; ++ i)nd[i].s = A*nd[i].h + B*nd[i].v;
	for(int i = 1 ; i <= n ; ++ i)nd2[i] = node2{nd[i].h, nd[i].v, nd[i].s};
	sort(nd+1, nd+1+n);
	sort(nd2+1, nd2+1+n);
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		int minh = nd[i].h;
		int cnt = 0;
		int pos1 = 0, pos2 = 0;
		for(int j = 1 ; j <= n ; ++ j){
			int minv = nd2[j].v;
			ll sum = A*minh + B*minv + C;
			while(pos1 < n){
				if(nd[pos1+1].s <= sum){
					if(nd[pos1+1].h >= minh && nd[pos1+1].v >= minv)cnt++;
					pos1++;
				}
				else break;
			}
			while(pos2 < n){
				if(nd2[pos2+1].v < minv){
					if(nd2[pos2+1].h >= minh && nd2[pos2+1].h <= minh + C/A)cnt--;
					pos2++;	
				}
				else break;
			}
			if(cnt > ans)ans = cnt;
		}
	}
	printf("%d\n",ans);
	return 0;
}
