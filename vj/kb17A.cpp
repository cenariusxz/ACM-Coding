#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxm=500006;

char s[1000010],word[55];
int nxt[maxm][26],cnt[maxm],fail[maxm],size;

int newnode(){
	memset(nxt[size],0,sizeof(nxt[size]));
	fail[size]=cnt[size]=0;
	return size++;
}

void insert(char s[]){
	int i,p=0;
	for(i=0;s[i];i++){
		int &x=nxt[p][s[i]-'a'];
		p=x?x:x=newnode();
	}
	cnt[p]++;
}

void makenxt(){
	int i;
	queue<int>q;
	q.push(0);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(i=0;i<26;i++){
			int v=nxt[u][i];
			if(v==0)nxt[u][i]=nxt[fail[u]][i];
			else q.push(v);    
			if(u&&v){
				fail[v]=nxt[fail[u]][i];
			}
		}
	}
}

int query(char s[]){
	int ans=0,d=0;
	for(int i=0;s[i];i++){
		d=nxt[d][s[i]-'a'];
		int tmp=d;
		while(tmp!=0){
			ans+=cnt[tmp];
			cnt[tmp]=0;
			tmp=fail[tmp];
		}
	}
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		size=0,newnode();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%s",word);
			insert(word);
		}
		makenxt();
		scanf("%s",s);
		printf("%d\n",query(s));
	}
	return 0;
}
