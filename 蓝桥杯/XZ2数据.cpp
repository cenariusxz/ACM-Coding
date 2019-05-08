#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;


char s[30];
int vis[30];

int main(){
	srand(time(NULL));
	printf("100\n");
	printf("abcdefghijklmnopqrstuvwxyz\ndcba hgfe\nqwertyuiopasdfghjklzxcvbnm\nabc def\nqwertyuiopasdfghjklzxcvbnm\nwertyuiopasdfghjklzxcvbnmq wertyuiopasdfghjklzxcvbnmq\n");
	for(int i=1;i<=97;++i){
		memset(vis,0,sizeof(vis));
		for(int j=0;j<26;++j){
			int p=rand()%26+1;
			int pos=0;
			while(1){
				if(!vis[pos])p--;
				if(p==0){
					putchar(pos+'a');
					s[j]=pos+'a';
					vis[pos]=1;
					break;
				}
				pos=(pos+1)%26;
			}
		}
		printf("\n");
		int l1=rand()%9999+1,l2=rand()%9999+1;
		if(l1==1){
			putchar(s[rand()%26]);
		}
		else{
			putchar(s[rand()%25+1]);
			for(int j=1;j<l1;++j){
				putchar(s[rand()%26]);
			}
		}
		printf(" ");
		if(l2==1){
			putchar(s[rand()%26]);
		}
		else{
			putchar(s[rand()%25+1]);
			for(int j=1;j<l2;++j){
				putchar(s[rand()%26]);
			}
		}
		printf("\n");
	}
	return 0;
}
