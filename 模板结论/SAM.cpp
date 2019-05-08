#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

struct SAM{
	SAM *par,*go[26];
	int ma;				//子串可行长度区间[min,max]，此为max，min是par的ma+1
	SAM(int _ma):par(0),ma(_ma){memset(go,0,sizeof(go));}
}*root,*last;

void addSAM(int w){
	SAM *p=last;
	SAM *np=new SAM(p->ma+1);
	while(p&&p->go[w]==0)p->go[w]=np,p=p->par;
	if(p==0)np->par=root;
	else{
		SAM *q=p->go[w];
		if(p->ma+1==q->ma)np->par=q;
		else{
			SAM *nq=new SAM(p->ma+1);
			memcpy(nq->go,q->go,sizeof(q->go));
			nq->par=q->par;
			q->par=nq;
			np->par=nq;
			while(p&&p->go[w]==q)p->go[w]=nq,p=p->par;
		}
	}
	last=np;
}

int main(){

}
