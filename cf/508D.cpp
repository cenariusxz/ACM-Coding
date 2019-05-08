#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<map>
using namespace std;
const int maxn=2e5+5;

map<string,int>M;
map<string,int>::iterator it;

int head[maxn],point[maxn],nxt[maxn],size;
char val[maxn];
int vis[maxn];
int id[maxn],od[maxn];
char ans[maxn];
int n,cnt;
char s[10];

void init(){
	memset(head,-1,sizeof(head));
	memset(id,0,sizeof(id));
	memset(od,0,sizeof(od));
	memset(vis,0,sizeof(vis));
	size=0;
	cnt=0;
}

void add(int a,int b,char v){
	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	head[a]=size++;
}

void dfs(int s){
	while(~head[s]){
		int i=head[s];
		head[s]=nxt[i];
		dfs(point[i]);
		ans[cnt++]=val[i];
	}
}

string str[10000];

int main(){
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;++i){
		scanf("%s",s);
		string tmp1,tmp2;
		tmp1+=s[0];tmp1+=s[1];
		tmp2+=s[1];tmp2+=s[2];
		if(!M[tmp1]){
			M[tmp1]=++cnt;
			str[cnt]=tmp1;
		}
		if(!M[tmp2]){
			M[tmp2]=++cnt;
			str[cnt]=tmp2;
		}
		add(M[tmp1],M[tmp2],s[2]);
		od[M[tmp1]]++,id[M[tmp2]]++;
	}
	int stx=1;
	int c1=0,c2=0;
	for(int i=1;i<=cnt;++i){
		if(od[i]-id[i]==1)c1++,stx=i;
		else if(od[i]-id[i]==-1)c2++;
		else if(od[i]-id[i])c1=3;
	}
	if(!((c1==0&&c2==0)||(c1==1&&c2==1)))printf("NO\n");
	else{
		cnt=0;
		dfs(stx);
		if(cnt!=n)printf("NO\n");
		else{
			printf("YES\n");
			printf("%c%c",str[stx][0],str[stx][1]);
			for(int i=cnt-1;i>=0;--i){
				printf("%c",ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
