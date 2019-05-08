#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

const int maxn=2e6+5;
const int maxm=1e6+5;

int head[2][maxn],point[2][maxm],nxt[2][maxm],size[2];
bool own[maxn];

void init(){
	size[0]=size[1]=0;
	memset(head,-1,sizeof(head));
	memset(own,0,sizeof(own));
}

void add(int a,int b){
	point[0][size[0]]=b;
	nxt[0][size[0]]=head[0][a];
	head[0][a]=size[0]++;
	point[1][size[1]]=a;
	nxt[1][size[1]]=head[1][b];
	head[1][b]=size[1]++;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		scanf("%d",&n);
		init();
		map<int,int>m;
		int cnt=0;
		for(int i=1;i<=n;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			if(m[a])a=m[a];
			else m[a]=++cnt;
			if(m[b])b=m[b];
			else m[b]=++cnt;
			if(a==b)own[a]=1;
			else add(a,b);
		}
		int ans1=0,ans2=0,ans3=0;
		for(int i=1;i<=cnt;++i){
			if(head[0][i]==-1&&head[1][i]==-1)ans3++;
			if(head[0][i]!=-1&&head[1][i]==-1){
				int num=0;
				bool f=1;
				for(int j=head[0][i];~j;j=nxt[0][i]){
					num++;
					int tmp=point[0][i];
					if(head[0][tmp]!=-1){
						f=0;
						break;
					}
					int num1=0;
					for(int j1=head[1][tmp];~j1;j1=nxt[1][j1]){
						num1++;
						if(num1>1){
							f=0;
							break;
						}
					}
					if(f=0)break;
				}
				if(!own[i]&&num==1)
			}
		}
		printf("Case #%d: %d %d %d\n",q,ans1,ans2,ans3);
	}
	return 0;
}
