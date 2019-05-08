#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[105];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(a,0,sizeof(a));
		int i,b;
		for(i=1;i<=n;i++){
			scanf("%d",&b);
			a[b]++;
		}
		int k;
		scanf("%d",&k);
		sort(a+1,a+n+1);
		for(i=1;i<=n&&k;i++){
			if(a[i]>1){
				if(a[i]-1<=k){
					k-=(a[i]-1);
					a[i]=1;
				}
				else{
					a[i]-=k;
					k=0;
				}
			}
		}
		int ans=0;
		for(i=1;i<=n;i++){
			if(a[i])ans++;
		}
		printf("%d\n",ans-k);
	}
	return 0;
}
