#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int a[3005];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	if(a[1]==1||a[m]==n)printf("NO\n");
	else{
		bool f=1;
		for(int i=3;i<=m;++i){
			if(a[i-2]+1==a[i-1]&&a[i-1]+1==a[i])f=0;
		}
		if(f)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
