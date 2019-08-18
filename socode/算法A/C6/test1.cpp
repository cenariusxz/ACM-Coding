#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int a[maxn];

int main(){
	int n,s;
	scanf("%d%d",&n,&s);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	sort(a+1,a+1+n);	// 对a排序 
	int pos = n;
	for(int i = 1 ; i <= n ; ++ i){		// 枚举两数种较小的数a[i] 
		while(a[i] + (ll)a[pos] > s && pos > i)pos--;	// 如果两数相加>s 并且pos在i后面,则向前找pos 
		if(pos <= i)break;		// pos比i小，则a[i]不是较小数 
		if(a[i] + (ll)a[pos] == s){	// 找到 
			printf("%d %d\n",a[i],a[pos]);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
