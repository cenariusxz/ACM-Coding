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
const int MAXN = 1000010;

int T,n,m,p;
int A[MAXN],B[MAXN],S[MAXN];
int P[MAXN],len;

void Get_P(){
	memset(P,0,sizeof(P));
	int j = 0;
	for(int i = 2; i <= m; ++i){
		while(j > 0 && B[j + 1] != B[i]) j = P[j];
		if(B[j + 1] == B[i]) j++;
		P[i] = j;
	}
}

int KMP(){
	int j = 0,res = 0;
	for(int i = 1; i <= len; ++i){
		while(j > 0 && B[j + 1] != S[i]) j = P[j];
		if(B[j + 1] == S[i]) j++;
		if(j == m){
			res++;
			j = P[j];
		}
	}
	return res;
}

int main(){
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%d%d%d",&n,&m,&p);
		for(int i = 1; i <= n; ++i) scanf("%d",&A[i]);
		for(int i = 1; i <= m; ++i) scanf("%d",&B[i]);
		Get_P();
		int ans = 0;
		for(int i = 1; i <= p; ++i){
			int c = 0;
			for(int j = i; j <= n; j += p){
				S[++c] = A[j];
			}
			len = c;
			ans += KMP();
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}

