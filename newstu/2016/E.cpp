#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int maxn=1E6+5;

int ans[maxn];

int main(){
	int p;
	scanf("%d",&p);
	memset(ans,-1,sizeof(ans));
	for(int i=0;i<p;++i){
		int num=(i*(ll)i)%p;
		if(ans[num]==-1)ans[num]=i;
	}
	for(int i=0;i<p;++i)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
