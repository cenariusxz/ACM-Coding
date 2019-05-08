#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int a[15];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int sum=0;
		for(int i=1;i<=n;++i)sum+=a[i];
		int ans=sum/2;
		int maxx=-1;
		for(int i=1;i<=n;++i)if(a[i]>maxx)maxx=a[i];
		int tmp=ans/2;
		printf("Case #%d: ",q);
		if(sum-maxx>=tmp)printf("%d\n",ans);
		else printf("%d\n",(sum-maxx)*2+1);

	}
	return 0;
}
