#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;

int main(){
	int n,s,t;
	while(scanf("%d%d%d",&n,&s,&t)!=EOF){
		int ans=2;
		if(s==1||t==1)ans--;
		if(s==n||t==n)ans--;
		if((s>1&&t==n)||(s<n&&t==1))ans=2;
		if(n>2&&(s==t+1||s==t-1))ans=1;
		if(s!=1&&s!=n&&t!=1&&t!=n&&(s>t+1||s<t-1))ans=2;
		if(s==t&&n>1)ans=-1;
		if(s==t&&n==1)ans=0;
		printf("%d\n",ans);
	}
	return 0;
}
