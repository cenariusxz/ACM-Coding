#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
#define PB push_back
#define MP make_pair

int Atime[6],Rtime[6],p[6];
int vis[6];
int n;

vector<pii >v[6];

struct SJFnode{
	int id,Rtime,Atime;
	SJFnode(){};
	SJFnode(int a,int b,int c):id(a),Rtime(b),Atime(c){}
	bool operator < (const SJFnode a)const{
		if(Rtime==a.Rtime)return Atime>a.Atime;
		return Rtime>a.Rtime;
	}
};

struct PRnode{
	int id,Rtime,Atime,p;
	PRnode(){};
	PRnode(int a,int b,int c,int d):id(a),Rtime(b),Atime(c),p(d){}
	bool operator < (const PRnode a)const{
		if(p==a.p)return Atime>a.Atime;
		return p>a.p;
	}
};

struct RRnode{
	int id,Rtime;
	RRnode(){};
	RRnode(int a,int b):id(a),Rtime(b){}
};

void FCFS(){
	int t=0;
	freopen("FCFS.txt","w",stdout);
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i)v[i].clear();
	for(int i=1;i<=n;++i){
		int minn=0x3f3f3f3f;
		int ans=-1;
		for(int i=1;i<=n;++i){
			if(vis[i])continue;
			if(Atime[i]<minn){
				minn=Atime[i];
				ans=i;
			}
		}
		vis[ans]=1;
		t=max(t,Atime[ans]);
		printf("%d ~ %d : %d\n",t,t+Rtime[ans]-1,ans);
		v[ans].PB(MP(t,t+Rtime[ans]));
		t+=Rtime[ans];
	}
	int t1=0,t2=0;
	for(int i=1;i<=n;++i){
		int pret=Atime[i],tmp=0;
		for(int j=0;j<v[i].size();++j){
			tmp+=v[i][j].first-pret;
			pret=v[i][j].second;
		}
		t1+=pret-Atime[i];
		t2+=tmp;
	}
	printf("平均周转时间：%lf\n平均等待时间：%lf\n",t1*1.0/n,t2*1.0/n);
}

void SJF(){
	int t=0,endt=0;
	freopen("SJF.txt","w",stdout);
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i)v[i].clear();
	priority_queue<SJFnode>q;
	while(1){
		bool f=0;
		for(int i=1;i<=n;++i){
			if(vis[i])continue;
			f=1;
			if(Atime[i]==t){
				q.push(SJFnode(i,Rtime[i],Atime[i]));
				vis[i]=1;
			}
		}
		if(!f&&q.empty())break;
		if(t==endt){
			SJFnode u=q.top();
			q.pop();
			printf("%d ~ %d : %d\n",t,t+u.Rtime-1,u.id);
			v[u.id].PB(MP(t,t+u.Rtime));
			endt=t+u.Rtime;
		}
		t++;
	}
	int t1=0,t2=0;
	for(int i=1;i<=n;++i){
		int pret=Atime[i],tmp=0;
		for(int j=0;j<v[i].size();++j){
			tmp+=v[i][j].first-pret;
			pret=v[i][j].second;
		}
		t1+=pret-Atime[i];
		t2+=tmp;
	}
	printf("平均周转时间：%lf\n平均等待时间：%lf\n",t1*1.0/n,t2*1.0/n);
}

void PR(){
	int t=0,endt=0;
	freopen("PR.txt","w",stdout);
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i)v[i].clear();
	priority_queue<PRnode>q;
	while(1){
		bool f=0;
		for(int i=1;i<=n;++i){
			if(vis[i])continue;
			f=1;
			if(Atime[i]==t){
				q.push(PRnode(i,Rtime[i],Atime[i],p[i]));
				vis[i]=1;
			}
		}
		if(!f&&q.empty())break;
		if(!q.empty()){
			PRnode u=q.top();
			q.pop();
			printf("%d ~ %d : %d\n",t,t,u.id);
			v[u.id].PB(MP(t,t+1));
			if(u.Rtime!=1){
				q.push(PRnode(u.id,u.Rtime-1,u.Atime,u.p));
			}
		}
		t++;
	}
	int t1=0,t2=0;
	for(int i=1;i<=n;++i){
		int pret=Atime[i],tmp=0;
		for(int j=0;j<v[i].size();++j){
			tmp+=v[i][j].first-pret;
			pret=v[i][j].second;
		}
		t1+=pret-Atime[i];
		t2+=tmp;
	}
	printf("平均周转时间：%lf\n平均等待时间：%lf\n",t1*1.0/n,t2*1.0/n);
}

void RR(int rt){
	int t=0,endt=0,now=-1,rest=0;
	if(rt==1)freopen("RR-1.txt","w",stdout);
	if(rt==2)freopen("RR-2.txt","w",stdout);
	if(rt==3)freopen("RR-3.txt","w",stdout);
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i)v[i].clear();
	queue<RRnode>q;
	while(1){
		bool f=0;
		for(int i=1;i<=n;++i){
			if(vis[i])continue;
			f=1;
			if(Atime[i]==t){
				q.push(RRnode(i,Rtime[i]));
				vis[i]=1;
			}
		}
		if(!f&&q.empty())break;
		if(t==endt){
			if(now!=-1&&rest!=0){
				q.push(RRnode(now,rest));
			}
			if(!q.empty()){
				RRnode u=q.front();
				q.pop();
				if(u.Rtime>rt){
					printf("%d ~ %d : %d\n",t,t+rt-1,u.id);
					v[u.id].PB(MP(t,t+rt));
					now=u.id;
					rest=u.Rtime-rt;
					endt=t+rt;
				}
				else{
					printf("%d ~ %d : %d\n",t,t+u.Rtime-1,u.id);
					now=u.id;
					rest=0;
					v[u.id].PB(MP(t,t+u.Rtime));
					endt=t+u.Rtime;
				}
			}
		}
		t++;
	}
	int t1=0,t2=0;
	for(int i=1;i<=n;++i){
		int pret=Atime[i],tmp=0;
		for(int j=0;j<v[i].size();++j){
			tmp+=v[i][j].first-pret;
			pret=v[i][j].second;
		}
		t1+=pret-Atime[i];
		t2+=tmp;
	}
	printf("平均周转时间：%lf\n平均等待时间：%lf\n",t1*1.0/n,t2*1.0/n);
}

int main(){
	freopen("JOB1.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&Atime[i],&Rtime[i],&p[i]);
	}
	FCFS();
	SJF();
	PR();
	RR(1);
	RR(2);
	RR(3);
	return 0;
}
