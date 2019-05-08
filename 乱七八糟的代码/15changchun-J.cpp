#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxm=100050;    //maxm是所有单词的总长度
typedef long long ll;

int Nxt[maxm][2];    //字母结点
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
		int &x=Nxt[p][s[i]-'0'];
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
		int x=Nxt[p][s[i]-'0'];
		Cnt[x]--;
		p=x;
	}
	tail[p]--;
}

bool findword(char s[]){    //查询单词函数，也可以返回int型查询该单词出现过多少次
	int p=0;
	for(int i=0;s[i];++i){
		int &x=Nxt[p][s[i]-'0'];
		if(!x)return 0;
		p=x;
	}
	return tail[p];
}

char s[1005][40];
int num[1005];
int ans;

void check(){
	int p=0;
	ll tmp=0;
	for(int i=0;s[1003][i];++i){
		int f;
		if(s[1003][i]=='1')f=0;
		else f=1;
		int x=Nxt[p][f];
		if(!x||Cnt[x]==0){
			x=Nxt[p][f^1];
		}
		else tmp=tmp+(1<<(32-i));
		p=x;
	}
	ans=max(ans,(int)tmp);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		init_trie();
		for(int i=1;i<=n;++i){
			int tmp;
			scanf("%d",&tmp);
			num[i]=tmp;
			for(int j=32;j>=0;--j){
				if(tmp&(1ll<<j))s[i][32-j]='1';
				else s[i][32-j]='0';
			}
			insertword(s[i]);
		}
		ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				deleteword(s[i]);
				deleteword(s[j]);
				int tmp=num[i]+num[j];
				for(int k=32;k>=0;--k){
					if(tmp&(1ll<<k))s[1003][32-k]='1';
					else s[1003][32-k]='0';
				}
				check();
				insertword(s[i]);
				insertword(s[j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
