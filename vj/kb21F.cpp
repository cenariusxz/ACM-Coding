#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxm=500006;
const double eps=1e-9;

double A[150][150];		//[0~top-1][0~top-1]是方程系数，每行的top个是方程等号右边的常量
int top;			//变量个数&方程数（后面的方程可为0）
int g[105];

void Gauss(){
	int i,col;
	for(i=0,col=0;col<top;++i,++col){
		int r=i;
		for(int j=i+1;j<top;++j)
			if(fabs(A[j][col])>fabs(A[r][col]))r=j;
		if(r!=i)for(int j=col;j<=top;++j)swap(A[r][j],A[i][j]);
		if(fabs(A[i][col])<eps){
			--i;
			continue;
		}
		for(int j=top;j>=col;--j)A[i][j]/=A[i][col];
		for(int k=0;k<top;++k)if(k!=i)
			for(int j=top;j>=col;--j)
				A[k][j]-=A[k][col]*A[i][j];
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		scanf("%d",&n);
		memset(g,-1,sizeof(g));
		for(int i=1;i<=n;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			a--;b--;
			g[a]=b;
		}
		memset(A,0,sizeof(A));
		int cnt=0;
		top=100;
		for(int i=0;i<99;++i){
			if(g[i]!=-1)continue;
			A[cnt][i]=1;
			int num=0;
			for(int j=1;j<=6;++j){
				if(i+j<100)num++;
			}
			for(int j=1;j<=num;++j){
				int p=i+j;
				if(g[p]!=-1)p=g[p];
				A[cnt][p]-=1.0/num;
			}
			A[cnt][top]=6.0/num;
			++cnt;
		}
		A[cnt][99]=1;A[cnt][top]=0;
		Gauss();
		printf("Case %d: %.10lf\n",q,A[0][top]);
	}
	return 0;
}
