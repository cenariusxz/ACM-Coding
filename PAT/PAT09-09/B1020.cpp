#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 1005;

struct node{
	double num,sum;
	bool operator < ( const node a)const{
		return sum * a.num > num * a.sum;
	}
}a[maxn];

int main(){
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i = 1 ; i <= n ; ++i)scanf("%lf",&a[i].num);
	for(int i = 1 ; i <= n ; ++i)scanf("%lf",&a[i].sum);
	sort(a + 1, a + 1 + n);
	double ans = 0;
	for(int i = 1 ; i <= n ; ++i){
		if(d > a[i].num){
			ans += a[i].sum;
			d -= a[i].num;
		}
		else{
			ans += a[i].sum * d / a[i].num;
			break;
		}
	}
	printf("%.2lf\n",ans);
	return 0;
}
