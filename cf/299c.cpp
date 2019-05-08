#include<stdio.h>
#include<string.h>
#include<math.h>
typedef long long ll;

ll a,b,n;
ll l,t,m,ans=0,sl;

ll run(ll p,ll sp){
	if(sp>t)return -1;
	if((sl+sp)*(p-l+1)/2>m*t)return -1;
	return p;
}

int main(){
	scanf("%I64d%I64d%I64d",&a,&b,&n);
	for(int q=1;q<=n;q++){
		scanf("%I64d%I64d%I64d",&l,&t,&m);
		sl=a+(l-1)*b;
		if(t<sl)ans=-1;
		else if(t==sl)ans=l;
		else{
			ans=-1;
			ll le=l;
			ll r=(b-2*sl+sqrt((2*sl-b)*(2*sl-b)*1.0+8*m*t*b))/(2*b);
			r=r+l;
			while(le<=r){	
				ll mid=(le+r)/2;
				ll sp=a+(mid-1)*b;
				ll tmp=run(mid,sp);
				if(tmp==-1)r=mid-1;
				else{
					le=mid+1;
					if(ans<tmp)ans=tmp;
				}
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
