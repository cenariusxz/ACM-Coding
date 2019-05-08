#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

struct ing{
	int num;
	double a,b,g,p;
	bool operator<(const ing a)const{
		return p>a.p;
	}
}d[100005];

double ans[100005];

int main(){
	freopen("burrito.in","r",stdin);
	freopen("burrito.out","w",stdout);
	int A,B,n;
	scanf("%d%d%d",&n,&A,&B);
	int i;
	memset(d,0,sizeof(d));
	memset(ans,0,sizeof(ans));
	for(i=1;i<=n;i++){
		scanf("%lf%lf%lf",&d[i].g,&d[i].a,&d[i].b);
		d[i].num=i;
		if(d[i].b==0){
			d[i].p=1000000;
		}
		else{
			d[i].p=d[i].a/d[i].b;
		}
	}
	sort(d+1,d+n+1);
	double sum1=0,sum2=0;
	for(i=1;i<=n;i++){
		if(d[i].b==0){
			ans[d[i].num]=d[i].g;
			sum1+=d[i].g*d[i].a;
		}
		else if((B-sum2)/d[i].b>d[i].g){
			ans[d[i].num]=d[i].g;
			sum1+=d[i].g*d[i].a;
			sum2+=d[i].g*d[i].b;
		}
		else{
			double gg=(B-sum2)/d[i].b;
			ans[d[i].num]=gg;
			sum1+=gg*d[i].a;
			sum2+=gg*d[i].b;
		}
	}
	if(sum1 < A) printf("-1 -1\n");
	else{
		printf("%.10lf %.10lf\n",sum1,sum2);
		for(i=1;i<=n;i++){
			printf("%.10lf",ans[i]);
			if(i==n)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
