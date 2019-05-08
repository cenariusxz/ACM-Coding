/******************************************************
  二分图最佳匹配 （kuhn munkras 算法 O(m*m*n)).
  邻接矩阵形式 。  返回最佳匹配值，传入二分图大小m,n
  邻接矩阵 g ，表示权，match1,match2返回一个最佳匹配,为匹配顶点的match值为-1，
  一定注意m<=n，否则循环无法终止，最小权匹配可将全职取相反数。
  初始化：  for(i=0;i<maxn;i++)
  for(j=0;j<maxn;j++) g[i][j]=-INF;
  对于存在的边：g[i][j]=val;//注意不能负值 
 ********************************************************/
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
const int maxn=305;
const int INF=0x3f3f3f3f;
int g[maxn][maxn];
int match1[maxn],match2[maxn];
int KM(int m,int n){
	int s[maxn],t[maxn],l1[maxn],l2[maxn];
	int p,q,i,j,k,ret=0;
	for(i=0;i<m;i++){
		l1[i]=-INF;
		for(j=0;j<n;j++)l1[i]=g[i][j]>l1[i]?g[i][j]:l1[i];
		if(l1[i]==-INF)return -1;
	}
	for(i=0;i<n;i++)l2[i]=0;
	memset(match1,-1,sizeof(match1));
	memset(match2,-1,sizeof(match2));
	for(i=0;i<m;i++){
		memset(t,-1,sizeof(t));
		p=0;q=0;
		for(s[0]=i;p<=q&&match1[i]<0;p++){
			for(k=s[p],j=0;j<n&&match1[i]<0;j++){
				if(l1[k]+l2[j]==g[k][j]&&t[j]<0){
					s[++q]=match2[j];
					t[j]=k;
					if(s[q]<0){
						for(p=j;p>=0;j=p){
							match2[j]=k=t[j];
							p=match1[k];
							match1[k]=j;
						}
					}
				}
			}
		}
		if(match1[i]<0){
			i--;
			p=INF;
			for(k=0;k<=q;k++){
				for(j=0;j<n;j++){
					if(t[j]<0&&l1[s[k]]+l2[j]-g[s[k]][j]<p)p=l1[s[k]]+l2[j]-g[s[k]][j];
				}
			}
			for(j=0;j<n;j++)l2[j]+=t[j]<0?0:p;
			for(k=0;k<=q;k++)l1[s[k]]-=p;  
		}
	}
	for(i=0;i<m;i++)ret+=g[i][match1[i]];
	return ret;
}


int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				scanf("%d",&g[i][j]);
			}
		}
		printf("%d\n",KM(n,n));
	}
	return 0;
}
