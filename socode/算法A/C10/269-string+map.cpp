#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

map<string,int>M;
char s[105];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		int age;
		scanf("%s%d",s,&age);
		M[string(s)] = age;
	}
	scanf("%s",s);
	printf("%d\n",M[string(s)]);
	return 0;
}

