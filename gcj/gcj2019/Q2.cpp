#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;

char s[maxn];

int main(){
	int T;
	scanf("%d",&T);
	for(int q = 1 ; q <= T ; ++ q){
		int n;
		scanf("%d%s",&n,s);
		printf("Case #%d: ",q);
		for(int i = 0 ; s[i] ; ++ i){
			if(s[i] == 'S')printf("E");
			else printf("S");
		}
		printf("\n");
	}
	return 0;
}
