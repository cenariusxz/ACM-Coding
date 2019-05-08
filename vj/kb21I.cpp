#include<stdio.h>
int main(){
	int T,n,s,q;
	scanf("%d",&T);
	for(q=1;q<=T;++q){
		scanf("%d%d",&n,&s);
		printf("Case %d: %.10lf\n",q,(3*n-s)*1.0*(2*s-4*n+1)/n);
	}
	return 0;
}
