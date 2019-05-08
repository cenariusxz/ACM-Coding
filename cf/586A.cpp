#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;

int a[105];
int vis[105];

int main(){
	int n;
	scanf("%d",&n);
	int ans=0;
	bool f=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int l=1,r=n;
	for(int i=n;i>=1&&a[i]==0;--i){
		vis[i]=1;
		r=i;
	}
	for(int i=1;i<=n&&a[i]==0;++i){
		vis[i]=1;
		l=i;
	}
	int i=l;
	while(i<=r){
		if(a[i]==1){
			while(i<=r&&a[i]==1){
				i++;
			}
		}
		else{
			int pre=i,num=0;
			while(i<=r&&a[i]==0){
				num++;
				i++;
			}
			if(num>1){
				for(int j=pre;j<i;++j)vis[j]=1;
			}
		}
	}
	for(int j=1;j<=n;++j)if(!vis[j])ans++;
	printf("%d\n",ans);
	return 0;
}
