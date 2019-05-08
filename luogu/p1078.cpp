#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
const int maxn = 105;
const int maxm = 2e4+5;
const int INF = 0x3f3f3f3f;

struct node{
	int s,dis;
	bitset<105>b;
	bool operator < (const node a)const{
		return dis > a.dis;
	}
	node(int _s,int _dis):s(_s),dis(_dis){
		b.reset();
	}
	pair<string,int> get(){
		return MP(b.to_string(),s);
	}
};

int head[105],point[20005],nxt[20005],val[20005],size;
int c[105];
bitset<105>M[105];
map< pair<string,int> , int > dis;
int n,k,m,s,t;

void init(){
	memset(head,-1,sizeof(head));
	size = 0;
}

void add(int a,int b,int v){
	val[size] = v;
	point[size] = b;
	nxt[size] = head[a];
	head[a] = size++;
}

void dij(){
	priority_queue<node>q;
	dis.clear();
	node stx(s,0);
	stx.b[c[s]]=1;
	q.push(stx);
	dis[stx.get()] = stx.dis;
	while(!q.empty()){
		node u = q.top();
		q.pop();
		if(u.s == t){
			printf("%d\n",u.dis);
			return;
		}
		if(u.dis > dis[u.get()])continue;
		for(int i = head[u.s] ; ~i ; i = nxt[i]){
			int j = point[i];
			if( (u.b&M[c[j]]).none() ){
				int d = u.dis + val[i];
				node tmp(j,d);
				tmp.b = u.b;
				tmp.b[c[j]] = 1;
				if(dis.find(tmp.get())==dis.end()||dis[tmp.get()]>tmp.dis){
					dis[tmp.get()] = tmp.dis;
					q.push(tmp);
				}
			}
		}
	}
	printf("-1\n");
}

int main(){
	scanf("%d%d%d%d%d",&n,&k,&m,&s,&t);
	init();
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&c[i]);
	for(int i = 1 ; i <= k ; ++ i){
		M[i].reset();
		for(int j = 1 ; j <= k ; ++ j){
			int a;
			scanf("%d",&a);
			if(a)M[i][j] = 1;
		}
		M[i][i] = 1;
	}
	while(m--){
		int a,b,v;
		scanf("%d%d%d",&a,&b,&v);
		if(!M[c[b]][c[a]])add(a,b,v);
		if(!M[c[a]][c[b]])add(b,a,v);
	}
	dij();
	return 0;
}
