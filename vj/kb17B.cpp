#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
const int maxm=520*250;

char s[10020],word[210];
bool vis[maxm];
int nxt[maxm][128-30],cnt[maxm],fail[maxm],size;
int ans[520],c;

int newnode(){
	memset(nxt[size],0,sizeof(nxt[size]));
	fail[size]=cnt[size]=0;
	return size++;
}

void insert(char s[],int k){
	int i,p=0;
	for(i=0;s[i];i++){
		int &x=nxt[p][s[i]-30];
		p=x?x:x=newnode();
	}
	cnt[p]=k;
}

void makenxt(){
	int i;
	queue<int>q;
	q.push(0);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(i=0;i<128-30;i++){
			int v=nxt[u][i];
			if(v==0)nxt[u][i]=nxt[fail[u]][i];
			else q.push(v);    
			if(u&&v){
				fail[v]=nxt[fail[u]][i];
			}
		}
	}
}

bool query(char s[]){
	int d=0;
	bool f=0;
	for(int i=0;s[i];i++){
		d=nxt[d][s[i]-30];
		int tmp=d;
		while(tmp!=0){
			if(cnt[tmp]&&!vis[tmp]){
				f=1;
				vis[tmp]=1;
				ans[++c]=cnt[tmp];
			}
			tmp=fail[tmp];
		}
	}
	return f;
}

int main(){
	int n,m,i;
	while(scanf("%d",&n)!=EOF){
		memset(cnt,0,sizeof(cnt));
		size=0,newnode();
		for(i=1;i<=n;i++){
			scanf("%s",word);
			insert(word,i);
		}
		makenxt();
		scanf("%d",&m);
		int res=0;
		for(i=1;i<=m;i++){
			memset(vis,0,sizeof(vis));
			c=0;
			scanf("%s",s);
			if(query(s)){
				res++;
				sort(ans+1,ans+c+1);
				printf("web %d:",i);
				for(int j=1;j<=c;j++){
					printf(" %d",ans[j]);
				}
				printf("\n");
			}
		}
		printf("total: %d\n",res);
	}
	return 0;
}
