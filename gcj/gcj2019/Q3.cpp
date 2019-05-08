#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 5;

int a[maxn],b[maxn],num[maxn];
map<int,char>M;
int n,l;

int main(){
	int T;
	scanf("%d",&T);
	for(int q = 1 ; q <= T ; ++ q){
		M.clear();
		scanf("%d%d",&n,&l);
		for(int i = 1 ; i <= l ; ++ i)scanf("%d",&a[i]);
		int pos = -1;
		for(int i = 2 ; i <= l ; ++ i){
			if(a[i] != a[i-1]){
				b[i-1] = __gcd(a[i],a[i-1]);
				pos = i-1;
				break;
			}
		}
		for(int i = pos-1 ; i >= 0 ; -- i){
			b[i] = a[i+1]/b[i+1];
		}
		for(int i = pos+1 ; i <= l ; ++ i){
			b[i] = a[i]/b[i-1];
		}
		for(int i = 1 ; i <= l+1 ; ++ i)num[i] = b[i-1];
		sort(num+1,num+l+1+1);
		int cnt = 1;
		for(int i = 2 ; i <= l + 1 ; ++ i){
			if(num[i] != num[i-1])num[++cnt] = num[i];
		}
		if(cnt != 26)while(1){}
		for(int i = 1 ; i <= cnt ; ++ i)M[num[i]] = 'A' + i - 1;
		printf("Case #%d: ",q);
		for(int i = 0 ; i <= l ; ++ i){
			printf("%c",M[b[i]]);
		}
		printf("\n");
	}
	return 0;
}
