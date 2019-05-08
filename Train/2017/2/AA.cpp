#include<stdio.h>
#include<string.h>

long long a[20000],b[20000];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int aa=n/2016,bb=m/2016;
		for(int i=0;i<2016;++i){
			a[i]=aa;
			if(i!=0){
				if(n%2016>=i)a[i]++;
			}
			b[i]=bb;
			if(i!=0){
				if(m%2016>=i)b[i]++;
			}
		}
		long long ans=0;
		for(int i=0;i<=2016;++i){
			for(int j=0;j<=2016;++j){
				if(i*j%2016==0)ans+=a[i]*b[j];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
