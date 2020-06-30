#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;
vector<int>vec;
int vis[10][10];
int ans=INF;
char c[3];
int w=0;
void dfs(int depth){
	if(depth==4){
		ans=min(ans,vec[0]);
	}
	for(int i=0;i<vec.size();i++){
//		if(vis[i])continue;
		for(int j=0;j<vec.size();j++){
			printf("(%d %d)",i,j);	
			if(vis[i][j])continue;
			int x=vec[i];
			int y=vec[j];
			if(c[4-vec.size()]=='+')vec.push_back(x+y);
			else vec.push_back(x*y);
			vec.erase(vec.begin()+i); 
			vec.erase(vec.begin()+j);
			sort(vec.begin(),vec.end());
			dfs(depth+1);
			vec.push_back(x);
			vec.push_back(y);
			sort(vec.begin(),vec.end());
			vis[i][j]=vis[j][i]=1;
		}
	}
}
int main(){
	vec.resize(4);
	for(int i=0;i<4;i++)cin>>vec[i];
	for(int i=0;i<3;i++)cin>>c[i];
	
	dfs(1);
	printf("%d\n",ans);
	return 0;
}


