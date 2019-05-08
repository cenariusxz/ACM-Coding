#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

char s[1000];
int num[205][205],id[40000];
int head[40000],point[40000],nxt[40000],size;
int n,m;

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	id[b]++;
}

void getnum(int a,int b){
	for(int i=0;s[i];++i){
		num[a][b]=num[a][b]*10+s[i]-'0';
	}
}

void getedge(int a,int b){
	int aa=0,bb=0;
	for(int i=1;s[i];++i){
		if(s[i]>='A'&&s[i]<='Z'){
			aa=aa*26+s[i]-'A'+1;
		}
		else if(s[i]>='0'&&s[i]<='9'){
			bb=bb*10+s[i]-'0';
		}
		else if(s[i]=='+'){
			add((bb-1)*m+aa,(a-1)*m+b);
			aa=0;
			bb=0;
		}
	}
	add((bb-1)*m+aa,(a-1)*m+b);
}

void topo(){
	queue<int>q;
	for(int i=1;i<=n*m;++i)if(!id[i])q.push(i);
	int cnt=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		int a=u/m,b=u%m;
		if(b)a++;
		else b=m;
		cnt++;
		for(int i=head[u];~i;i=nxt[i]){
			int j=point[i];
			id[j]--;
			int aa=j/m,bb=j%m;
			if(bb)aa++;
			else bb=m;
			num[aa][bb]+=num[a][b];
			if(!id[j])q.push(j);
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(num,0,sizeof(num));
		memset(id,0,sizeof(id));
		memset(head,-1,sizeof(head));
		size=0;
		scanf("%d%d",&m,&n);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				scanf("%s",s);
				if(s[0]=='=')getedge(i,j);
				else getnum(i,j);
			}
		}
		topo();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				printf("%d",num[i][j]);
				if(j==m)printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}
