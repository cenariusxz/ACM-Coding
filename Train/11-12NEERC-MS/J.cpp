#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e6+5;

struct Node{
	int dp,a,b;
}res[maxn][3];

int n,A[maxn],B[maxn];
int V[maxn][3];

void init(){
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	memset(res,0,sizeof(res));
	memset(V,0,sizeof(V));
}

int main(){
	init();
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
		int v,c;
		scanf("%d%d",&v,&c);
		V[v][c] = 1;
	}
	Node ans;
	ans.dp = ans.a = ans.b = 0;
	for(int i = 0; i <= 1000000; ++i){
		if(i){
			res[i][0]=res[i-1][0];
			res[i][1]=res[i-1][1];
			res[i][2]=res[i-1][2];
		}
		if(V[i][0]){
			res[i][0].dp++;
			res[i][0].a = res[i][0].b = i;
		}
		if(V[i][1]){
			res[i][1].dp++;
			res[i][1].b = i;
			if(res[i - 1][0].dp + 1 > res[i][1].dp){
				res[i][1].dp = res[i - 1][0].dp + 1;
				res[i][1].a = res[i - 1][0].a;
			}
			else if(res[i - 1][0].dp + 1 == res[i][1].dp && res[i - 1][0].a < res[i][1].a){
				res[i][1].a = res[i - 1][0].a;
			}
		}
		if(V[i][2]){
			res[i][2].dp++;
			if(res[i - 1][0].dp + 1 > res[i][2].dp){
				res[i][2].dp = res[i - 1][0].dp + 1;
				res[i][2].a = res[i - 1][0].a;
				res[i][2].b = res[i - 1][0].b;
			}
			else if(res[i - 1][0].dp + 1 == res[i][2].dp && res[i - 1][0].a + res[i - 1][0].b < 
					res[i][2].a + res[i][2].b){
				res[i][2].a = res[i - 1][0].a;
				res[i][2].b = res[i - 1][0].b;
			}
			if(res[i - 1][1].dp + 1 > res[i][2].dp){
				res[i][2].dp = res[i - 1][1].dp + 1;
				res[i][2].a = res[i - 1][1].a;
				res[i][2].b = res[i - 1][1].b;
			}
			else if(res[i - 1][1].dp + 1 == res[i][2].dp && res[i - 1][1].a + res[i - 1][1].b < 
					res[i][2].a + res[i][2].b){
				res[i][2].a = res[i - 1][1].a;
				res[i][2].b = res[i - 1][1].b;
			}
		}
		for(int k = 0; k < 3; ++k){
			if(res[i][k].dp > ans.dp) ans = res[i][k];
			else if(res[i][k].dp == ans.dp && res[i][k].a + res[i][k].b < 
					ans.a + ans.b) ans = res[i][k];
		}
	}
	printf("%d %d\n",ans.a,ans.b);
	return 0;
}
