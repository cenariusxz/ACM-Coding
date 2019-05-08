#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

const int MAX=1460000;
int h[9][2]={8,1,0,2,1,3,2,4,3,5,4,6,5,7,6,8,7,0};
int v[9][2]={3,6,4,7,5,8,0,6,1,7,2,8,0,3,1,4,2,5};
int A[10]={1,1,2,6,24,120,720,5040,40320,362880};
int num[9][9][9][9][9][9][9][9][9];

struct node{
	int s[10];		//0 kaishi
	int f,num;
}heap[MAX];
int heaplen;
int M[362885];

void heap_insert(node p)
{
	int i;
	for(i=++heaplen;heap[i>>1].f>p.f;i>>=1)
		heap[i]=heap[i>>1];
	heap[i]=p;
}

int getnum(int s[]){
	if(num[s[0]][s[1]][s[2]][s[3]][s[4]][s[5]][s[6]][s[7]][s[8]]!=-1)return num[s[0]][s[1]][s[2]][s[3]][s[4]][s[5]][s[6]][s[7]][s[8]];
	num[s[0]][s[1]][s[2]][s[3]][s[4]][s[5]][s[6]][s[7]][s[8]]=0;
	for(int i=0;i<9;++i){
		int tmp=A[s[i]];
		int cnt=0;
		for(int j=i+1;j<9;++j){
			if(s[j]<s[i])cnt++;
		}
		tmp*=cnt;
		num[s[0]][s[1]][s[2]][s[3]][s[4]][s[5]][s[6]][s[7]][s[8]]+=tmp;
	}
	return num[s[0]][s[1]][s[2]][s[3]][s[4]][s[5]][s[6]][s[7]][s[8]];
}

node heap_min()
{
	node min=heap[1],last=heap[heaplen--];
	int i,child;
	for(i=1;(i<<1)<=heaplen;i=child){
		child=(i<<1);
		if(child!=heaplen&&heap[child].f>heap[child+1].f) child++;
		if(heap[child].f>=last.f) break;
		heap[i]=heap[child];
	}
	heap[i]=last;
	return min;
}

int main(){
	memset(num,-1,sizeof(num));
	int ch,cv;
	while(scanf("%d%d",&ch,&cv)!=EOF){
		if(ch==0&&cv==0)break;
		node s;s.f=0;
		heaplen=0;
		for(int i=0;i<9;++i){
			scanf("%d",&s.s[i]);
		}
		s.num=getnum(s.s);
		heap_insert(s);
		memset(M,0x3f,sizeof(M));
		M[s.num]=0;
		int t=0;
		int tmp[10];
		for(int i=0;i<9;++i){
			scanf("%d",&tmp[i]);
		}
		t=getnum(tmp);
		int cnt=0;
		while(heaplen){
			++cnt;
			node u=heap_min();
			if(u.num==t){
				printf("%d\n",u.f);
				break;
			}
			if(u.f>M[u.num])continue;
			int pos=0;
			for(int i=0;i<9;++i)if(u.s[i]==0)pos=i;
			for(int i=0;i<=1;++i){
				node nxt;
				for(int j=0;j<9;++j)nxt.s[j]=u.s[j];
				nxt.s[pos]=nxt.s[h[pos][i]];
				nxt.s[h[pos][i]]=0;
				nxt.f=u.f+ch;
				nxt.num=getnum(nxt.s);
				if(M[nxt.num]>nxt.f){
					M[nxt.num]=nxt.f;
					heap_insert(nxt);
				}
				for(int j=0;j<9;++j)nxt.s[j]=u.s[j];
				nxt.s[pos]=nxt.s[v[pos][i]];
				nxt.s[v[pos][i]]=0;
				nxt.f=u.f+cv;
				nxt.num=getnum(nxt.s);
				if(M[nxt.num]>nxt.f){
					M[nxt.num]=nxt.f;
					heap_insert(nxt);
				}
			}
		}
	}
	return 0;
}
