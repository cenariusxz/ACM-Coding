#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

char t[105];
char s[105][105];

int main(){
	int n = 0;
	while(scanf("%s",t) != EOF){
		strcpy(s[++n],t);	
	}
	for(int i = 1 ; i <= n ; ++ i){
		int id = i;
		for(int j = i + 1 ; j <= n ; ++ j){
			if(strcmp(s[id],s[j]) > 0)id = j;	
		}
		strcpy(t, s[id]);
		strcpy(s[id], s[i]);
		strcpy(s[i], t);
	}
	printf("%s\n", s[1]);
	for(int i = 2 ; i <= n ; ++ i){
		if(strcmp(s[i-1],s[i]) == 0)continue;
		printf("%s\n", s[i]);	
	}
	return 0;
}

