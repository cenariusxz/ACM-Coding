#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=4e5+5;
int nxt[maxn],ext[maxn];
char s[maxn],t[maxn];

void EKMP(char s[],char t[],int lens,int lent){
	int i,j,p,l,k;
	nxt[0]=lent;j=0;
	while(j+1<lent&&t[j]==t[j+1])j++;
	nxt[1]=j;
	k=1;
	for(i=2;i<lent;i++){
		p=nxt[k]+k-1;
		l=nxt[i-k];
		if(i+l<p+1)nxt[i]=l;
		else{
			j=max(0,p-i+1);
			while(i+j<lent&&t[i+j]==t[j])j++;
			nxt[i]=j;
			k=i;
		}
	}

	j=0;
	while(j<lens&&j<lent&&s[j]==t[j])j++;
	ext[0]=j;k=0;
	for(i=1;i<lens;i++){
		p=ext[k]+k-1;
		l=nxt[i-k];
		if(l+i<p+1)ext[i]=l;
		else{
			j=max(0,p-i+1);
			while(i+j<lens&&j<lent&&s[i+j]==t[j])j++;
			ext[i]=j;
			k=i;
		}
	}
}

int ans[maxn];

int main(){
	while(scanf("%s",s)!=EOF){
		strcpy(t,s);
		int l=strlen(s);
		EKMP(s,t,l,l);
		int cnt=0;
		for(int i=l-1;i>=0;--i){
			if(ext[i]==l-i)ans[++cnt]=l-i;
		}
		for(int i=1;i<=cnt;++i){
			printf("%d",ans[i]);
			if(i==cnt)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
