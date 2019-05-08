#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=5e5+5;
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;

int a[maxn];
int res[maxn];
int l[maxn],r[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	bool f=0;
	int ans=0;
	memset(res,-1,sizeof(res));
	res[1]=a[1];
	int cnt=0;
	for(int i=2;i<=n;++i){
		if(!f){
			if(a[i]!=a[i-1]){
				l[++cnt]=i-1;
				f=1;
			}
		}
		if(f){
			if(a[i]==a[i-1]){
				r[cnt]=i-1;
				f=0;
				int num=r[cnt]-l[cnt];
				if(num/2>ans)ans=num/2;
			}
		}
	}
	if(f){
		r[cnt]=n;
		int num=r[cnt]-l[cnt];
		if(num/2>ans)ans=num/2;
	}
	for(int i=1;i<=cnt;++i){
		if(a[l[i]]==a[r[i]]){
			for(int j=l[i];j<=r[i];++j)res[j]=a[l[i]];
		}
		else{
			for(int j=l[i];j<=(l[i]+r[i])/2;++j)res[j]=a[l[i]];
			for(int j=(l[i]+r[i])/2+1;j<=r[i];++j)res[j]=a[r[i]];
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i){
		if(res[i]==-1)printf("%d",a[i]);
		else printf("%d",res[i]);
		if(i==n)printf("\n");
		else printf(" ");
	}
	return 0;
}
