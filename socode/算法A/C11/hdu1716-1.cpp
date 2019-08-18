#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int cnt[maxn], vis[10], pre = 0;
int num[10];

void dfs(int t, int sum){
	if(t == 4){
		if(sum >=1000 && !cnt[sum]){
			if(sum / 1000 == pre / 1000)printf(" ");
			else if(pre != 0)printf("\n");
			printf("%d",sum);
			cnt[sum]++;
			pre = sum;
		}
		return;
	}
	for(int i = 1 ; i <= 4 ; ++ i){
		if(vis[i])continue;
		vis[i] = 1;
		dfs(t+1, sum*10+num[i]);
		vis[i] = 0;	
	}
}

int main(){
	int t = 0;
	while(scanf("%d%d%d%d",&num[1], &num[2], &num[3], &num[4])){
		if(num[1]+num[2]+num[3]+num[4] == 0)break;
		if(t)printf("\n");
		t++;
		memset(cnt,0,sizeof(cnt));
		pre = 0;
		sort(num+1, num+1+4);
		dfs(0, 0);
		printf("\n");
	}
	return 0;
}

