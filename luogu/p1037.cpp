#include <bits/stdc++.h>
using namespace std;

int M[10][10];
int sum[10];
int m;
char s[35];

struct Num{
	int d[35];
	int len;
	Num(){
		memset(d,0,sizeof(d));
		len=0;
	}
};

Num mulNum(Num a,int x){
	Num ans;
	int len = a.len;
	for(int i = 0 ; i < len ; ++ i)ans.d[i] = a.d[i]*x;
	for(int i = 0 ; i < len ; ++ i){
		ans.d[i+1] += ans.d[i] / 10;
		ans.d[i] %= 10;
	}
	if(ans.d[len])len++;
	while(ans.d[len-1] >= 10){
		ans.d[len] = ans.d[len-1] / 10;
		ans.d[len-1] %= 10;
		len++;
	}
	ans.len = len;
	return ans;
}

int main(){
	while(scanf("%s%d",s,&m)!=EOF){
		memset(M,0,sizeof(M));
		for(int i = 0 ; i <= 9 ; ++ i)M[i][i] = 1;
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			M[a][b] = 1;
		}
		for(int k = 0 ; k <= 9 ; ++ k){
			for(int i = 0 ; i <= 9 ; ++ i){
				for(int j = 0 ; j <= 9 ; ++ j){
					if(M[i][k]&&M[k][j])M[i][j] = 1;
				}
			}
		}
		for(int i = 0 ; i <= 9 ; ++ i){
			for(int j = 0 ; j <= 9 ; ++ j){
				sum[i]+=M[i][j];
			}
		}
		Num ans;
		ans.len = 1;
		ans.d[0] = 1;
		for(int i = 0 ; s[i] ; ++ i){
			int mul = sum[s[i]-'0'];
			ans = mulNum(ans,mul);
		}
		for(int i = ans.len-1 ; i >= 0 ; -- i)printf("%d",ans.d[i]);
		printf("\n");
	}
	return 0;
}
