#include<stdio.h>
#include<string.h>
typedef long long ll;

int a[10005];

int gcd(int a,int b){
	while(b){
		int t=a%b;
		a=b;
		b=t;
	}
	return a;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(a,0,sizeof(a));
		int b,i,j,k,m=0;
		int ans=0;
		for(i=1;i<=n;i++){
			scanf("%d",&b);
			if(b>m)m=b;
			a[b]++;
		}
		for(i=2;i<=m;i++){
			int tmp=0;
			ans+=((((a[i]*a[i])%10007)*i%10007)*(i-1)%10007)%10007;
			for(j=1;i*j<=m&&a[i*j];j++){
				for(k=j+1;k*i<=m&&a[i*k]&&gcd(j,k)==1;k++){
					tmp+=(((((a[i*j]*a[i*k])%10007)*i)%10007)*(i-1)%10007)%10007;
				}
			}
			tmp=tmp*2%10007;
			ans=(ans+tmp)%10007;
		}
		printf("%d\n",ans);
	}
	return 0;
}
