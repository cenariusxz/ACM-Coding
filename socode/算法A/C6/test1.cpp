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
	sort(a+1,a+1+n);	// ��a���� 
	int pos = n;
	for(int i = 1 ; i <= n ; ++ i){		// ö�������ֽ�С����a[i] 
		while(a[i] + (ll)a[pos] > s && pos > i)pos--;	// ����������>s ����pos��i����,����ǰ��pos 
		if(pos <= i)break;		// pos��iС����a[i]���ǽ�С�� 
		if(a[i] + (ll)a[pos] == s){	// �ҵ� 
			printf("%d %d\n",a[i],a[pos]);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
