#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int T,A,B;
double DP[310][310],dp[310][310],ck[310][310];
int VIS[310][310],vis[310][310],exi[310][310];
int flag;

int cnt = 0;

double SOLVE(int a,int b){
	if(cnt < 20) cnt++,printf("s %d %d\n",a,b);
	if(a == 0){
		return 0;
	}
	if(VIS[a][b]) return DP[a][b];
	int nxta = a + a;
	int nxtb = b - a;
	if(nxta > nxtb) swap(nxta,nxtb);
	if(nxta == a && nxtb == b){
		VIS[a][b] = 1;
		DP[a][b] = 2;
	}
	else{
		DP[a][b] = 0.5 * SOLVE(nxta,nxtb) + 1;
	}
	VIS[a][b] = 1;
	return DP[a][b];
}

double Solve(int a,int b){
	if(flag) return 0;
	if(a == 0) return 0;
	if(b == 0) return 1;
	if(exi[a][b]) return ck[a][b];
	if(vis[a][b]){
		flag = 2;
		return 0;
	}
	vis[a][b] = 1;
	int tmin = min(a,b);
	if(a - tmin == A && b + tmin == B){ flag = 1; return 0; }
	if(a + tmin == A && b - tmin == B){ flag = 1; return 0; }
	dp[a][b] = 0.5 * (Solve(a - tmin,b + tmin) +
			Solve(a + tmin,b - tmin));
	return dp[a][b];
}

pair<double,double> Gakki(int a,int b){
	if(a == 0) return make_pair(0,0);
	if(b == 0) return make_pair(0,1);
	int tmin = min(a,b);
	pair<double,double> res1,res2;
	if(a - tmin == A && b + tmin == B){
		res1.first = 1;
		res1.second = 0;
	}
	else res1 = Gakki(a - tmin,b + tmin);
	res1.first *= 0.5;
	res1.second *= 0.5;
	if(a + tmin == A && b - tmin == B){
		res2.first = 1;
		res2.second = 0;
	}
	else res2 = Gakki(a + tmin,b - tmin);
	res2.first *= 0.5;
	res2.second *= 0.5;
	res1.first += res2.first;
	res1.second += res2.second;
	return res1;
}

int main(){
	for(int i = 1; i <= 150; ++i){
		for(int j = 1; j <= 150; ++j){
			A = i;
			B = j;
			flag = 0;
			memset(vis,0,sizeof(vis));
			Solve(i,j);
			if(flag == 0){
				exi[i][j] = 1;
				ck[i][j] = dp[i][j];
			}
			else if(flag == 1){
				pair<double,double> res = Gakki(i,j);
				exi[i][j] = 1;
				ck[i][j] = res.second / (1.0 - res.first);
			}
		}
	}
	for(int i = 1; i <= 150; ++i){
		for(int j = 1; j <= 150; ++j){
			A = i;
			B = j;
			flag = 0;
			memset(vis,0,sizeof(vis));
			Solve(i,j);
			exi[i][j] = 1;
			ck[i][j] = dp[i][j];
		}
	}
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%d%d",&A,&B);
		printf("Case %d:",tt);
		printf(" %.6f",SOLVE(min(A,B),max(A,B)));
		printf("here\n");
		printf(" %.6f\n",ck[A][B]);
	}
	return 0;
}

