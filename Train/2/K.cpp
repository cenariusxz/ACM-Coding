#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=30;
const int maxm=700;

int head[30],point[maxm],nxt[maxm];
int size,f;
int vis[maxn],v[maxn];
int path[maxn],cnt,path2[maxn],cnt2;
int id[maxn];
int M[maxn][maxn];

void init(){
	cnt2=0;
//	memset(v,0,sizeof(v));
	memset(id,0,sizeof(id));
	memset(vis,0,sizeof(vis));
	memset(head,-1,sizeof(head));
	size=0;
	memset(M,0,sizeof(M));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	id[b]++;
}

void dfs1(int s){
//	v[s]=1;
	vis[s]=1;
	path[++cnt]=s;
	for(int i=head[s];~i;i=nxt[i]){
		if(f)return;
		int j=point[i];
		if(!vis[j]){
			dfs1(j);
		}
		else{
			f=j;
			return;
		}
	}
	if(f)return;
	vis[s]=0;
	--cnt;
}

void print(int l){
/*	for(int i=0;i<cnt2;++i)printf("%d ",path2[i]);
	printf("\n");
*/	for(int i=0;i<l;++i){
		int f=i%cnt2;
		for(int j=0;j<l;++j){
			printf("%c",'a'+path2[(i+j)%cnt2]-1);
		}
		printf("\n");
	}
}

void dfs2(int s,int t){
	path[t]=s;
	int num=0;
	for(int i=head[s];~i;i=nxt[i]){
		++num;
		int j=point[i];
		dfs2(j,t+1);
	}
	if(!num){
		if(t>cnt2){
			cnt2=0;
			for(int j=1;j<=t;++j){
				path2[cnt2++]=path[j];
			}
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		int m;
		scanf("%d",&m);
		while(m--){
			char s[20];
			scanf("%s",s);
			M[s[0]-'a'+1][s[1]-'a'+1]=1;
		}
		int c=0;
		for(int i=1;i<=26;++i){
			if(M[i][i]==0){//
				c=i;
				break;
			}
		}
		if(c){
			cnt2=0;
			path2[cnt2++]=c;
			print(20);
		}
		else{
			for(int i=1;i<=26;++i){
				for(int j=1;j<=26;++j){
					if(M[i][j]==0)add(i,j);//
				}
			}
			f=0;
			for(int i=1;i<=26;++i){
//				if(!v[i]){
					memset(vis,0,sizeof(vis));
					cnt=0;
					dfs1(i);
					if(f){
				//		printf("%d\n",f);
						int pos=0;
						for(int j=1;j<=cnt;++j){
							if(path[j]==f){
								pos=j;
							}
						}
						cnt2=0;
						for(int j=pos;j<=cnt;++j){
							path2[cnt2++]=path[j];
						}
						print(20);
						break;
					}
		//		}
			}
			if(!f){
				cnt2=0;
		//		printf("aaa\n");
				for(int i=1;i<=26;++i){
					if(id[i]==0){
						dfs2(i,1);
					}
				}
				print((cnt2+1)/2);
			}
		}
	}
	return 0;
}
