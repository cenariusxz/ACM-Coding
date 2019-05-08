#include <stdio.h>
#include <string.h>

int vis[50];
char s[10];

int main(){
	int n, ans = 0, cnt = 0;
	scanf("%d",&n);
	while(n--){
		scanf("%s",s);
		int len = strlen(s),sum = 0;
		for(int i = 0 ; i < len ; ++ i){
			sum += s[i] - '0';
		}
		vis[sum] = 1;
	}
	for(int i = 0 ; i < 40 ; ++i ){
		if(vis[i])ans++;
	}
	printf("%d\n",ans);
	for(int i = 0 ; i < 40 ; ++i ){
		if(vis[i]){
			if(cnt > 0)printf(" ");
			printf("%d",i);
			cnt++;
		}
	}
	printf("\n");
	return 0;
}
