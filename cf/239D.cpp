#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int a[100005];

int main(){
	int n,h;
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&h);
	int i,j;
	int minn=0x7fffffff,pos=0,ans;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<minn){
			minn=a[i];
			pos=i;
		}
	}
	sort(a+1,a+n+1);
	bool f=0;
	int ans1=a[n]+a[n-1]-a[1]-a[2];
	int ans2=max(a[n-1]+a[n],a[n]+a[1]+h)-min(a[1]+a[2]+h,a[2]+a[3]);
	if(ans1<ans2){
		ans=ans1;
	}
	else{
		ans=ans2;
		f=1;
	}
	printf("%d\n",ans);
	if(!f){
		for(i=1;i<=n;i++)printf("1 ");
		printf("\n");
	}
	else{
		for(i=1;i<=n;i++){
			if(i==pos)printf("2 ");
			else printf("1 ");
		}
		printf("\n");
	}
	return 0;
}
