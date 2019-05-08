#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct soldier{
	int b,j;
	bool operator<(const soldier a)const{
		return j>a.j;
	}
}s[10001];

int main(){
	int n,cnt=0;
	while(scanf("%d",&n)!=EOF&&n){
		int i;
		for(i=1;i<=n;i++)scanf("%d%d",&s[i].b,&s[i].j);
		sort(s+1,s+n+1);
		int pos=0,ans=0;
		for(i=1;i<=n;i++){
			ans=max(ans,pos+s[i].b+s[i].j);
			pos+=s[i].b;
		}
		printf("Case %d: %d\n",++cnt,ans);
	}
	return 0;
}
