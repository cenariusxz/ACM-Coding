#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> sons[100005];
int w[100005],f[100005];
long long ans[100005];

void dfs(int s){
	ans[s]=w[s];
	for(int i=0;i<sons[s].size();++i){
		int j=sons[s][i];
		dfs(j);
		ans[s]+=ans[j];
	}
}

int main(){
	scanf("%d%d",&n,&w[1]);
	for(int i=2;i<=n;++i){
		scanf("%d%d",&f[i],&w[i]);
		sons[f[i]].push_back(i);
	}
	dfs(1);
	int q;
	scanf("%d",&q);
	while(q--){
		int id;
		scanf("%d",&id);
		printf("%lld\n",ans[id]);
	}
	return 0;
}

