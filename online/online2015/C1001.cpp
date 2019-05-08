#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int INF=0x3f3f3f3f;
const double eps=1e-12;

double x[105],y[105];
double d[105][105];

inline double get(int i,int j){
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&m,&n);
		for(int i=1;i<=m;++i){
			scanf("%lf%lf",&x[i],&y[i]);
		}
		for(int i=1;i<=m;++i){
			for(int j=i+1;j<=m;++j){
				d[i][j]=d[j][i]=get(i,j);
			}
		}
		for(int i=1;i<=m;++i){
			d[i][i]=0;
		}
		int ans=INF;
		for(int i=1;i<=m;++i){
			sort(d[i]+1,d[i]+m+1);
			int di=(int)d[i][n];
			di--;
			if(d[i][n]<di&&fabs(d[i][n]-di)>eps){
				if(n==m||(n<m&&di<d[i][n+1]&&fabs(d[i][n]-di)>eps))ans=min(ans,di);
			}
			di++;
			if(d[i][n]<di&&fabs(d[i][n]-di)>eps){
				if(n==m||(n<m&&di<d[i][n+1]&&fabs(d[i][n]-di)>eps))ans=min(ans,di);
			}
			di++;
			if(d[i][n]<di&&fabs(d[i][n]-di)>eps){
				if(n==m||(n<m&&di<d[i][n+1]&&fabs(d[i][n]-di)>eps))ans=min(ans,di);
			}
		}
		if(ans==INF)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
