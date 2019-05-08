#include<stdio.h>
#include<string.h>

typedef long long ll;

int main(){
//	freopen("stdin","r",stdin);
//	freopen("stdout","w",stdout);
	ll pnow,ppre;
	int a,b;
	scanf("%d%d",&a,&b);
	ppre=a;pnow=b;
	int cnt=2;
	int f=0;
	while(1){
		cnt++;
		ll t=pnow;
		pnow=ppre-pnow;
		ppre=t;
		if(pnow<0)break;
		if(cnt>=100){
			f=1;
			break;
		}
	}
	if(f)printf("0 0\n");
	else printf("%d %lld\n",cnt,pnow);
	return 0;
}
