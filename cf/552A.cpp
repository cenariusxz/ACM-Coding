#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int i;
	int ans=0;
	for(i=1;i<=n;i++){
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		ans+=(x2-x1+1)*(y2-y1+1);
	}
	printf("%d\n",ans);
	return 0;
}
