#include<stdio.h>
#include<math.h>

int ss[105];

int main(){
	int n,t,s;
	scanf("%d%d%d",&n,&t,&s);
	for(int i=1;i<=n;++i)scanf("%d",&ss[i]);
	for(int i=1;i<=n;++i){
		if(s<=ss[i])printf("%.10lf\n",ss[i]+(t-(ss[i]-s))/2.0);
		else printf("%.10lf\n",s+(t-(s-ss[i]))/2.0);
	}
	return 0;
}
