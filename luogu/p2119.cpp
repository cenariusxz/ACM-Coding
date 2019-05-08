#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const int maxm = 4e5 + 5;

int cnt[maxn],sum[maxn];
int ans[maxn][4];
int num[maxm];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; ++ i){
		scanf("%d",&num[i]);
		cnt[num[i]]++;
	}
	int delcd = 0,delab = 0;
	for(delab = 2 ; 9 * delab < 2 * n ; delab += 2){
		sum[n+1] = 0;
		delcd = delab >> 1;
		for(int c = n ; c >= 1 ; -- c){
			sum[c] = sum[c+1] + cnt[c]*cnt[c+delcd];
		}
		for(int a = 1 ; a + delab <= n ; ++ a){
			int b = a + delab;
			if(!cnt[a] || !cnt[b])continue;
			int c = 3*delab + b + 1;
			if(c > n)continue;
			ans[a][0] += sum[c]*cnt[b];
			ans[b][1] += sum[c]*cnt[a];
		}
	}
	for(delcd = 1 ; 9 * delcd < n ; ++delcd){
		sum[0] = 0;
		delab = delcd << 1;
		for(int b = 1 ; b <= n ; ++ b){
			if(b - delab < 1)sum[b] = 0;
			else sum[b] = sum[b-1] + cnt[b]*cnt[b-delab];
		}
		for(int c = 1 ; c + delcd <= n ; ++ c){
			int d = c + delcd;
			if(!cnt[c] || !cnt[d])continue;
			int b = c - 6 * delcd - 1;
			if(b < 1)continue;
			ans[c][2] += sum[b]*cnt[d];
			ans[d][3] += sum[b]*cnt[c];
		}
	}
	for(int i = 1 ; i <= m ; ++ i){
		for(int j = 0 ; j < 4 ; ++ j){
			printf("%d",ans[num[i]][j]);
			if(j == 3)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
