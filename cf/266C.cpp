#include<stdio.h>
#include<string.h>
typedef long long ll;

int a[500005];
int num[500005];
ll s[500005];

ll C(int n,int k){
	int i;
	ll ans=1;
	for(i=1;i<=k;i++){
		ans*=(n-i+1);
		ans/=i;
	}
	return ans;
}

int main(){
	int n,i;
	s[0]=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	if(!(s[n]%3)){
		ll b=s[n]/3,ans3=0;
		int ans=0,ans2=0;
		if(b){
			for(i=1;i<=n;i++){
				if(s[i]==b)num[++ans]=ans2;
				else if(s[i]==b*2)ans2++;
			}
			for(i=1;i<=ans;i++){
				ans3+=ans2-num[i];
			}
		}
		else{
			for(i=1;i<=n;i++){
				if(s[i]==b)ans3++;
			}
			ans3=C(ans3-1,2);
		}
		printf("%I64d\n",ans3);
	}
	else printf("0\n");
}
