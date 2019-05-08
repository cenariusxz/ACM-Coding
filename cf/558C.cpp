#include<stdio.h>

int vis[100005],num[100005],a[100005],maxx=0;

void cha(int tmp,int cnt){
	tmp*=2;
	while(tmp<=maxx){
		vis[tmp]++;
		num[tmp]+=cnt++;
		tmp*=2;
	}
}

int main(){
	int n,i,j,ans=0x3f3f3f3f;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>maxx)maxx=a[i];
	}
	for(i=1;i<=n;i++){
		int tmp=a[i],cnt=0;
		while(tmp>1){
			if(tmp%2)cha(tmp/2,cnt+2);
			vis[tmp]++;
			num[tmp]+=cnt++;
			tmp/=2;
		}
		vis[1]++;
		num[1]+=cnt;
		cnt=1;
		tmp=a[i]*2;
		while(tmp<=maxx){
			vis[tmp]++;
			num[tmp]+=cnt++;
			tmp*=2;
		}
	}
	for(i=1;i<=maxx;i++){
		if(vis[i]==n){
			if(ans>num[i])ans=num[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}
