#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;
int n,r;
int p[2005],vis[2005];
int cnt;
int solve(){
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			cnt++;
			bool flag=0;
			int pos=-1;
			for(int j=i+r-1;j>0;j--){
				if(p[j]==1){
					pos=j;
					flag=1;
					break;
				}
			}
			if(flag==0)return -1;
			for(int j=pos;j<pos+r;j++)vis[j]=1;
			for(int j=pos-r;j<=pos;j++)vis[j]=1;
		}
	}
	return cnt;
}
int main(){
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		if(p[i]==1)vis[i]=1;
	}
	printf("%d",solve());
	return 0;
}


