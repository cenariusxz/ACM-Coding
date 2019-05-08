#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxm=1010*55;

char s[2000000+50],word[1010][55];
int c;
int vis[1010];
int nxt[maxm][128-30],cnt[maxm],fail[maxm],size;

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

void query(char s[]){
	int d=0;
	for(int i=0;s[i];i++){
		d=nxt[d][s[i]-30];
		int tmp=d;
		while(tmp!=0){
			vis[cnt[tmp]]++;
			tmp=fail[tmp];
		}
	}
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		size=0,newnode();
		int i;
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++){
			scanf("%s",word[i]);
			insert(word[i],i);
		}
		makenxt();
		scanf("%s",s);
		query(s);
		for(i=1;i<=n;i++){
			if(vis[i])printf("%s: %d\n",word[i],vis[i]);
		}
	}
	return 0;
}
