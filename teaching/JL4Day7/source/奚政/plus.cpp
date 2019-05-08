#include <bits/stdc++.h>
using namespace std;

int n;
char s[105],t[105];
int a[105],b[105],c[105];
int lena,lenb,lenc;

void get(char s[],int a[],int len){
	for(int i = 0 ; s[i] ; ++ i){
		if(s[i] >= '0' && s[i] <= '9')a[i] = s[i] - '0';
		else a[i] = s[i] - 'A' + 10;
	}
	for(int i=0,j=len-1 ; i < j ; ++i,--j)swap(a[i],a[j]);
}

int main(){
	freopen("plus.in","r",stdin);
	freopen("plus.out","w",stdout);

	scanf("%d%s%s",&n,s,t);
	lena = strlen(s),lenb = strlen(t);
	lenc = max(lena,lenb);

	get(s,a,lena);
	get(t,b,lenb);

	for(int i = 0 ; i < lenc ; ++ i){
		c[i] += a[i] + b[i];
		c[i+1] += c[i] / n;
		c[i] %= n;
	}
	if(c[lenc])lenc++;

	for(int i = lenc-1 ; i >= 0 ; -- i){
		if(c[i] <= 9)printf("%d",c[i]);
		else printf("%c",c[i]-10+'A');
	}
	printf("\n");
	return 0;
}
