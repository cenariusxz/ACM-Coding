#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 50010;
int a[MAXN];
int F[MAXN];
int find(int x){
	if(F[x] == -1)return x;
	return F[x] = find(F[x]);
}
void bing(int x,int y){
	int t1 = find(x), t2 = find(y);
	if(t1 != t2)F[t2] = t1;
}
int b[MAXN];
int last[MAXN];
int dp[MAXN];

int main()
{
    int n;
	while(scanf("%d",&n) == 1){
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
			b[cnt++] = a[i];
		}
		sort(b,b+cnt);
		cnt = unique(b,b+cnt) - b;
		map<int,int>mp;
		for(int i = 0;i < cnt;i++){
			mp[b[i]] = i+1;
			last[i] = -1;
		}
		for(int i = 1;i <= n;i++)a[i] = mp[a[i]];
	/*	for(int i=1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");*/
		dp[0] = 0;
		F[0] = -1;
		for(int i = 1;i <= n;i++){
			F[i] = -1;
			if(last[a[i]] != -1){
				bing(last[a[i]]-1,last[a[i]]);
			}
			last[a[i]] = i;
			dp[i] = i;
			int num = 0;
			for(int j = i;j > 0;j = find(j-1)){
				num++;
				if(num*num >= dp[i])break;
				int nxt = find(j-1);
				dp[i] = min(dp[i],dp[nxt]+num*num);
			}
		}
		printf("%d\n",dp[n]);
	}
    return 0;
}
