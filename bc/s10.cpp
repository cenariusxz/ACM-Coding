#include<stdio.h>
#include<string.h>
typedef long long ll;

ll lcm(ll a,ll b){
	ll t;
	ll tmp=a*b;
	while(b){
        t=a%b;
        a=b;
		b=t;
	}
	a=tmp/a;
	return a;
}

ll gcd(ll a,ll b){
	ll t;
	while(b){
        t=a%b;
        a=b;
		b=t;
	}
	return a;
}

ll aa[1005];
int a[1005],b[1005],ans[1005];

int main(){
	int T;
	scanf("%d",&T);
	for(int Q=1;Q<=T;Q++){
		int n,q;
		scanf("%d%d",&n,&q);
		int i,j;
		for(i=1;i<=n;i++)aa[i]=1;
		for(i=1;i<=q;i++){
			scanf("%d%d%d",&a[i],&b[i],&ans[i]);
			for(j=a[i];j<=b[i];j++){
				if(aa[j]%ans[i]){
					aa[j]=lcm(aa[j],ans[i]);
				}
			}
		}
		bool f=1;
		for(i=1;i<=q&&f;i++){
			ll tmp=aa[a[i]];
			for(j=a[i]+1;j<=b[i];j++){
				tmp=gcd(tmp,aa[j]);
			}
			if(tmp!=ans[i])f=0;
		}
		
		if(!f)printf("Stupid BrotherK!\n");
		else{
			for(i=1;i<=n;i++){
				printf("%lld",aa[i]);
				if(i==n)printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}
