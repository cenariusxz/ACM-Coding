#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct leg{
	int l,c;
	bool operator < (const leg a)const{
		if(l==a.l)return c<a.c;
		return l<a.l;
	}
}l[100005];

int num[100005],sum[100005],s[100005];
int d[205];

int cmp(leg a,leg b){
	return a.c<b.c;
}

int main(){
	int n;
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&l[i].l);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&l[i].c);
	}
	sort(l+1,l+n+1);
	int pos=0,cnt=0;
	for(i=1;i<=n;i++){
		s[i]=s[i-1]+l[i].c;
		if(l[i].l==pos){
			num[cnt]++;
		}
		else{
			pos=l[i].l;
			num[++cnt]++;
		}
	}
	for(i=1;i<=cnt;i++){
		sum[i]=sum[i-1]+num[i];
	}
	int ans=0x3f3f3f3f,j;
//	for(i=1;i<=n;i++)printf("%d ",s[i]);
//	printf("\n");
	for(i=1;i<=cnt;i++){
		int tmp=s[sum[cnt]]-s[sum[i]];
		int m=n-(num[i]+num[i]-1);
	//	printf("%d %d %d\n",tmp,m,sum[cnt]-sum[i]);
		if(m>sum[cnt]-sum[i]){
			int x=m-sum[cnt]+sum[i];
			for(j=1;j<=200&&x;j++){
				if(x<d[j]){
					tmp+=x*j;
					x=0;
				}
				else{
					tmp+=d[j]*j;
					x-=d[j];
				}
			}
		}
		if(tmp<ans)ans=tmp;
		for(j=sum[i-1]+1;j<=sum[i];j++){
			d[l[j].c]++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
