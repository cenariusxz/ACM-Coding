#include<stdio.h>
#include<string.h>
struct node{
	int ch;
	int next[26];
	bool end;
	node(){
		memset(next,-1,sizeof(next));
		end=0;
	}
}trie[100000];
int cnt=0,sum;

 void trie_insert(char s[])
 {
 	int i,c,now=0,l=strlen(s);
 	for(i=0;i<l;i++){
 		//printf("%d ",now);
 		c=s[i]-'a';
 		if(trie[now].next[c]==-1){
 			trie[now].next[c]=++cnt;
 			now=cnt;
 			trie[now].ch=c;
 		}
 		else now=trie[now].next[c];
 	}
 	//printf("%d %d\n",now,trie[now].end);
 	if(trie[now].end==0) sum++;
 	trie[now].end=1;
 }

int main()
{
	int i,p;
	char s[10000],ch,ss[1000];
	while(1){
		for(i=0;i<=cnt;i++){
			memset(trie[i].next,-1,sizeof(trie[i].next));
			trie[i].end=0;
		}
		cnt=0;sum=0;s[0]=1;
		gets(s);
		if(s[0]=='#') return 0;
		i=0;
		while(i<strlen(s)){
			while(i<strlen(s)&&s[i]==' ') i++;
			if(i>=strlen(s)) break;
			for(p=i;s[p]>='a'&&p<strlen(s);p++)
				ss[p-i]=s[p];
			ss[p-i]=0;
			i=p;
			//printf("%s ",ss);
			trie_insert(ss);
			}
		printf("%d\n",sum);
	}
 return 0;
}

