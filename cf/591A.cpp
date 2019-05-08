#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;

int main(){
	int l,p,q;
	scanf("%d%d%d",&l,&p,&q);
	printf("%.10lf\n",l*1.0/(p+q)*1.0*p);
	return 0;
}
