#include<stdio.h>
#include<string.h>
typedef long long ll;

int n,m,s;

ll cal(int a,int b,int c,int d){
	ll ans=0;
	ans+=(ll)(n-2*d)*(ll)(m-2*a);
	ll tmp=ans*2;
	return tmp;
}

int main(){
	scanf("%d%d%d",&n,&m,&s);
	int i,j,k,p;
	ll ans=0;
	if(s%2){
		for(i=1;i<=s;i++){
			if(!(s%i)){
				int t=s/i;
				int b=i/2,a=t/2;
				if(t<=m&&i<=n){
					if(i!=t){
						ans+=((ll)(a+1)*(ll)(b+1)*2-1)*(ll)(n-i+1)*(ll)(m-t+1);
					}
					else{
						ans+=(((ll)(a+1)*(ll)(b+1))*2-1)*(ll)(n-i+1)*(ll)(m-t+1);
					}
				}
			}
		}
	}
	for(i=3;i<=m;i+=2){
		for(j=1;j<n;j+=2){
			for(k=1;k<i;k+=2){
				int a=i/2,b=j/2,c=k/2,d;
				if(!((s+4*b*c-4*a*b-2*a-1)%(4*c+2))){
					d=(s+4*b*c-4*a*b-2*a-1)/(4*c+2);
					p=2*d+1;
					if(p>j&&p<=n){
						ans+=cal(a,b,c,d);
					}
				}
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
