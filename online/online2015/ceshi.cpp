#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

const int maxn=1e6+5;
const int maxm=1e6+5;

struct que{
	bool fi,fo;    //youru/youchu
	int r1,c1;    //ru1/chu1
}num[maxn];

int head[2][maxn],point[2][maxm],nxt[2][maxm],size[2];

void init(){
	size[0]=size[1]=0;
	memset(head,-1,sizeof(head));
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
		memset(num,0,sizeof(num));
		int n;
		scanf("%d",&n);
		ini();
		int cnt=0;
		map<int,int>m;
		for(int i=1;i<=n;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			if(!m[a])a=m[a]=cnt++;
			else a=m[a];
			if(!m[b])b=m[b]=cnt++;
			else b=m[b];
			int t1=a,t2=b;
			if(t1!=t2)add(t1,t2);
			if(!num[t2].fi){
				num[t2].fi=t1;
				num[t2].r1=t1;
			}
			else if(num[t2].r1!=t1)num[t2].r1=0;
			if(!num[t1].fo){
				num[t1].fo=t2;
				num[t1].c1=t2;
			}
			else if(num[t1].c1!=t2)num[t1].c1=0;
		}
		int ans1=0,ans2=0,ans3=0;
		for(int i=1;i<=cnt;++i){
			if( num[i].fo && ( (!num[i].fi) || num[i].r1==i )){
				if(num[i].c1){
					if(num[i].c1==i)ans3++;
					else{
						int tmp=num[i].c1;
						if((!num[tmp].fo)&&num[tmp].r1)ans3++;
					}
				}
				else{
					bool f=1;
					for(int j=head[0][i];~j;j=nxt[0][j]){
						int tmp=point[0][j];
						if((!num[tmp].fo)&&num[tmp].r1){
						}
						else f=0;
					}
					if(f)ans1++;
				}
			}
			else if( num[i].fi &&( (!num[i].fo) || num[i].c1==i )){
				if(!num[i].r1){
					bool f=1;
					for(int j=head[1][i];~j;j=nxt[1][j]){
						int tmp=point[1][j];
						if((!num[tmp].fi)&&num[tmp].c1){
						}
						else f=0;
					}
					if(f)ans2++;
				}
			}
		}
		printf("Case #%d: %d %d %d\n",q,ans1,ans2,ans3);
	}
	return 0;
}
