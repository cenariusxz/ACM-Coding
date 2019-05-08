#include<stdio.h>
#include<string.h>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxm=500006;
const double eps=1e-9;

double A[150][150];
int word[15];
int nxt[maxm][6],tail[maxm],f[maxm],size;
int last[maxm];
int L;
int top;

int newnode(){
	memset(nxt[size],0,sizeof(nxt[size]));
	f[size]=tail[size]=0;
	return size++;
}

void insert(int s[],int num){
	int i,p=0;
	for(i=0;i<L;++i){
		int &x=nxt[p][s[i]-1];
		p=x?x:x=newnode();
	}
	tail[p]=num;
}

void makenxt(){
	int i;
	queue<int>q;
	f[0]=0;
	for(i=0;i<6;i++){
		int v=nxt[0][i];
		if(v){
			f[v]=last[v]=0;
			q.push(v);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(i=0;i<6;i++){
			int v=nxt[u][i];
			if(!v)nxt[u][i]=nxt[f[u]][i];
			else{
				q.push(v);
				f[v]=nxt[f[u]][i];
				last[v]=tail[f[v]]?f[v]:last[f[v]];
			}
		}
	}
}

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
	while(T--){
		memset(tail,0,sizeof(tail));
		int n;
		scanf("%d%d",&n,&L);
		size=0,newnode();
		for(int i=0;i<n;i++){
			for(int j=0;j<L;++j)scanf("%d",&word[j]);
			insert(word,i+1);
		}
		makenxt();
		
		for(int k=1;k<=n;++k){
			int cnt=0;
			memset(A,0,sizeof(A));
			for(int i=0;i<size;++i){
				if(tail[i])continue;
				A[cnt][i]+=-1;
				for(int j=0;j<6;++j){
					int id=nxt[i][j];
					if(tail[id]==k){
						A[cnt][size]+=-1.0/6;
					}
					else if(tail[id]==0){
						A[cnt][id]+=1.0/6;
					}
				}
				++cnt;
			}
	//		if(k==2){
	//			for(int i=0;i<size;++i){
	//				for(int j=0;j<size;++j)printf("%.6lf ",a[i][j]);
	//				printf("%.6lf\n\n",x[i]);
	//			}
	//		}
			top=size;
			Gauss();
	//		for(int i=0;i<=size;++i)printf("%.6lf ",g[1][i]);
			printf("%.6lf",A[0][top]);
			if(k==n)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
