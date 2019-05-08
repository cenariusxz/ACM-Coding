#include <stdio.h>

const int MAXN = 100010;

int n,m,k;
int w[MAXN],t[MAXN];
int pre[MAXN];

int main(){
	while(scanf("%d%d%d",&n,&m,&k) != EOF){
		for(int i = 1; i <= n; ++i){
			scanf("%d",&w[i]);
		}
		for(int i = 1; i <= m; ++i){
			scanf("%d",&t[i]);
		}
		int pos = 1,total = w[1];
		pre[1] = 1;
		for(int i = 2; i <= n; ++i){
			total += w[i];
			while(total - w[pos] > k){
				pos++;
				total -= w[pos];
			}
			pre[i] = pos;
			printf("pre[%d] : %d\n",i,pre[i]);
		}
		int now = 0,tm = 0;
		bool f = 0;
		for(int i = 1; i <= m; ++i){
			if(now + t[i] - tm - 1 >= n){
				printf("%d\n",tm + n - now);
				f = 1;
				break;
			}
			now += t[i] - tm - 1;
			tm = t[i];
		 	if(now)now = pre[now] - 1;
			//printf("tm : %d , now : %d\n",tm,now);
		}
		if(f) continue;
		printf("%d\n",tm + n - now);
	}
	return 0;
}
