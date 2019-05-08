#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=205;
ll a[maxn];
int vis[maxn];
int l[maxn],r[maxn];

int main(){
	int T,cnt=0;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		ll ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i){
			ll num;
			scanf("%I64d",&num);
			ans+=num;
		}
		for(int i=1;i<=n;++i){
			scanf("%I64d",&a[i]);
		}
		for(int i=1;i<=n;++i){
			int maxx=-0x3f3f3f3f;
			int pos=0,hit=0;
			for(int j=1;j<=n;++j){
				if(vis[j])continue;
				int tmp=0,k,p,temp=0;
				l[j]=r[j]=-1;
				for(k=j-1;k>=1;--k){
					if(!vis[k])break;
				}
				if(k>=1)l[j]=k;
				for(p=j+1;p<=n;++p){
					if(!vis[p])break;
				}
				if(p<=n)r[j]=p;
				if(l[j]==-1&&r[j]==-1)pos=j;
				else{
					if(l[j]==-1){
						tmp=a[j];
						temp=a[p];
					}
					else if(r[j]==-1){
						tmp=a[j];
						temp=a[k];
					}
					else{
						tmp+=a[j]-a[k];
						tmp+=a[j]-a[p];
						temp+=a[k]+a[p];
					}
					if(pos==0){
						maxx=tmp;
						pos=j;
						hit=temp;
					}
					else if(tmp>maxx){
						maxx=tmp;
						pos=j;
						hit=temp;
					}
					else if(tmp==maxx&&hit>temp){
						maxx=tmp;
						pos=j;
						hit=temp;
					}
				}
			}
		//	printf("%d %d %d\n",pos,l[pos],r[pos]);
			vis[pos]=1;
		//	if(~l[pos])ans+=a[l[pos]];
		//	if(~r[pos])ans+=a[r[pos]];
			ans+=hit;
		}
		printf("Case #%d: %I64d\n",++cnt,ans);
	}
	return 0;
}
