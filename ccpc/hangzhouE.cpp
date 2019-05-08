#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxm=50;
const int maxn=50;
const double INF=1e100;
const double eps=1e-8;

int n,m;

struct Simplex {
	int n; // 变量个数
	int m; // 约束个数
	double a[maxm][maxn]; // 输入矩阵
	int B[maxm], N[maxn]; // 算法辅助变量

	void pivot(int r, int c) {
		swap(N[c], B[r]);
		a[r][c] = 1 / a[r][c];
		for(int j = 0; j <= n; j++) if(j != c) a[r][j] *= a[r][c];
		for(int i = 0; i <= m; i++) if(i != r) {
			for(int j = 0; j <= n; j++) if(j != c) a[i][j] -= a[i][c] * a[r][j];
			a[i][c] = -a[i][c] * a[r][c];
		}
	}

	bool feasible() {
		for(;;) {
			int r, c;
			double p = INF;
			for(int i = 0; i < m; i++) if(a[i][n] < p) p = a[r = i][n];
			if(p > -eps) return true;
			p = 0;
			for(int i = 0; i < n; i++) if(a[r][i] < p) p = a[r][c = i];
			if(p > -eps) return false;
			p = a[r][n] / a[r][c];
			for(int i = r+1; i < m; i++) if(a[i][c] > eps) {
				double v = a[i][n] / a[i][c];
				if(v < p) { r = i; p = v; }
			}
			pivot(r, c);
		}
	}

	// 解有界返回1，无解返回0，无界返回-1。b[i]为x[i]的值，ret为目标函数的值
	int simplex(int n, int m, double x[maxn], double& ret) {
		this->n = n;
		this->m = m;
		for(int i = 0; i < n; i++) N[i] = i;
		for(int i = 0; i < m; i++) B[i] = n+i;
		if(!feasible()) return 0;
		for(;;) {
			int r, c;
			double p = 0;
			for(int i = 0; i < n; i++) if(a[m][i] > p) p = a[m][c = i];
			if(p < eps) {
				for(int i = 0; i < n; i++) if(N[i] < n) x[N[i]] = 0;
				for(int i = 0; i < m; i++) if(B[i] < n) x[B[i]] = a[i][n];
				ret = -a[m][n];
				return 1;
			}
			p = INF;
			for(int i = 0; i < m; i++) if(a[i][c] > eps) {
				double v = a[i][n] / a[i][c];
				if(v < p) { r = i; p = v; }
			}
			if(p == INF) return -1;
			pivot(r, c);
		}
	}
}solver;
double ans,x[maxn];
int lim[10]={0,16,15,14,13,12,11,10,9,8};
int num[10];
int equ[36][3]={
	{1,1,2},
	{1,2,3},
	{1,3,4},
	{1,4,5},
	{1,5,6},
	{1,6,7},
	{1,7,8},
	{1,8,9},
	{2,1,3},
	{2,2,4},
	{2,3,5},
	{2,4,6},
	{2,5,7},
	{2,6,8},
	{2,7,9},
	{3,1,4},
	{3,2,5},
	{3,3,6},
	{3,4,7},
	{3,5,8},
	{3,6,9},
	{4,1,5},
	{4,2,6},
	{4,3,7},
	{4,4,8},
	{4,5,9},
	{5,1,6},
	{5,2,7},
	{5,3,8},
	{5,4,9},
	{6,1,7},
	{6,2,8},
	{6,3,9},
	{7,1,8},
	{7,2,9},
	{8,1,9}
};

void init(){
	n=36,m=45;
	memset(solver.a,0,sizeof(solver.a));
	for(int i=0;i<36;++i){
		for(int j=0;j<=8;++j)num[j]=0;
		num[equ[i][0]-1]++;
		num[equ[i][1]-1]++;
		num[equ[i][2]-1]++;
		for(int j=0;j<=8;++j)solver.a[j][i]=num[j];
	}
	for(int i=0;i<36;++i)solver.a[9+i][i]=1,solver.a[9+i][n]=1;
	for(int i=0;i<36;++i)solver.a[m][i]=1;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		init();
		for(int i=1;i<=9;++i){
			scanf("%d",&num[i]);
			if(num[i]>lim[i])num[i]=lim[i];
			solver.a[i-1][n]=num[i];
		}
		solver.simplex(n,m,x,ans);
		printf("%.6lf\n",ans);
		printf("Case #%d: %d\n",q,(int)round(ans));
	}
	return 0;
}
