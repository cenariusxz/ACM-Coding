#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+5;
 
int a[maxn];
 
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	ll ans=0;
	int pos1=1,pos2=n,bit=1,lim=min(k,n-k+1);
	while(pos1<=pos2){
		if(pos1==pos2)ans+=bit*(ll)a[pos1];
		else ans+=bit*(a[pos1]+(ll)a[pos2]);
		pos1++;pos2--;bit++;
		if(bit>lim)bit=lim;
	}
	printf("%.10lf\n",ans*1.0/(n-k+1));
	return 0;
}
