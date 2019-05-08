#include <stdio.h>
#include <string.h>

char S[1010];
int N;
int pos[30][2];
int ans[30];

int main(){
	int T;
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%s",S + 1);
		N = strlen(S + 1);
		memset(pos,0,sizeof(pos));
		memset(ans,0,sizeof(ans));
		for(int i = 1; i <= N; ++i){
			int id = S[i] - 'A';
			if(pos[id][0] == 0) pos[id][0] = i;
			else pos[id][1] = i;
		}
		for(int i = 1; i <= N; ++i){
			int id = S[i] - 'A';
			if(ans[id] == 0){
				if(i != 1) ans[id] = 1;
				int p = i + 1;
				while(p != pos[id][1]){
					ans[id]++;
					p = pos[S[p] - 'A'][1] + 1;
				}
			}
		}
		printf("Case %d\n",tt);
		for(int i = 0; i < 26; ++i){
			if(ans[i]){
				printf("%c = %d\n",'A' + i,ans[i]);
			}
		}
	}
	return 0;
}
