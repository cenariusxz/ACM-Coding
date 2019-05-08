#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const double PI=acos(-1.0);
const double area1=PI/4.0;
const double area2=4.0-area1-area1;
const int maxn=250*250;

int fa[maxn];
double a[maxn];

void init(){
	memset(a,0,sizeof(a));
	for(int i=0;i<maxn;++i)fa[i]=i;
}

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

char s[150][150];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int r,c;
		init();
		scanf("%d%d",&r,&c);
		for(int i=1;i<=r;++i){
			scanf("%s",s[i]+1);
		}
		for(int i=1;i<=r;++i){
			for(int j=1;j<=c;++j){
				if(s[i][j]=='0'){
					int x=(i-1)*2+1,y=(j-1)*2+1;
					int x1=x,y1=y+2;
					int id1=(x1-1)*(2*c+1)+y1;
					int x2=x+1,y2=y+1;
					int id2=(x2-1)*(2*c+1)+y2;
					int X=find(id1),Y=find(id2);
					if(X!=Y)fa[Y]=X;
					x2=x+2,y2=y;
					id2=(x2-1)*(2*c+1)+y2;
					Y=find(id2);
					if(X!=Y)fa[Y]=X;
				}
				if(s[i][j]=='1'){
					int x=(i-1)*2+1,y=(j-1)*2+1;
					int x1=x,y1=y;
					int id1=(x1-1)*(2*c+1)+y1;
					int x2=x+1,y2=y+1;
					int id2=(x2-1)*(2*c+1)+y2;
					int X=find(id1),Y=find(id2);
					if(X!=Y)fa[Y]=X;
					x2=x+2,y2=y+2;
					id2=(x2-1)*(2*c+1)+y2;
					Y=find(id2);
					if(X!=Y)fa[Y]=X;
				}
			}
		}
		for(int i=1;i<=r;++i){
			for(int j=1;j<=c;++j){
				if(s[i][j]=='0'){
					int x=(i-1)*2+1,y=(j-1)*2+1;
					int id1=(x-1)*(2*c+1)+y;
					int X=find(id1);
					a[X]+=area1;
					x++,y++;
					id1=(x-1)*(2*c+1)+y;
					X=find(id1);
					a[X]+=area2;
					x++,y++;
					id1=(x-1)*(2*c+1)+y;
					X=find(id1);
					a[X]+=area1;	
				}
				if(s[i][j]=='1'){
					int x=(i-1)*2+3,y=(j-1)*2+1;
					int id1=(x-1)*(2*c+1)+y;
					int X=find(id1);
					a[X]+=area1;
					x--,y++;
					id1=(x-1)*(2*c+1)+y;
					X=find(id1);
					a[X]+=area2;
					x--,y++;
					id1=(x-1)*(2*c+1)+y;
					X=find(id1);
					a[X]+=area1;	
				}

			}
		}
		printf("Case %d:\n",q);
		int Q;
		scanf("%d",&Q);
		while(Q--){
			int x,y;
			scanf("%d%d",&x,&y);
			x++,y++;
			int id=(x-1)*(2*c+1)+y;
			int X=find(id);
			printf("%.4lf\n",a[X]);
		}
	}
	return 0;
}
