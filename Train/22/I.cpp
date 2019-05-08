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
const int MAXN = 100010;

int T,N;
int A[MAXN],B[MAXN];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i = 1; i <= N; ++i) scanf("%d",&A[i]);
		for(int i = 1; i <= N; ++i) scanf("%d",&B[i]);
		bool f = true;
		sort(A + 1,A + N + 1);
		sort(B + 1,B + N + 1);
		for(int i = N; i >= 1; --i){
			if(A[i] == B[i]) continue;
			if(A[i] > B[i]){
				f = false;
				break;
			}
			else break;
		}
		if(f) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
