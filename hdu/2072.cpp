#include<stdio.h>
#include<string.h>

int nxt[5000][26];
bool tail[5000];
int cnt,ans;

void insert(char word[]){
	int root=0;
	for(int i)	
	if(nxt[root][c-'a']<0){
			nxt[root][c-'a']=++cnt;
			memset(nxt[cnt],-1,sizeof(nxt[cnt]));
		}
		root=nxt[root][c-'a'];
		c=getchar();
	}
	if(!tail[root]&&root!=0){
		tail[cnt]=1;
		ans++;
	}
	if(c=='\n')f=0;
}

int main(){
	f2=1;
	while(f2){
		f=1;
		cnt=0;
		ans=0;
		memset(tail,0,sizeof(tail));
		memset(nxt[0],-1,sizeof(nxt[0]));
		while(f){
			insert();
		}
		if(f2)printf("%d\n",ans);
	}
	return 0;
}
