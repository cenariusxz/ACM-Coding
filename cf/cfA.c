#include<stdio.h>
#include<string.h>
const int MAXM=1000000;

char s[MAXM*2+5],tmp1[MAXM*2+5],tmp2[MAXM*2+5];
int b[MAXM+5],p[MAXM+5],t[MAXM+5],cnt=0,l;
bool f=0;

void run(){
	strcpy(tmp1,s);
	for(int i=1;i<=cnt;i++){
		memset(tmp2,0,sizeof(tmp2));
		strcpy(tmp2,s+p[t[i]]);
		strcat(tmp2,s);
		
		if(strcmp(tmp1,tmp2)>0)strcpy(tmp1,tmp2);
	}
	if(f){
		int c=0,i;
		for(i=p[l-1];i<l;i++){
			tmp2[c++]=s[i];
		}
		for(i=0;i<p[l-1];i++){
			tmp2[c++]=s[i];
		}
		if(strcmp(tmp1,tmp2)>0){
			strcpy(tmp1,tmp2);
		}
	}
}

int main(){
	memset(b,0,sizeof(b));
	memset(p,0,sizeof(p));
	scanf("%s",s);
	l=strlen(s);
	int i,ans=0,sl=0,sr=0,l0=0;
	bool f1=1;
	if(s[0]==')'){
		b[0]=0;
		sr++;
		f1=0;
	}
	else{
		b[0]=1;
		p[0]=0;
		t[++cnt]=0;
		sl++;
		l0++;
	}
	ans=b[1];
	for(i=1;i<l;i++){
		if(s[i]==')'){
			if(f1)f1=0;
			b[i]=0;
			sr++;
		}
		else{
			sl++;
			if(f1)l0++;
			if(b[i-1]>0){
				b[i]=b[i-1]+1;
				p[i]=p[i-1];
			}
			else{
				b[i]=1;
				p[i]=i;
			}
		}
		if(b[i]==ans)t[++cnt]=i;
		else if(b[i]>ans){
			ans=b[i];
			cnt=0;
			t[++cnt]=i;
		}
	}
	if(s[0]=='('){
		if(l0+b[l-1]==ans)f=1;
		else if(l0+b[i-1]>ans){
			ans=l0+b[i-1];
			f=1;
			cnt=0;
		}
	}
	if(sl<sr){
		for(i=1;i<=sr-sl;i++)printf("(");
	}
	run();
	for(i=0;i<l;i++)printf("%c",tmp1[i]);
	if(sl>sr){
		for(i=1;i<=sl-sr;i++){
			printf(")");
		}
	}
	printf("\n");
	return 0;
}
