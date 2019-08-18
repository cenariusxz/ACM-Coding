#include <bits/stdc++.h>
using namespace std;
char s[1005],t[1005];
int a[1000005],b[1000005],c[1000005];
int E(char s[],char t[]){
	int A=strlen(s);
	int B=strlen(t);
	int C=A;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(int i=0;i<A;++i)a[i]=s[i]-'0';
	for(int i=0, j=A-1;i<j;++i,--j)swap(a[i],a[j]);
	for(int i=0;i<B;++i)b[i]=t[i]-'0';
	for(int i=0, j=B-1;i<j;++i,--j)swap(b[i],b[j]);
	for(int i=0;i<C;++i){
		c[i]+=a[i]-b[i];
		if(c[i]<0){
			c[i]+=10;
			c[i+1]--;
		}
	}
	while(c[C-1]==0&&C>1)C--;
	return C;
}
bool D(char s[],char t[]){
	int A=strlen(s),B=strlen(t);
	if(A>B)return 1;
	if(A<B)return 0;
	for(int i=0;i<A;++i){
		if(s[i]>t[i])return 1;
		if(s[i]<t[i])return 0;
	}
	return 1;
}

int main(){
	scanf("%s%s",s,t);
	int C;
	if(D(s,t))C=E(s,t);
	else C=E(t,s);
	if(D(s,t)==0)printf("-");
	for(int i=C-1;i>=0;--i) printf("%d",c[i]);
	return 0;
}

