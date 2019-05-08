#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=1e5+5;
const int maxm=8e5+5;
char s[maxn<<1];

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

int nxt[maxm][2];    //字母结点
int tail[maxm];        //记录某个结点是否为单词结尾，可以用bool型仅记录是否结尾，也可以int型记录其作为结尾的单词编号或记录单词出现过多少次
int size,cnt;

void init(){        //初始化函数
	nxt[0][0]=nxt[0][1]=0;
	memset(tail,0,sizeof(tail));
	size=1;
	cnt=0;
}

void insert(char s[]){    //添加单词函数
	int p=0;
	for(int i=0;s[i];i++){
		int &x=nxt[p][s[i]-'0'];
		if(!x){
			nxt[size][0]=nxt[size][1]=0;
			x=size++;
		}
		p=x;
	}
	if(!tail[p]){
		cnt++;
		tail[p]=1;
	}
}

int MINR(char s[],int l){
	for(int i=0;i<l;++i)s[l+i]=s[i];
	s[2*l]=0;
	int i=0,j=1;
	while(i<l&&j<l){
		int k=0;
		while(s[i+k]==s[j+k]&&k<l)++k;
		if(k==l)return min(i,j);
		if(s[i+k]>s[j+k])i=max(i+k+1,j+1);
		else j=max(j+k+1,i+1);
	}
	return min(i,j);
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		init();
		for(int i=1;i<=n;++i){
			scanf("%s",s);
			int l=strlen(s);
			int pos=MINR(s,l);
			s[pos+l]=0;
			insert(s+pos);
		}
		printf("%d\n",cnt);
	}
	return 0;
}
