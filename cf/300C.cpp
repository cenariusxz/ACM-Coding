#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct tour{
	int d,h;
}t[100005];

bool f=1;

int aabs(int a){
	return a>=0?a:-a;
}

int run(int n){
	int m=n+1;
	int dd=aabs(t[m].d-t[n].d),dh=aabs(t[m].h-t[n].h);
	if(dd<dh){
		f=0;
		return -1;
	}
	int ans=(dd-1-dh+1)/2+max(t[n].h,t[m].h);
	return ans;
}

int main(){
	int n,m,i,j,ma=0;
	scanf("%d%d",&n,&m);
	memset(t,0,sizeof(t));
	for(i=1;i<=m;i++)scanf("%d%d",&t[i].d,&t[i].h);
	ma=max(t[1].h+t[1].d-1,n-t[m].d+t[m].h);
	for(i=1;i<=m-1&&f;i++){
		ma=max(run(i),ma);
	}
	if(f)printf("%d\n",ma);
	else printf("IMPOSSIBLE\n");
	return 0;
}
