#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int a,b;

int dfs(int a,int b){		// 1 first-win 0 first-lose
	if(a < b)swap(a,b);
	if(a % b == 0)return 1;
	for(int i = b ; i <= a ; i += b){
		if(dfs(a-i,b) == 0)return 1;
	}
	return 0;
}

int main(){
	while(scanf("%d%d",&a,&b)!=EOF){
		if(a == 0 && b == 0)break;
		if(dfs(a,b))printf("win\n");
		else printf("lose\n");	
	}
	return 0;
}

