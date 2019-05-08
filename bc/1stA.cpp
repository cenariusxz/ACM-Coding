#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int minn(int a,int b){
	return a<b?a:b;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,p,q;
		scanf("%d%d%d%d",&n,&m,&p,&q);
		int ans=0;
		ans=n*p;
		ans=minn(ans,n/m*q+(n-(n/m*m))*p);
		ans=minn(ans,(n/m+1)*q);
		printf("%d\n",ans);
	}
	return 0;
}
