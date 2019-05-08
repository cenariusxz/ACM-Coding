#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxm=100;

char s[100];
int nxt[maxm][128],tail[maxm],f[maxm],size;
int last[maxm];

int newnode(){
	memset(nxt[size],0,sizeof(nxt[size]));
	f[size]=tail[size]=0;
	return size++;
}

void insert(char s[],int k){
	int i,p=0;
	for(i=0;s[i];i++){
		int &x=nxt[p][s[i]];
		p=x?x:x=newnode();
	}
	tail[p]=k;
}

void makenxt(){
	int i;
	queue<int>q;
	f[0]=0;
	for(i=0;i<128;i++){
		int v=nxt[0][i];
		if(v){
			f[v]=last[v]=0;
			q.push(v);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(i=0;i<128;i++){
			int v=nxt[u][i];
			if(!v)nxt[u][i]=nxt[f[u]][i];
			else q.push(v);
			f[v]=nxt[f[u]][i];
			last[v]=tail[f[v]]?f[v]:last[f[v]];
		}
	}
}

void query(char s[]){
	int v=0;
	for(int i=0;s[i];i++){
		while(v&&!nxt[v][s[i]])v=f[v];
		v=nxt[v][s[i]];
		int tmp=v;
		while(tmp){
			if(tail[tmp]==1)printf("MAI MAI MAI!\n");
			else if(tail[tmp]==2)printf("SONY DAFA IS GOOD!\n");
			tmp=last[tmp];
		}
	}
}

int main(){
	size=0,newnode();
	char word[5][10]={"Apple","iPhone","iPod","iPad","Sony"};
	insert(word[0],1);
	insert(word[1],1);
	insert(word[2],1);
	insert(word[3],1);
	insert(word[4],2);
	makenxt();
	while(scanf("%s",s)!=EOF){
		query(s);
	}
	return 0;
}
