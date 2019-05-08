#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int v[11][1050][11];
int c[12][11]={{1},{1,-1},{1,-2,1},{1,-3,3,-1},{1,-4,6,-4,1},{1,-5,10,-10,5,-1},{1,-6,15,-20,15,-6,1},{1,-7,21,-35,35,-21,7,-1},{1,-8,28,-56,70,-56,28,-8,1},{1,-9,36,-84,126,-126,84,-36,9,-1},{1,-10,45,-120,210,-252,210,-120,45,-10,1}};

void init(){
	int i,j,k,p;
	memset(v,0,sizeof(v));
	v[0][1][0]=1;
	for(i=1;i<=9;i++){
		for(j=1;j<(1<<(i+1));j++){
			for(k=0;k<=i;k++){
				if(j&(1<<k)){
					for(p=0;p<=k;p++){
						v[i][j][p+i-k]+=c[k][p];
					}
				}
			}
		}
	}
}

int num[11];

int dfs(int l){
	int i,j;
	if(l==0){
		if(num[0]==1)return 1;
		else return 0;
	}
	int ans=0;
	if(num[l]==0)ans+=dfs(l-1);
	for(i=1;i<(1<<(l+1));i++){
		if(num[l]+v[l][i][l]==0){
			for(j=0;j<=l;j++){
				num[j]+=v[l][i][j];
			}
			ans+=dfs(l-1);
			for(j=0;j<=l;j++){
				num[j]-=v[l][i][j];
			}
		}
	}
	return ans;
}

int main(){
//	freopen("immetric.in","r",stdin);
//	freopen("immetric.out","w",stdout);
	int n,i,j;
	init();
	int cnt=0;
	while(scanf("%d",&n)!=EOF&&n){
		int ans=0;
		for(i=1;i<(1<<(n+1));i++){
			if(v[n][i][n]==0){
				for(j=0;j<=n;j++)num[j]=v[n][i][j];
				ans+=dfs(n-1);
			}
		}
		printf("Case #%d: %d\n",++cnt,ans);
	}
	return 0;
}
