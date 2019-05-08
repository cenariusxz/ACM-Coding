// 有nxt数组版本。。该程序不能判别相同模式串，因此若模式串重复，答案会将相同模式串当做不同的处理，因此若需要可以用map去重或修改insert
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxm=5000006;        //maxm是总结点数：约为字母数+++

char s[1000005],word[10005];
int nxt[maxm][26],tail[maxm],f[maxm],size;        //nxt是结点指向不同字母的结点下标，tail是表示该结点为几个单词的词尾(可能需要计算重复的模式串情况),f是当不匹配时转跳到的结点下标,size是结点数
int last[maxm];    //last指针是指向上一个是单词结尾的结点，由于是由失配指针拓展得到的，因此所指向的单词都是该结点表示的单词的后缀单词，但由于可能卡空间，所以虽然可以在时间上优化，但是有时并不使用

int newnode(){        //初始化整个trie或建立新的结点时，首先初始化当前结点所指向的26个字母的结点为0，表示暂时还没有指向的字母，然后暂定该结点不是单词尾结点，暂无失配时转跳位置（即转跳到根节点），返回结点标号
	memset(nxt[size],0,sizeof(nxt[size]));
	f[size]=tail[size]=0;
	return size++;
}

void insert(char s[]){    //构造trie,p为当前结点的上一个结点标号，初始为0；x即为当前结点（上个结点标号指向当前字母的结点）标号,若此结点还未出现过，那么就建立这个结点；然后更新p为当前结点标号以便后续操作
	int i,p=0;
	for(i=0;s[i];i++){
		int &x=nxt[p][s[i]-'A'];
		p=x?x:x=newnode();
	}
	tail[p]++;    //此时仅将s串记录，即将s串结尾的结点加1，若无相同模式串，则此操作只会使所有串尾结点的tail值由0变为1，但有相同模式串，则会重复记录，需要去重可以用map或用tail[p]=1;语句来完成
}

void makenxt(){    //利用bfs来构造失配指针
	int i;
	queue<int>q;
	f[0]=0;
	for(i=0;i<26;i++){    //首先将0结点（根节点）连接的字母结点加入队列，并定失配指针和last指针都指向0结点
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
			if(!v)nxt[u][i]=nxt[f[u]][i];    //当u结点没有i对应字母，则视为失配，将其指向失配后转跳到的结点所指向的i对应字母
			else{
				q.push(v);    //u结点存在指向i的结点，则将所指向的结点下标加入队列
				f[v]=nxt[f[u]][i];    //设置这个结点的失配指针指向上个结点失配后的指向字母i的结点，由于bfs一定会从字典树浅层到深层，即从字符串短到长，而失配转跳后表示的字符串长度严格减少，所以只需要指向一次即可
				last[v]=tail[f[v]]?f[v]:last[f[v]];    //若失配指针指向的结点是单词结尾，那么当前结点失配后就可以直接指向失配结点，即失配路径上的上一个单词结点，若失配结点不是单词结尾，就指向失配结点的last
			}
		}
	}
}

int query(char s[]){    //查询s串中模式串出现了多少种/次
	int ans=0,v=0;
	for(int i=0;s[i];i++){
		while(v&&!nxt[v][s[i]-'A'])v=f[v];
		v=nxt[v][s[i]-'A'];
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
		size=0,newnode();
		scanf("%s",word);
		insert(word);
		makenxt();
		scanf("%s",s);
		printf("%d\n",query(s));
	}
	return 0;
}
