#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int a[100005];
int b[100005];

bool cmp(int a,int b){
	return a>b;
}

int gcd(int a,int b){
	while(b){
		int t=a%b;
		a=b;
		b=t;
	}
	return a;
}

int main(){
	int t;
	while(scanf("%d",&t)!=EOF){
		for(int q=1;q<=t;q++){
			int n,i,j;
			memset(b,0,sizeof(b));
			scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[a[i]]++;
		}
		sort(a+1,a+n+1,cmp);
		int p=a[1]/2;
		bool f=1;
		int ans;
		for(i=1;i<=n&&a[i]>p&&f;i++){
			int tmp=a[i],c,cnt=0;
			for(c=1;c*tmp<=a[1]&&f;c++){
				cnt+=b[c*tmp];
				if(cnt>=2){
					f=0;
					ans=tmp;
				}
			}
		}
		for(i=p;i>=1&&f;i--){
			int c,cnt=0;
			for(c=1;c*i<=a[1]&&f;c++){
				cnt+=b[c*i];
				if(cnt>=2){
					f=0;
					ans=i;
				}
			}
		}
		printf("Case #%d: %d\n",q,ans);
		}
	}
	return 0;
}
