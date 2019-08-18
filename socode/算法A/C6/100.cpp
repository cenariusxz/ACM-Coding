#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e7 + 5;

char s[maxn];
int cnt[505];

int main(){
	int n, k;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int anslen = INF, ansl, ansr;
	int pos = 0, num = 0;
	for(int i = 1 ; s[i] ; ++ i){
		while(num < k && pos+1 <= n){
			pos++;
			cnt[s[pos]] ++;
			if(cnt[s[pos]] == 1)num ++;
		}
		if(num == k){
			if(pos - i + 1 <= anslen)anslen = pos-i+1, ansl = i, ansr = pos;	
		}
		cnt[s[i]] -- ;
		if(cnt[s[i]] == 0)num--;
	}
	if(anslen == INF)printf("-1\n");
	else{
		for(int i = ansl ; i <= ansr ; ++ i){
			printf("%c", s[i]);
		}
		printf("\n");
	}
	return 0;
}

