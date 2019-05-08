#include<stdio.h>
#include<string.h>
typedef long long ll;
const int maxm=1e5+5;

ll num[maxm],sum[maxm];
int fa[maxm];

int main(){
	int i,j;
	for(i=2;i<=1e5;++i){
		sum[i]=sum[i-1];
		for(j=2;j*j<=i;++j){
			if(!(i%j)){
				if(!num[i]){
					num[i]=i/j;
					sum[i]+=num[i];
				}
				if(num[j]!=j&&num[j]>maxx){
					maxx=num[j];
					pos=j;
				}
				if(num[i/j]!=i/j&&num[i/j]>maxx){
					maxx=num[i/j];
					pos=i/j;
				}
			}
		}
		if(!num[i]){
			num[i]=1;
			sum[i]++;
		}
	}
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%lld\n",sum[n]);
	}
	return 0;
}
