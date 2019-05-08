#include<stdio.h>
#include<string.h>
typedef long long ll;

ll a[55];
void init(){
	a[0]=1;
	for(int i=1;i<=50;i++){
		a[i]=a[i-1]*2;
	}
}

int main(){
	init();
	ll n,h;
	scanf("%lld%lld",&h,&n);
	ll l=1,r=a[h];
	bool f=1;	//1 left 0 right;
	ll ans=1;
	int h1=h;
//	ll mid=l+(r-l)/2;	//mid 在左
	while(l<r){
		ll mid=l+((r-l)>>1);
		if(n<=mid){
			if(f){
				ans+=1;
			}
			else{
				ans+=a[h1];
			}
			f=0;
			r=mid;
		}
		else{
			if(f){
				ans+=a[h1];
			}
			else{
				ans+=1;
			}
			f=1;
			l=mid+1;
		}
		h1--;
	}
	printf("%lld\n",ans-1);
	return 0;
}
