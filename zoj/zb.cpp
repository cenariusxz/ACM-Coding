#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int a[100005];
int num[35];

bool cmp(int a,int b){
	return a>b;
}
int c[35];
void init(){
	c[0]=1;
	for(int i=1;i<=32;i++){
		c[i]=c[i-1]*2;
	}
}


int main(){
	int t;
	init();
	while(scanf("%d",&t)!=EOF){
		for(int q=1;q<=t;q++){
			memset(num,0,sizeof(num));
			int n;
			scanf("%d",&n);
			int i,j,ans=0;
			for(i=1;i<=n;i++)scanf("%d",&a[i]);
			sort(a+1,a+n+1,cmp);
			for(i=1;i<=n;i++){
				int tmp=a[i];
				if(a[i]==0)num[0]++;
				int cnt=0;
				while(tmp){
					if(!(tmp&1))num[cnt]++;
					cnt++;
					bool f=1;
					if(tmp==1)f=0;
					tmp>>=1;
					if(f&&tmp==0)num[0]++;
				}
				for(j=0;j<=31;j++){
					if(a[i]>=c[j]&&a[i]<c[j+1]){
                        ans+=num[j];
                        break;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
