#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int i,j;
	int ans=0,cnt2=0;
	for(i=1;i<=k;i++){
		int m;
	 	scanf("%d",&m);
		int a,tmp=-1,cnt=0;
		for(j=1;j<=m;j++){
			scanf("%d",&a);
			if(cnt&&a==tmp+1){
				cnt++;
				cnt2=cnt;
			}
			else{
				cnt=0;
			}
			if(a==1)cnt2=cnt=1;
			tmp=a;
		}
	}
	ans+=n-k-(cnt2-1);
	ans+=n-1-(cnt2-1);
	printf("%d\n",ans);
	return 0;
}
