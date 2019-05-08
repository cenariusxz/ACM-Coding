//关于引用说明：如果引用创建后，注意是否会修改x引用的对象，即x引用某值，再修改x的值。

#include<stdio.h>
#include<string.h>
const int maxm=5050;    //maxm是所有单词的总长度

int Nxt[maxm][26];    //字母结点
int tail[maxm];        //记录某个结点是否为单词结尾，可以用bool型仅记录是否结尾，也可以int型记录其作为结尾的单词编号或记录单词出现过多少次
int Cnt[maxm];			//每个节点及后继所代表的单词数有多少，适用于字典树需要删除节点的时候使用
int size;

void init_trie(){        //初始化函数
	memset(Nxt[0],0,sizeof(Nxt[0]));
	memset(tail,0,sizeof(tail));
	memset(Cnt,0,sizeof(Cnt));
	size=1;
}

void insertword(char s[]){    //添加单词函数
	int p=0;
	for(int i=0;s[i];++i){
		int &x=Nxt[p][s[i]-'a'];
		if(!x){
			memset(Nxt[size],0,sizeof(Nxt[size]));
			x=size++;
		}
		Cnt[x]++;				//用于记录后继单词数
		p=x;
	}
	tail[p]++;    //可以通过函数额外传一个单词编号的int型参数，此处即可将tail[p]赋为单词编号记录下来；也可以根据此处tail[p]的初始值是否为0，若为0可以用计数器加值记录共出现多少不同的单词；换成tail[p]++语句也可以用于记录某个单词出现过多少次
}

void deleteword(char s[]){
	int p=0;
	for(int i=0;s[i];++i){
		int x=Nxt[p][s[i]-'a'];
		Cnt[x]--;
		p=x;
	}
	tail[p]--;
}

bool findword(char s[]){    //查询单词函数，也可以返回int型查询该单词出现过多少次
	int p=0;
	for(int i=0;s[i];++i){
		int &x=Nxt[p][s[i]-'a'];
		if(!x)return 0;
		p=x;
	}
	return tail[p];
}

int main(){
	char word[50];
	int i;
	init_trie();
//	for(i=1;i<=10;i++){scanf("%s",word);insertword(word);}
//	printf("\n");
//	for(i=1;i<=20;i++){scanf("%s",word);printf("%d\n",findword(word));}
	while(1){
		int t;
		scanf("%d%s",&t,word);
		if(t==1)insertword(word);
		if(t==2)deleteword(word);
		if(t==3)printf("%d\n",findword(word));
	}
	return 0;
}
