#include <stdio.h>
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int a[15];
int vis[15], d1[20], d2[20];	// 列、主对角线、副对角线 
int cnt = 0, n;

void dfs(int t){
	if(t == 8){
		cnt ++;
		if(cnt == n){
			for(int i = 1 ; i <= 8 ; ++ i){
				printf("%d",a[i]);
			}
			printf("\n");
		}
		return;
	}
	for(int i = 1 ; i <= 8 ; ++ i){
		if(vis[i] || d1[t+1 - i + 8] || d2[t+1 + i])continue;
		// t+1 , i
		vis[i] = 1;
		d1[t+1 - i + 8] = 1;
		d2[t+1 + i] = 1;
		a[t+1] = i;
		dfs(t+1);
		if(cnt >= n)return;
		vis[i] = 0;
		d1[t+1 - i + 8] = 0;
		d2[t+1 + i] = 0;
		a[t+1] = 0;
	}
}

int main(){
	scanf("%d",&n);
	dfs(0);
	return 0;
}

