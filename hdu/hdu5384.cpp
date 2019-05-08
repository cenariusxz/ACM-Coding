#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxm=600006;

char s[100005][10005],word[10005];
int nxt[maxm][26],tail[maxm],f[maxm],size;
int last[maxm];

int newnode(){
    memset(nxt[size],0,sizeof(nxt[size]));
    f[size]=tail[size]=0;
    return size++;
}

void insert(char s[]){
    int i,p=0;
    for(i=0;s[i];i++){
        int &x=nxt[p][s[i]-'a'];
        p=x?x:x=newnode();
    }
    tail[p]++;
}

void makenxt(){
    int i;
    queue<int>q;
    f[0]=0;
    for(i=0;i<26;i++){
        int v=nxt[0][i];
        if(v){
            f[v]=last[v]=0;
            q.push(v);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(i=0;i<26;i++){
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

int query(char s[]){
    int ans=0,v=0;
    for(int i=0;s[i];i++){
        while(v&&!nxt[v][s[i]-'a'])v=f[v];
        v=nxt[v][s[i]-'a'];
        int tmp=v;
        while(tmp){
            ans+=tail[tmp];
            tmp=last[tmp];
        }
    }
    return ans;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        size=0,newnode();
		for(int i=0;i<n;++i){
			scanf("%s",s[i]);
		}
        for(int i=0;i<m;++i){
            scanf("%s",word);
            insert(word);
        }
        makenxt();
		for(int i=0;i<n;++i){
			printf("%d\n",query(s[i]));
		}
    }
    return 0;
}
