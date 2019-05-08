#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct di{
	char s[55];
	int v,n;
	bool operator<(di a)const{
		if(v==a.v)return n<a.n;
		return v<a.v;
	}
}d[3][105];

int main(){
	int t;
	while(scanf("%d",&t)!=EOF){
		for(int q=1;q<=t;q++){
			int l[3];
			int i;
			scanf("%d%d%d",&l[0],&l[1],&l[2]);
			for(i=1;i<=l[0];i++){
				scanf("%s%d",d[0][i].s,&d[0][i].v);
				d[0][i].n=i;
			}
			for(i=1;i<=l[1];i++){
				scanf("%s%d",d[1][i].s,&d[1][i].v);
				d[1][i].n=i;
			}
			for(i=1;i<=l[2];i++){
				scanf("%s%d",d[2][i].s,&d[2][i].v);
				d[2][i].n=i;
			}
			int ans=0;
			char a[3][55];
			for(i=0;i<=2;i++){
				sort(d[i]+1,d[i]+l[i]+1);
				if(l[i]%2){
					ans+=d[i][(l[i]+1)/2].v;
					strcpy(a[i],d[i][(l[i]+1)/2].s);
				}
				else{
					ans+=d[i][(l[i])/2+1].v;
					strcpy(a[i],d[i][(l[i])/2+1].s);
				}
			}
			printf("%d %s %s %s\n",ans,a[0],a[1],a[2]);
		}
	}
	return 0;
}
