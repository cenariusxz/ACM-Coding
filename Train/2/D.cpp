#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
typedef pair<int,int> pii;

const int INF=0x3f3f3f3f;

const int maxn1=1e5+5;
const int maxm1=3e5+5;
const int maxx=1e6+5;

char ss[100];
vector<int>v[maxm1];
map<string,int>p;	//stop map
map<string,int>l;	//line map
map<string,int>M[maxn1];	//stop pos in line
bool f=0;
int sn;		//stop num
int ln;		//line num
int s,t;
int dis[maxn1];

int head1[maxn1],point1[maxx],nxt1[maxx],val1[maxx],size1;

void init(){
	memset(head1,-1,sizeof(head1));
	size1=0;
}

void add1(int a,int b,int v){
	point1[size1]=b;
	val1[size1]=v;
	nxt1[size1]=head1[a];
	head1[a]=size1++;

	point1[size1]=a;
	val1[size1]=v;
	nxt1[size1]=head1[b];
	head1[b]=size1++;
}

void build1(){
	for(int i=1;i<=sn;++i){
		for(int j=0;j<v[i].size();++j){
			for(int k=j+1;k<v[i].size();++k){
				add1(v[i][j],v[i][k],1);
			}
		}
	}
	for(int i=0;i<v[s].size();++i){
		add1(0,v[s][i],0);
	}
	// zhong dian ln+1
	for(int i=0;i<v[t].size();++i){
		add1(v[t][i],ln+1,0);
	}
}

struct cmp{                        //将优先队列改为小根堆
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

void dij(){            //传入出发点和到达点
	int i;
	s=0;
	t=ln+1;
	priority_queue<pii,vector<pii>,cmp>q;
	q.push(make_pair(0,s));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>dis[u.second])continue;
		for(i=head1[u.second];~i;i=nxt1[i]){
			int j=point1[i];
			if(dis[j]>u.first+val1[i]){
				dis[j]=u.first+val1[i];
				q.push(make_pair(dis[j],j));
			}
		}
	}
	printf("%d\n",dis[t]);        //或去掉在主函数中输出或操作
}

string read(){
	string tmp;
	cin>>tmp;
	if(tmp[tmp.size()-1]==','){
		tmp.erase(tmp.end()-1);
	}
	else f=1;
	return tmp;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		p.clear();
		l.clear();
		sn=0;
		scanf("%s",ss);
		f=0;
		while(1){
			sn++;
			string tmp=read();
//			cout<<tmp<<endl;
			p[tmp]=sn;
			if(f)break;
		}
		for(int i=1;i<=sn;++i)v[i].clear();
		ln=0;
		scanf("%s",ss);
		f=0;
		while(1){
			ln++;
			l[read()]=ln;
			if(f)break;
		}
		for(int i=1;i<=ln;++i)M[i].clear();
		for(int i=1;i<=ln;++i){
			scanf("%s%s",ss,ss);
			f=0;
			int cnt=0;
			while(1){
				++cnt;
				string tmp=read();
				M[i][tmp]=cnt;
				v[p[tmp]].push_back(i);
				if(f)break;
			}
		}
		string tmp;
		scanf("%s%s%s",ss,ss,ss);
		cin>>tmp;
		s=p[tmp];
		scanf("%s%s%s",ss,ss,ss);
		cin>>tmp;
		t=p[tmp];
		init();
		build1();
		dij();
	}
	return 0;
}
