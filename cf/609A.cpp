#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=105;
int a[maxn];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=n;i>=1;--i){
		if(m>0){
			m-=a[i];
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
