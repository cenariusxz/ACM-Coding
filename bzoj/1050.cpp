#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500+5;
const int maxm = 5000+5;
const int INF = 0x3f3f3f3f;
struct node{
	int x,y,v;
	bool operator < (const node a)const{
		return v < a.v;
	}
}nd[maxm];
int fa[maxn],n,m,s,t;

void init(int n){
    for(int i=0;i<=n;i++)fa[i]=i;
}

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void unio(int x,int y){
    int dx=find(x),dy=find(y);
    if(dx!=dy)fa[dx]=dy;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; ++ i){
		scanf("%d%d%d",&nd[i].x,&nd[i].y,&nd[i].v);	
	}
	scanf("%d%d",&s,&t);
	sort(nd+1,nd+1+m);
	int ans1 = INF, ans2 = 1;
	for(int i = 1 ; i <= m ; ++ i){
		init(n);
		bool flag = 0;
		for(int j = i ; j <= m ; ++ j){
			int x = nd[j].x, y = nd[j].y;
			if(find(x) != find(y)){
				unio(x,y);
				if(find(s) == find(t)){
					int v1 = nd[j].v;
					int v2 = nd[i].v;
					if(v1*(ll)ans2 < v2*(ll)ans1){
						ans1 = v1;
						ans2 = v2;
					}
					flag = 1;
					break;
				}
			}
		}
		if(!flag)break;
	}
	if(ans1 == INF)printf("IMPOSSIBLE\n");
	else if(ans1 % ans2 == 0)printf("%d\n",ans1/ans2);
	else{
		int g = __gcd(ans1,ans2);
		printf("%d/%d\n",ans1/g,ans2/g);	
	}
	return 0;
}
