#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iostream>
using namespace std;

const int maxn=1e5+5;
typedef long long ll;

struct num{
	int id,a,b,v;
	bool operator < (const num x)const{
		if(b==x.b)return a>x.a;
		return b>x.b;
	}
}p[maxn];

//1是取小的
//2是取大的

struct num1{
	int id,b,id2;
	bool operator < (const num1 x)const{
		return b>x.b;
	}
	num1(){}
	num1(int c,int d,int e):id(c),b(d),id2(e){}
};

struct num2{
	int id,a,b,id2;
	bool operator < (const num2 x)const{
		if(b==x.b)return a<x.a;
		return b<x.b;
	}
	num2(){}
	num2(int c,int d,int e,int f):id(c),b(d),id2(e),a(f){}
};

bool cmp(num a,num b){
	if(a.a==b.a)return a.b>b.b;
	return a.a>b.a;
}

int main(){
	int n;
//	while(scanf("%d",&n)!=EOF){
		scanf("%d",&n);
		int maxx=0;
		int pre=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&p[i].a);
		}
		for(int i=1;i<=n;++i){
			scanf("%d",&p[i].b);
		}
		for(int i=1;i<=n;++i){
			if(p[i].a>maxx){
				maxx=p[i].a;
				pre=i;
			}
			else if(p[i].a==maxx){
				if(p[i].b>p[pre].b){
					pre=i;
				}
			}
		}
		for(int i=1;i<=n;++i){
			p[i].v=0;
			p[i].id=i;
		}

		sort(p+1,p+n+1);
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(p[i].id!=pre){
				p[i].v=1;
				cnt++;
				if(cnt==n/2)break;
			}
		}
		for(int i=1;i<=n;++i){
			if(p[i].id==pre){
				swap(p[i],p[n]);
			}
		}
		sort(p+1,p+n,cmp);
	//		for(int i=1;i<=n;++i){
	//			printf("%d %d %d\n",p[i].a,p[i].b,p[i].v);
	//		}
		priority_queue<num1>q1;
		priority_queue<num2>q2;
		for(int i=1;i<n;++i){
			if(p[i].v==0){
		//		printf("%d\n",i);
				q2.push(num2(p[i].id,p[i].b,i,p[i].a));
			}
		}
		cnt=0;
		for(int i=1;i<n;++i){
			if(p[i].v){
				cnt++;
				q1.push(num1(p[i].id,p[i].b,i));
			}
			if(i-cnt<i/2){
				num2 u2;
				while(!q2.empty()){
					u2=q2.top();
					q2.pop();
					if(u2.id2>i)break;
				}
				num1 u1=q1.top();
				q1.pop();
				p[u2.id2].v=1;
				p[u1.id2].v=0;
				cnt--;
			}
		}
		ll ans=0;
		for(int i=1;i<n;++i)if(p[i].v)ans+=p[i].b;
		cout<<ans<<endl;
//	}
	return 0;
}
