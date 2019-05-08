#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
const int INF = 0x3f3f3f3f;

int factor[10],fnum[10],cnt;
int s[maxn];
int n,m1,m2;

void run1(){
	cnt = 0;
	for(int i = 2 ; i * i <= m1 ; ++ i){
		if(m1 % i)continue;
		cnt++;
		factor[cnt] = i;
		while(m1 % i == 0)m1/=i,fnum[cnt]++;
	}
	if(m1 > 1){
		cnt++;
		factor[cnt] = m1;
		fnum[cnt] = 1;
	}
}

void solve(){
	int ans = INF;
	for(int i = 1 ; i <= n ; ++ i){
		int tmp = 0;
		for(int j = 1 ; j <= cnt ; ++ j){
			if(s[i] % factor[j]){
				tmp = -1;
				break;
			}
			int tmpcnt = 0;
			while(s[i] % factor[j] == 0){
				s[i] /= factor[j];
				tmpcnt++;
			}
			int sum = fnum[j] * m2;
			int res = sum / tmpcnt;
			if(sum % tmpcnt)res++;
			if(res > tmp)tmp = res;
		}
		if(tmp != -1)ans = min(ans,tmp);
	}
	if(ans == INF)printf("-1\n");
	else printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d%d",&n,&m1,&m2)!=EOF){
		for(int i = 1 ; i <= n ; ++ i)scanf("%d",&s[i]);
		if(m1 == 1){
			printf("0\n");
			continue;
		}
		run1();
		solve();
	}
	return 0;
}
