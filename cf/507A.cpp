#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct ins{
	int a,num;
	bool operator<(const ins b)const{
		return a<b.a;
	}
}a[105];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int i,j;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i].a);
		a[i].num=i;
	}
	sort(a+1,a+n+1);
	int v[105];
	int ans=0;
	for(i=1;i<=n;i++){
		if(a[i].a<=k){
			v[++ans]=a[i].num;
			k-=a[i].a;
		}
		else break;
	}
	printf("%d\n",ans);
	for(i=1;i<=ans;i++){
		printf("%d ",v[i]);
	}
	printf("\n");
	return 0;
}
