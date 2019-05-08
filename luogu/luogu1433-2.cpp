#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

double x[20],y[20];
int vis[20],que[20],n;
double ans = 1e60;

double cal(int i,int j){
	return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}

void dfs(int t){
	if(t == n){
		double dis = 0;
		for(int i = 1 ; i <= n ; ++ i)dis += cal(que[i-1],que[i]);
		if(dis < ans) ans = dis;
		return;
	}
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i])continue;
		vis[i] = 1;
		que[t+1] = i;
		dfs(t+1);
		vis[i] = 0;	
	}
}

int main(){
	x[0] = 0, y[0] = 0;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%lf%lf",&x[i],&y[i]);	
	}
	dfs(0);
	printf("%.2lf\n",ans);
	return 0;
	return 0;
}

