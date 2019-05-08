#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> pii;

struct cmp{
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

int a[200005],b[200005];

int main(){
	int n;
	scanf("%d",&n);
	int i;
	b[0]=0;
	a[0]=2;
	priority_queue<pii,vector<pii>,cmp>q[3];
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		q[a[i]%3].push(make_pair(a[i],i));
	}
	bool f=1;
	for(i=1;i<=n&&f;i++){
		if(!q[(i-1)%3].empty()){
			pii u=q[(i-1)%3].top();
			q[(i-1)%3].pop();
			if(u.first==a[b[i-1]]+1||u.first==a[b[i-1]]-2){
				b[i]=u.second;
			}
			else f=0;
		}
		else f=0;
	}
	if(f){
		printf("Possible\n");
		for(i=1;i<=n;i++){
			printf("%d",b[i]);
			if(i==n)printf("\n");
			else printf(" ");
		}
	}
	else printf("Impossible\n");
	return 0;
}
