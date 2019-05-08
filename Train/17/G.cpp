#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;
const int MOD = 1e9 + 7;
const int MAXN = 100010;

struct Hash{
	int B,mod,len,hash[MAXN],pw[MAXN];
	void init(char *s,int tlen,int tB,int tmod){
		B = tB,mod = tmod,len = tlen;
		pw[0] = 1;
		hash[0] = 0;
		for(int i = 1; i <= len; ++i){
			pw[i] = 1ll * pw[i - 1] * B % mod;
			hash[i] = (1ll * hash[i - 1] * B + s[i] - 'A' + 1) % mod;
		}
	}
	int gethash(int l,int r){
		int res = (hash[r] - 1ll * hash[l - 1] * pw[r - l + 1]) % mod;
		if(res < 0) res += mod;
		return res;
	}
}H11,H12,H21,H22;

char s1[MAXN],s2[MAXN];

int main(){
	int n1,n2;
	while(scanf("%d%d",&n1,&n2) != EOF,n1 + n2){
		scanf("%s%s",s1 + 1,s2 + 1);
		if(n1 < n2){
			printf("Hamlet\n");
			continue;
		}
		else if(n1 > n2){
			printf("Laertes\n");
			continue;
		}
		H11.init(s1,n1,173,MOD);
		H12.init(s1,n1,277,MOD);
		H21.init(s2,n2,173,MOD);
		H22.init(s2,n2,277,MOD);
		bool flag = 0;
		for(int i = 2; i <= n1; ++i){
			bool f1 = 0,f2 = 0;
			int L = n1 - i + 1;
			if(H11.gethash(1,L) == H11.gethash(i,n1) && 
				H12.gethash(1,L) == H12.gethash(i,n1)){
				f1 = 1;
			}
			if(H21.gethash(1,L) == H21.gethash(i,n1) &&
				H22.gethash(1,L) == H22.gethash(i,n1)){
				f2 = 1;
			}
			if(f1 == f2) continue;
			if(f1 == 1) printf("Laertes\n"),flag = 1;
			else printf("Hamlet\n"),flag = 1;
			if(flag) break;
		}
		if(flag == 0){
			printf("Equal\n");
		}
	}
	return 0;
}
