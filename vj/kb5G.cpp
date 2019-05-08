#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct work{
	int p,d;
	bool operator<(work a)const{
		if(p==a.p)return d>a.d;
		return p>a.p;
	}
}w[10005];

bool t[10005];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,j;
		memset(t,0,sizeof(t));
		for(i=1;i<=n;i++){
			int a,b;
			scanf("%d%d",&w[i].p,&w[i].d);
		}
		sort(w+1,w+n+1);
		int ans=0;
		for(i=1;i<=n;i++){
			for(j=w[i].d;j>=1;j--){
				if(!t[j]){
					ans+=w[i].p;
					t[j]++;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
