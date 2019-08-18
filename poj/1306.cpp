#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int C[105][105][205];
int len[105][105];

int add(int a[], int lena, int b[], int lenb, int c[]){
	int lenc = max(lena, lenb);
	for(int i = 0 ; i < lenc ; ++ i){
		c[i] += a[i] + b[i];
		c[i+1] += c[i] / 10;
		c[i] %= 10;
	}
	if(c[lenc])lenc++;
	return lenc;
}

void init(){
	for(int i = 0 ; i <= 100 ; ++ i){
		for(int j = 0 ; j <= i ; ++ j){
			if(j == 0 || j == i)C[i][j][0] = 1, len[i][j] = 1;
			else len[i][j] = add(C[i-1][j-1],len[i-1][j-1],C[i-1][j],len[i-1][j],C[i][j]);
		}
	}
}

int main(){
	init();
	int n,m;
	while(scanf("%d%d",&n,&m) && n && m){
		printf("%d things taken %d at a time is ",n,m);
		for(int i = len[n][m] - 1 ; i >= 0 ; -- i)printf("%d",C[n][m][i]);
		printf(" exactly.\n");	
	}
	return 0;
}

