#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=1e5+5;

char ct[27];
char s[maxn],tmp[maxn];
int ext[maxn],nxt[maxn];

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

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",ct,s);
		int len=strlen(s);
		for(int i=0;i<len;++i)tmp[i]=ct[s[i]-'a'];
		EKMP(tmp,s,len,len);
		int i;
		for(i=(len+1)/2;i<len;++i){
			if(ext[i]==len-i){
				break;
			}
		}
		i--;
		for(int j=0;j<=i;++j)putchar(s[j]);
		for(int j=0;j<=i;++j){
			for(int k=0;k<26;++k){
				if(ct[k]==s[j]){
					putchar('a'+k);
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
