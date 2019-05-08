#include<stdio.h>
#include<string.h>
struct node{
	int next[26];
	int cnt;
	node(){
		memset(next,-1,sizeof(next));
		cnt=0;
	}
}trie[500000];
int cnt=0,sum;

 void dfs(int x){
 	int i;
 	sum+=trie[x].cnt;
 	for(i=0;i<26;i++)
 		if(trie[x].next[i]!=-1)
 			dfs(trie[x].next[i]);
 }

 int trie_query(char s[])
 {
 	int i,c,now=0,l=strlen(s);
 	for(i=0;i<l;i++){
 		c=s[i]-'a';
 		now=trie[now].next[c];
 		if(now==-1) break;
 	}
 	return now;
 }

 void trie_insert(char s[])
 {
 	int i,c,now=0,l=strlen(s);
 	for(i=0;i<l;i++){
 		c=s[i]-'a';
 		//printf("%d ",now);
 		if(trie[now].next[c]==-1){
 			trie[now].next[c]=++cnt;
 			now=cnt;
 		}
 		else now=trie[now].next[c];
 	}
 	trie[now].cnt=1;
 	//printf("%d %d\n",now,trie[now].cnt);
 }

int main()
{
	int p;
	char s[100];
	while(1){
		gets(s);
		if(strlen(s)==0) break;
		//printf("%d\n",strlen(s));
		trie_insert(s);
	}
	while(gets(s)!=NULL){
		p=trie_query(s);
		sum=0;
		if(p!=-1) dfs(p);
		//printf("%d\n",p);
		printf("%d\n",sum);
	}
 return 0;
}

