#include<stdio.h>
#include<string.h>
typedef long long ll;
int m1[1000005],m2[1000005];

int main(){
	int m,i;
	ll h1,h2,a1,a2,y1,y2,x1,x2;
	memset(m1,-1,sizeof(m1));
	memset(m2,-1,sizeof(m2));
	
	scanf("%d",&m);
	scanf("%lld%lld",&h1,&a1);
	scanf("%lld%lld",&x1,&y1);
	scanf("%lld%lld",&h2,&a2);
	scanf("%lld%lld",&x2,&y2);
	m1[h1]=0;
	ll pos=h1;
	ll k1,k2;
	for(i=1;i<=m+10;i++){
		pos=(x1*pos+y1)%m;
		if(m1[pos]==-1){
			m1[pos]=i;
		}
		else{
			k1=i-m1[pos];
			break;
		}
	}
	m2[h2]=0;
	pos=h2;
	for(i=1;i<=m+10;i++){
		pos=(x2*pos+y2)%m;
		if(m2[pos]==-1){
			m2[pos]=i;
		}
		else{
			k2=i-m2[pos];
			break;
		}
	}
	printf("%lld %lld\n",k1,k2);
	if(m1[a1]==-1||m2[a2]==-1){
		printf("-1\n");
		return 0;
	}
	if(x1==0){
		printf("%d\n",m2[a2]);
		return 0;
	}
	if(x2==0){
		printf("%d\n",m1[a1]);
		return 0;
	}
	int p1=m1[a1],p2=m2[a2];
	ll ans=-1;
	for(i=0;i<=k2&&ans==-1;i++){
		ll sum=i*k1+p1;
		if(sum%k2==p2)ans=sum;
	}
	printf("%lld\n",ans);
	return 0;
}
