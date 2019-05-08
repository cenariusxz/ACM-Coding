#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=15;

int a[maxn];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int b;
		scanf("%d",&b);
		a[b]++;
	}
	int ans=0;
	int sum=0;
	for(int i=1;i<=m;++i){
		ans+=sum*(a[i]);
		sum+=a[i];
	}
	printf("%d\n",ans);
	return 0;
}
