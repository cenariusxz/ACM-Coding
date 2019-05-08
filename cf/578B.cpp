#include<stdio.h>
#include<string.h>
#include<algorithm>
typedef long long ll;
const int maxn=2e5+5;
int a[maxn];
int b[maxn];
ll num[50];

int main(){
	memset(b,0,sizeof(b));
	memset(num,0,sizeof(num));
	int n,k,x,maxx=0;
	scanf("%d%d%d",&n,&k,&x);
	ll mult=1;
	for(int i=1;i<=k;++i)mult*=x;
	ll ans=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		int tmp=a[i],cnt=0;
		while(tmp){
			num[cnt++]+=tmp%2;
			tmp/=2;
		}
		b[i]=cnt;
		if(cnt>maxx)maxx=cnt;
		ans|=a[i];
	}
	ll res=0;
	for(int i=1;i<=n;++i){
		if(b[i]==maxx){
			int tmp=a[i],cnt=0;
			ll temp=ans;
			while(tmp){
				if(tmp%2){
					if(num[cnt]==1){
						temp-=(1<<cnt);
					}
				}
				tmp/=2;
				cnt++;
			}
			temp|=((ll)a[i]*mult);
			if(temp>res)res=temp;
		}
	}
	printf("%lld\n",res);
	return 0;
}
