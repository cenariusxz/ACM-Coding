#include<stdio.h>
#include<string.h>
#include<bitset>
using namespace std;

int a[1005][1005];

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	int q;
	scanf("%d",&q);
	int ans=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			ans+=a[i][j]*a[j][i];
		}
	}
	ans%=2;
	int cnt=0;
	for(i=1;i<=q;i++){
		int as;
		scanf("%d",&as);
		if(as==1||as==2){
			int b;
			scanf("%d",&b);
			cnt++;
		}
		if(as==3){
			if(cnt%2)printf("%d",!ans);
			else printf("%d",ans);
		}
	}
	printf("\n");
	return 0;
}
