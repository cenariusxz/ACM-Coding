#include <stdio.h>
#include <string.h>

const int maxn = 1005;

int score[maxn];
int vis[maxn];

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int team,id,num;
		scanf("%d-%d%d",&team,&id,&num);
		vis[team] = 1;
		score[team] += num;
	}
	int ans = 0;
	for(int i = 1 ; i <= 1000 ; ++i ){
		if(vis[i] && score[i] > score[ans])ans = i;
	}
	printf("%d %d\n",ans,score[ans]);
	return 0;
}
