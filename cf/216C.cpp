#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int que[100000],cnt;

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	cnt=0;
	for(int i=1;i<=k;++i)que[++cnt]=1;
	for(int t=2;t<=n+m;++t){
		int tmp=0;
		for(int i=1;i<=cnt;++i){
			if(que[i]+n-1>=t)tmp++;
		}
		if(!tmp)que[++cnt]=t-1,tmp++;
		for(int i=tmp+1;i<=k;++i)que[++cnt]=t;
	}
	bool f=0;
	for(int i=1;i<=cnt;++i){
		if(que[i]+n-1>=n+m&&que[i]+n-1>=n+m+1)f=1;
	}
	if(!f)que[++cnt]=n+m;
	sort(que+1,que+cnt+1);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i)printf("%d ",que[i]);
	printf("\n");
	return 0;
}
