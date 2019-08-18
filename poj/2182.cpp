#include <stdio.h>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

int c[maxn],n,pre[maxn],ans[maxn];

inline int lowbit(int x){return x&(-x);}

void add(int x,int a,int n){
    for(int i=x;i<=n;i+=lowbit(i))c[i]+=a;
}

int sum(int x){
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i))ans+=c[i];
    return ans;
}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)add(i,1,n);
	for(int i = 2 ; i <= n ; ++ i)scanf("%d",&pre[i]);
	for(int i = n ; i >= 1 ; -- i){
		int l = 1, r = n;
		ans[i] = INF;
		while(l <= r){
			int m = (l+r) >> 1;
			if(sum(m) >= pre[i] + 1){
				ans[i] = min(ans[i], m);
				r = m - 1;	
			}
			else l = m + 1;
		}
		add(ans[i],-1,n);
	}
	for(int i = 1 ; i <= n ; ++ i)printf("%d\n",ans[i]);
	return 0;
}
