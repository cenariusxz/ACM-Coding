#include<stdio.h>
#include<string.h>
typedef long long ll;

ll d[200005];
ll s,a;
int n;

void run(int i){
	ll ans1,ans2;
	ll lim1=n-1+d[i],lim2=s-d[i]+1;
	if(a<lim1)ans1=a-n+1;
	else ans1=d[i];
	if(a>lim2)ans2=d[i]-(s-a);
	else ans2=1;
	ll ans=ans1-ans2+1;
	printf("%I64d",d[i]-ans);
}

int main(){
	int i;
	s=0;
	scanf("%d%I64d",&n,&a);
	for(i=1;i<=n;i++){
		scanf("%I64d",&d[i]);
		s+=d[i];
	}
	for(i=1;i<=n;i++){
		run(i);
		if(i==n)printf("\n");
		else printf(" ");
	}
	return 0;
}
