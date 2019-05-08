#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e3+5;

int n,m;
char s[maxn][maxn];
int r[maxn],d[maxn];
int row[maxn],col[maxn];
int num1,num2;

struct point{
	int i,j;
}p[maxn];

inline ll sum(int i,int j){
	return j*(j-1)/2*(ll)i+i*(i-1)/2*(ll)(j-1)+j*(j-1)/2*(ll)(n-i+1)+(n-i+1)*(n-i)/2*(ll)(j-1)-j*(j-1)/2;
}

inline ll get(int i,int j){
	return sum(i,j)+sum(i,m-j+1)+i*(i-1)/2+(n-i+1)*(n-i)/2;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(r,0,sizeof(r));
		memset(d,0,sizeof(d));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
		num1=0;
		num2=0;
		ll ans=0;
		memset(row,-1,sizeof(row));
		memset(col,-1,sizeof(col));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(s[i][j]=='G'){
					num1++;
					row[i]=j;
					col[j]=i;
					p[num1].i=i;
					p[num1].j=j;
					ans-=get(i,j);
				}
				else{
					num2++;
					ans+=get(i,j);
				}
			}
		}
		for(int i=1;i<=num1;++i){
			for(int j=1;j<=num1;++j){
				ans+=abs(p[i].i-p[j].i)+abs(p[i].j-p[j].j);
			}
		}
		for(int i=n;i>=1;--i){
			if(i==n){
				if(row[i]!=-1)r[i]=m-row[i];
			}
			else{
				if(row[i]!=-1){
					if(row[i]<row[i+1])r[i]=m-row[i]+r[i+1];
					else r[i]=m-row[i];
				}
			}
		}
		for(int i=m;i>=1;--i){
			if(i==m){
				if(col[i]!=-1)d[i]=n-col[i];
			}
			else{
				if(col[i]!=-1){
					if(col[i]<col[i+1])d[i]=n-col[i]+d[i+1];
					else d[i]=n-col[i];
				}
			}
		}
		for(int i=1;i<=n;++i){
			if(row[i]!=-1){
				ans+=4*(row[i]-1)*r[i];
		//		printf("%d %d\n",row[i]-1,r[i]);
			}
		}
		for(int i=1;i<=m;++i){
			if(col[i]!=-1){
				ans+=4*(col[i]-1)*d[i];
		//		printf("%d %d\n",col[i]-1,d[i]);
			}
		}

		memset(r,0,sizeof(r));
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;++i){
			if(i==1){
				if(row[i]!=-1)r[i]=m-row[i];
			}
			else{
				if(row[i]!=-1){
					if(row[i]<row[i-1])r[i]=m-row[i]+r[i-1];
					else r[i]=m-row[i];
				}
			}
		}
		for(int i=1;i<=m;++i){
			if(i==1){
				if(col[i]!=-1)d[i]=n-col[i];
			}
			else{
				if(col[i]!=-1){
					if(col[i]<col[i-1])d[i]=n-col[i]+d[i-1];
					else d[i]=n-col[i];
				}
			}
		}
		for(int i=1;i<=n;++i){
			if(row[i]!=-1){
				ans+=4*(row[i]-1)*r[i];
		//		printf("%d %d\n",row[i]-1,r[i]);
			}
		}
		for(int i=1;i<=m;++i){
			if(col[i]!=-1){
				ans+=4*(col[i]-1)*d[i];
		//		printf("%d %d\n",col[i]-1,d[i]);
			}
		}

		for(int i=1;i<=n;++i){
			if(row[i]!=-1){
				ans-=4*(row[i]-1)*(m-row[i]);
		//		printf("%d %d\n",row[i]-1,r[i]);
			}
		}
		for(int i=1;i<=m;++i){
			if(col[i]!=-1){
				ans-=4*(col[i]-1)*(n-col[i]);
		//		printf("%d %d\n",col[i]-1,d[i]);
			}
		}

		printf("%.4lf\n",ans*1.0/(num2*1.0*num2));
	}
	return 0;
}
