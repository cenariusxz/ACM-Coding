#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;

int v[maxn];
int vis[maxn];
int res[maxn];

int main(){
	int n,s;
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;++i)scanf("%d",&v[i]);
	sort(v+1,v+n+1);
	int pos1=1,pos2=n;
	int ans=0;
	int cnt=0;
	while(pos1<pos2){
		if(v[pos1]+(ll)v[pos2]<=s)pos1++;
		else{
			res[++cnt]=v[pos1];
			res[++cnt]=v[pos2];
			ans+=2;
			vis[pos1]=1;
			vis[pos2]=1;
			pos1++;
			pos2--;
		}
	}
	for(int i=n;i>=1;--i){
		if(!vis[i]){
			res[++cnt]=v[i];
		}
	}
	ans=0;
	int sum=0,num=0;
	for(int i=1;i<=n;++i){
		if(i<n&&res[i]+(ll)res[i+1]>s){
			ans++;
		}
		else{
			ans++;
			i++;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i){
		printf("%d",res[i]);
		if(i==n)printf("\n");
		else printf(" ");
	}

	return 0;
}
