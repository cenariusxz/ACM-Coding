#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int T,c;
char word[110][110];
char say[2000010];
char ani[110][110];

void Change(){
	int len = strlen(say);
	c = 0;
	int pos = 0;
	for(int i = 0; i < len; ++i){
		if(say[i] >= 'a' && say[i] <= 'z'){
			if(pos == 0) ++c;
			word[c][pos++] = say[i];
		}
		else if(say[i] == ' '){
			pos = 0;
		}
	}
}

int main(){
	scanf("%d",&T);
	//getchar();
	for(int tt = 1;  tt <= T; ++tt){
		memset(word,0,sizeof(word));
		memset(say,0,sizeof(say));
		memset(ani,0,sizeof(ani));
		getchar();
		gets(say);
		Change();
		//for(int i = 1; i <= c; ++i){
		//	printf("say : %s\n",word[i]);
		//}
		char s1[110],s2[110];
		int cnt = 0;
		while(1){
			scanf("%s%s",s1,s2);
			if(strcmp(s1,"what") == 0 && strcmp(s2,"does") == 0){
				scanf("%s%s",s1,s2);
				scanf("%s",s1);
				break;
			}
			++cnt;
			scanf("%s",ani[cnt]);
		}
		int s = 1;
		for(int i = 1; i <= c; ++i){
			bool f = true;
			for(int j = 1; j <= cnt; ++j){
				if(strcmp(word[i],ani[j]) == 0){
					f = false;
					break;
				}
			}
			if(!f) continue;
			if(s == 0) printf(" ");
			s = 0;
			printf("%s",word[i]);
		}
		puts("");
	}
	return 0;
}
