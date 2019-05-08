#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;

struct Node{
	int p,d,id;
	bool operator < (const Node a)const{
		if(p==a.p)return id>a.id;
		return p<a.p;
	}
	Node(){}
	Node(int a,int b,int c):p(a),d(b),id(c){}
};

struct Do{
	int t,id;
	bool operator < (const Do a)const{
		return t>a.t;
	}
	Do(){}
	Do(int a,int b):t(a),id(b){}
};

struct pa{
	int t;
	vector<int>p;
	vector<int>d;
}p[505];

struct Ans{
	int id,t;
	bool operator < (const Ans a)const{
		if(t==a.t)return id<a.id;
		return t<a.t;
	}
}ans[505];

int vis[505];
int num[505];

int main(){
	int n,t;
	int q=0;
	while(scanf("%d%d",&n,&t)!=EOF){
		if(n==0&&t==0)break;
		memset(vis,0,sizeof(vis));
		priority_queue<Node>q1;
		priority_queue<Do>q2;
		for(int i=1;i<=n;++i)q2.push(Do(t,-1));
		int cnt=0;
		int tt;
		while(scanf("%d",&tt)){
			if(tt==-1)break;
			p[++cnt].t=tt;
			p[cnt].p.clear();
			p[cnt].d.clear();
			int a,b;
			while(scanf("%d%d",&a,&b)){
				if(a==0&&b==0)break;
				p[cnt].p.push_back(a);
				p[cnt].d.push_back(b);
			}
			num[cnt]=p[cnt].p.size();
		}
		printf("\n");
		int pos=1;
		for(pos;pos<=cnt&&p[pos].t<=t;++pos){
			q1.push(Node(p[pos].p[0],p[pos].d[0],pos));
			vis[pos]++;
		}
		while(pos!=cnt+1||!q1.empty()){
			if(!q1.empty()){
				Do t2=q2.top();
				q2.pop();
				for(pos;pos<=cnt&&p[pos].t<=t2.t;++pos){
					q1.push(Node(p[pos].p[0],p[pos].d[0],pos));
					vis[pos]++;
				}
				int id2=t2.id;
				if(id2!=-1){
					if(vis[id2]==num[id2]){
						ans[id2].id=id2;
						ans[id2].t=t2.t;
					}
					else{
						q1.push(Node(p[id2].p[vis[id2]],p[id2].d[vis[id2]],id2));
						vis[id2]++;
					}
				}
				Node t1=q1.top();
				q1.pop();
				int id=t1.id;
				printf("aaa: %d %d %d\n",t1.p,t1.d,t1.id);
				printf("bbb: %d\n",t2.t);
				t2.t+=t1.d;
				t2.id=id;
				q2.push(t2);
			}
			else{
				int ti=p[pos].t;
				for(pos;pos<=cnt&&p[pos].t<=ti;++pos){
					q1.push(Node(p[pos].p[0],p[pos].d[0],pos));
					vis[pos]++;
					printf("ccc:%d %d %d\n",p[pos].p[0],p[pos].d[0],pos);
				}
				while(!q2.empty()){
					Do t2=q2.top();
					q2.pop();
					int id2=t2.id;
					if(id2!=-1){
						if(vis[id2]==num[id2]){
							ans[id2].id=id2;
							ans[id2].t=t2.t;
						}
						else{
							q1.push(Node(p[id2].p[vis[id2]],p[id2].d[vis[id2]],id2));
							vis[id2]++;
						}
					}
				}
				for(int i=1;i<=n;++i)q2.push(Do(ti,-1));
			}
		}
		while(!q2.empty()){
			Do t2=q2.top();
			q2.pop();
			int id2=t2.id;
			if(id2!=-1){
				if(vis[id2]==num[id2]){
					ans[id2].id=id2;
					ans[id2].t=t2.t;
				}
				else{
					q1.push(Node(p[id2].p[vis[id2]],p[id2].d[vis[id2]],id2));
					vis[id2]++;
				}
			}
		}

		sort(ans+1,ans+cnt+1);
		printf("Case %d:\n",++q);
		for(int i=1;i<=cnt;++i){
			printf("%d %d\n",ans[i].id,ans[i].t);
			printf("Patient %d released at clock = %d\n",p[ans[i].id].t,ans[i].t);
		}

	}
	return 0;
}
