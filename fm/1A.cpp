#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int a[20005],b[20005];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n+m){
		int i;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=m;i++)scanf("%d",&b[i]);
		sort(a+1,a+n+1);
		sort(b+1,b+m+1);
		int cnt=1;
		long long sum=0;
		for(i=1;i<=n;i++){
			while(cnt<=m&&b[cnt]<a[i])cnt++;
			sum+=b[cnt];
			cnt++;
		}
		if(cnt>m+1)printf("Loowater is doomed!\n");
		else printf("%lld\n",sum);
	}
	return 0;
}
