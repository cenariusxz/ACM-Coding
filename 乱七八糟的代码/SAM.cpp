#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=5e5+5;	//后缀自动机节点数(串长的2倍)

struct SAM{
	SAM *par,*go[26];
	int ma;				//子串可行长度区间[min,max]，此为max，min是par的ma+1
	void clear(){par=0;ma=0;memset(go,0,sizeof(go));}	//多组样例可能需要清空，否则会MLE
}*root,*last,sam[maxn],*B[maxn];
int tot,Cnt[maxn];

char s[maxn],t[maxn];

void addSAM(int w){
	SAM *p=last;
	SAM *np=&sam[tot++];
	np->ma=p->ma+1;
	while(p&&!p->go[w])p->go[w]=np,p=p->par;
	if(!p)np->par=root;
	else{
		SAM *q=p->go[w];
		if(p->ma+1==q->ma)np->par=q;
		else{
			SAM *nq=&sam[tot++];
			nq->ma=p->ma+1;
			memcpy(nq->go,q->go,sizeof(q->go));
			nq->par=q->par;
			np->par=q->par=nq;
			while(p&&p->go[w]==q)p->go[w]=nq,p=p->par;
		}
	}
	last=np;
}

int main(){

	//初始化
	tot=0;
	last=root=&sam[tot++];

	//建立后缀自动机
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;s[i];++i)addSAM(s[i]-'a');
	
	//生成索引数组B，B的每个元素是一个后缀自动机中的状态节点，且子节点编号一定在祖先节点的后面
	memset(Cnt,0,sizeof(Cnt));
	for(int i=0;i<tot;++i)Cnt[sam[i].ma]++;
	for(int i=1;i<=len;++i)Cnt[i]+=Cnt[i-1];
	for(int i=0;i<tot;++i)B[--Cnt[sam[i].ma]]=&sam[i];

	//将另一个串在后缀自动机上运行的一般过程
	scanf("%s",t);
	SAM *p=root;
	int res=0;		//res是对于后面的每个i位置能匹配的最长长度
	for(int i=0;t[i];++i){
		int w=t[i]-'a';
		if(p->go[w])res++,p=p->go[w];
		else{
			while(p&&!p->go[w])p=p->par;
			if(!p)res=0,p=root;
			else res=p->ma+1,p=p->go[w];
		}
		/* xxx */
	}

	//需要儿子节点更新父节点的情况，注意，由于父亲节点的right一定包括了儿子接点的right，所以儿子能够匹配到的长度，父亲在同一right位置同样也可以匹配到，所以需要仔细考虑是否要更新
	for(int i=tot-1;i>=0;--i){
		p=B[i];
		if(p->par/*&& xxx */)/* xxx */;

	}

	return 0;
}
