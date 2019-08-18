#include <stdio.h>
#include <string.h>
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

int dp[255][500];
int len[255];
int res[500];
int reslen;

void add(int a[],int lena,int b[],int lenb){
	reslen = max(lena, lenb);
	memset(res,0,sizeof(res));
	for(int i = 0 ; i < reslen ; ++ i){
		res[i] += a[i] + b[i];
		res[i+1] = res[i] / 10;
		res[i] %= 10;
	}
	if(res[reslen])reslen++;
}

void init(){
	len[0] = 1;
	dp[0][0] = 1;
	len[1] = 1;
	dp[1][0] = 1;
	for(int i = 2 ; i <= 250 ; ++ i){
		add(dp[i-2],len[i-2],dp[i-2],len[i-2]);
		memcpy(dp[i],res,reslen*sizeof(int));
		len[i] = reslen;
		add(dp[i],len[i],dp[i-1],len[i-1]);
		memcpy(dp[i],res,reslen*sizeof(int));
		len[i] = reslen;
	}
}

int main(){
	init();
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i = len[n]-1 ; i >= 0 ; -- i)printf("%d",dp[n][i]);
		printf("\n");	
	}
	return 0;
}

