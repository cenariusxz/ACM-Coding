#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int n,m;
struct color{
	int c,num;
	bool operator<(const color a)const{
		return c<a.c;
	}
}a[30];
int nx[30]={0,1,3,5,2,4,1,3,5,2,4,1,3,5,2,4,1,3,5,2,4,1,3,5,2,4};
int ny[30]={0,1,1,1,2,2,3,3,3,4,4,5,5,5,1,1,2,2,2,3,3,4,4,4,5,5};
int num[6][6];
int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};

int nxt(int pos){
	for(int i=pos+1;i<=25;++i){
		if(nx[i]<=n&&ny[i]<=m)return i;
	}
}

int nxt1(int pos){
	for(int i=pos-1;i>=1;--i){
		if(nx[i]<=n&&ny[i]<=m)return i;
	}
}

int main(){
	int T,c=0;
	scanf("%d",&T);
	while(T--){
		int k;
		scanf("%d%d%d",&n,&m,&k);
		bool ff=0;
		if(n>m){
			ff=1;
			swap(n,m);
		}
		int pos[2];
		pos[0]=1;pos[1]=25;
	/*	for(int i=1;i<=n*m;++i){
			printf("%d %d\n",nx[pos],ny[pos]);
			if(i==n*m)break;
			else pos=nxt(pos);
		}*/
		for(int i=1;i<=k;++i){scanf("%d",&a[i].c);a[i].num=i;}
		sort(a+1,a+k+1);
		int cnt=0,x=0;
		for(int i=k;i>=1;i--){
			while(a[i].c--){
				++cnt;
				if(!(nx[pos[x]]<=n&&ny[pos[x]]<=m)){
					if(x==0)pos[x]=nxt(pos[x]);
					else pos[x]=nxt1(pos[x]);
				}
				num[nx[pos[x]]][ny[pos[x]]]=a[i].num;
				if(cnt==n*m)break;
				else{
					if(x==0)pos[x]=nxt(pos[x]);
					else pos[x]=nxt1(pos[x]);
				}
			}
		}
		bool f=1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				for(int k=0;k<4;++k){
					int dx=i+xx[k];
					int dy=j+yy[k];
					if(dx>=1&&dx<=n&&dy>=1&&dy<=m){
						if(num[dx][dy]==num[i][j])f=0;
					}
				}
			}
		}
		printf("Case #%d:\n",++c);
		if(f){
			printf("YES\n");
			if(!ff){
				for(int i=1;i<=n;++i){
					for(int j=1;j<=m;++j){
						printf("%d",num[i][j]);
						if(j==m)printf("\n");
						else printf(" ");
					}
				}
			}
			else{
				for(int i=1;i<=m;++i){
					for(int j=1;j<=n;++j){
						printf("%d",num[j][i]);
						if(j==n)printf("\n");
						else printf(" ");
					}
				}
			}
		}
		else printf("NO\n");
	}
	return 0;
}
