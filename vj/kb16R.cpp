#include<stdio.h>
#include<string.h>
const int maxm=5050*20;

int Nxt[maxm][26];
int tail[maxm];
int size;

void init_trie(){
	memset(Nxt[0],0,sizeof(Nxt[0]));
	memset(tail,0,sizeof(tail));
	size=1;
}

void insertword(char s[],int c){
	int p=0;
	for(int i=0;s[i];i++){
		int &x=Nxt[p][s[i]-'a'];
		if(!x){
			memset(Nxt[size],0,sizeof(Nxt[size]));
			x=size++;
		}
		p=x;
	}
	tail[p]=c;
}

int findword(char s[]){
	int p=0;
	for(int i=0;s[i];i++){
		int &x=Nxt[p][s[i]-'a'];
		if(!x)return 0;
		p=x;
	}
	return tail[p];
}

//n 1;	pron 2;	adj 3;	adv 4;	prep 5;	art 6;	vt 7;	vi 8;	v 9;
//				1		1		1		1

char s[100],t[20];
char a[25][105];
int vis[25],type[25];

bool check(int n){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i){
		type[i]=findword(a[i]);
	}
/*	for(int i=1;i<=n;++i){
		printf("%d ",type[i]);
	}
	printf("\n");*/
	for(int i=1;i<=n;++i){
		if(type[i]==6){
			if(i+1<=n&&type[i+1]==1)vis[i]=1;
			else if(i+2<=n&&type[i+1]==3&&type[i+2]==1)vis[i]=vis[i+1]=1;
			else return 0;
		}
		else if(type[i]==1){
			if(i-1>=1&&type[i-1]==6)vis[i-1]=1;
			else if(i-2>=1&&type[i-2]==6&&type[i-1]==3)vis[i-2]=vis[i-1]=1;
			else return 0;
		}
		else if(type[i]==3){
			if(i-1>=1&&type[i-1]==6&&i+1<=n&&type[i+1]==1)vis[i-1]=vis[i]=1;
			else return 0;
		}
		else if(type[i]==4){
			if(i+1<=n&&(type[i+1]==7||type[i+1]==8||type[i+1]==9))vis[i]=1;
			else return 0;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(!vis[i])strcpy(a[++cnt],a[i]);
	}
	n=cnt;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i){
		type[i]=findword(a[i]);
	}
/*	for(int i=1;i<=n;++i){
		printf("%d ",type[i]);
	}
	printf("\n");*/
	for(int i=1;i<=n;++i){
		if(type[i]==5){
			if(i+1<=n&&(type[i+1]==1||type[i+1]==2))vis[i]=vis[i+1]=1;
			else return 0;
		}
	}
	cnt=0;
	for(int i=1;i<=n;++i){
		if(!vis[i])strcpy(a[++cnt],a[i]);
	}
	n=cnt;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i){
		type[i]=findword(a[i]);
	}
/*	for(int i=1;i<=n;++i){
		printf("%d ",type[i]);
	}
	printf("\n");*/
	if(n==2){
		if((type[1]==1||type[1]==2)&&(type[2]==8||type[2]==9))return 1;
		else return 0;
	}
	if(n==3){
		if((type[1]==1||type[1]==2)&&(type[2]==7||type[2]==9)&&(type[3]==1||type[3]==2))return 1;
		else return 0;
	}
	return 0;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	init_trie();
	while(n--){
		scanf("%s%s",s,t);
		if(t[0]=='n')insertword(s,1);
		else if(t[0]=='p'&&t[2]=='o')insertword(s,2);
		else if(t[0]=='a'&&t[2]=='j')insertword(s,3);
		else if(t[0]=='a'&&t[2]=='v')insertword(s,4);
		else if(t[0]=='p'&&t[2]=='e')insertword(s,5);
		else if(t[0]=='a'&&t[2]=='t')insertword(s,6);
		else if(t[0]=='v'&&t[1]=='t')insertword(s,7);
		else if(t[0]=='v'&&t[1]=='i')insertword(s,8);
		else if(t[0]=='v'&&t[1]=='.')insertword(s,9);
	}
	char c=getchar();
	while(c!='\n')c=getchar();
	while(m--){
		int cnt=1,len=0;
		while(1){
			a[cnt][len++]=getchar();
			if(a[cnt][len-1]>='A'&&a[cnt][len-1]<='Z'){
				a[cnt][len-1]=a[cnt][len-1]-'A'+'a';
			}
			else if(a[cnt][len-1]==' '){
				a[cnt][--len]=0;
				cnt++;
				len=0;
				continue;
			}
			else if(a[cnt][len-1]=='\n'){
				a[cnt][--len]=0;
				break;
			}
			else if(a[cnt][len-1]<'a'||a[cnt][len-1]>'z'){
				len--;
			}
		}
		if(check(cnt))printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
