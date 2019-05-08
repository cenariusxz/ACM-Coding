#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;

vector<double>v[maxn];
int n,m;
int head[maxn],point[maxn],nxt[maxn],size,val[maxn];
map<int,double>M[maxn];

void init(){
	memset(val,0,sizeof(val));
	memset(head,-1,sizeof(head));
	size=0;
	for(int i=1;i<=n;++i){M[i].clear();v[i].clear();}
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

map<int,double>::iterator it1,it2;

void dfs(int s){
	M[s][val[s]]=1;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		dfs(j);
		double sums=0,sumj=0;
		it1=M[s].begin();it2=M[j].begin();
		while(it1!=M[s].end()&&it2!=M[j].end()){
			int num1=(*it1).first,num2=(*it2).first;
			double p1=(*it1).second,p2=(*it2).second;
			if(num1<num2){
				sums+=p1;
				M[s][num1]=p1*sumj;
				it1++;
			}
			else if(num1>num2){
				sumj+=p2;
				M[s][num2]=p2*sums;
				it2++;
			}
			else{
				M[s][num1]=p1*sumj+p2*sums+p1*p2;
				sums+=p1;
				sumj+=p2;
				it1++;
				it2++;
			}
		}
		while(it1!=M[s].end()){
			M[s][(*it1).first]=(*it1).second*sumj;
			it1++;
		}
		while(it2!=M[j].end()){
			M[s][(*it2).first]=(*it2).second*sums;
			it2++;
		}
/*		if(s==2){
			printf("%d:\n",s);
			for(it1=M[s].begin();it1!=M[s].end();++it1){
				printf("%d %.6lf\n",(*it1).first,(*it1).second);
			}

		}*/
		M[j].clear();
	}
	for(int i=0;i<v[s].size();++i){
		for(it1=M[s].end(),it1--;;--it1){
			int num=(*it1).first;
			double p=(*it1).second;
			M[s][num+1]+=p*v[s][i];
			M[s][num]=p*(1-v[s][i]);
			if(it1==M[s].begin())break;
		}
	}
/*			printf("%d:\n",s);
			for(it1=M[s].begin();it1!=M[s].end();++it1){
				printf("%d %.6lf\n",(*it1).first,(*it1).second);
			}*/
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		for(int i=1;i<n;++i){
			int a,b;
			scanf("%d%d\n",&a,&b);
			add(b,a);
			val[a]++;
		}
		int root=0;
		for(int i=1;i<=n;++i)if(val[i]==0)root=i;
		for(int i=1;i<=n;++i)scanf("%d",&val[i]);
		while(m--){
			int a;
			double p;
			scanf("%d%lf",&a,&p);
			v[a].push_back(p);
		}
		dfs(root);
		double ans=0;
		for(it1=M[root].begin();it1!=M[root].end();++it1){
			ans+=(*it1).first*(*it1).second;
		}
		printf("%.6lf\n",ans);
	}
	return 0;
}
