//该程序不能判别相同模式串，因此若模式串重复，答案会将相同模式串当做不同的处理，因此若需要可以用map去重或修改insert
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxm=500006;    //maxm是总结点数：约为字母数+++

char s[1000005],word[55];
int nxt[maxm][26],tail[maxm],f[maxm],size;    //nxt是结点指向不同字母的结点下标，tail是表示该结点为几个单词的词尾(可能需要计算重复的模式串情况),f是当不匹配时转跳到的结点下标,size是结点数

int newnode(){    //初始化整个trie或建立新的结点时，首先初始化当前结点所指向的26个字母的结点为0，表示暂时还没有指向的字母，然后暂定该结点不是单词尾结点，暂无失配时转跳位置（即转跳到根节点），返回结点标号
	memset(nxt[size],0,sizeof(nxt[size]));
	f[size]=tail[size]=0;
	return size++;
}

void insert(char s[]){    //构造trie,p为当前结点的上一个结点标号，初始为0；x即为当前结点（上个结点标号指向当前字母的结点）标号,若此结点还未出现过，那么就建立这个结点；然后更新p为当前结点标号以便后续操作
	int i,p=0;
	for(i=0;s[i];i++){
		int &x=nxt[p][s[i]-'a'];
		p=x?x:x=newnode();
	}
	tail[p]++;    //此时仅将s串记录，即将s串结尾的结点加1，若无相同模式串，则此操作只会使所有串尾结点的tail值由0变为1，但有相同模式串，则会重复记录，需要去重可以用map或用tail[p]=1;语句来完成
}

void makenxt(){    //利用bfs来构造失配指针
	int i;
	queue<int>q;
	f[0]=0;    //先将0结点挂的字母加入队列，失配指针指向0结点
	for(i=0;i<26;i++){
		int v=nxt[0][i];
		if(v){
			f[v]=0;
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
				f[v]=nxt[f[u]][i];    //失配指针指向上个结点失配指针指向结点所挂当前字母的结点
			}
		}
	}
}

int query(char s[]){    //查询s串中模式串出现了多少种/次
	int ans=0,v=0;
	for(int i=0;s[i];i++){
		while(v&&!nxt[v][s[i]-'a'])v=f[v];    //先匹配直到没有失配
		v=nxt[v][s[i]-'a'];
		int tmp=v;
		while(tmp){
			ans+=tail[tmp];
			tail[tmp]=0;    //这里加这句是为了仅计算出现多少种模式链，而若不加这句则可以计算累计出现多少次
			tmp=f[tmp];
		}
	}
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		size=0,newnode();
		for(int i=0;i<n;i++){
			scanf("%s",word);
			insert(word);
		}
		makenxt();
		scanf("%s",s);
		printf("%d\n",query(s));
	}
	return 0;
}
