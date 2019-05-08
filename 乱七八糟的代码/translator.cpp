#include<stdio.h>
#include<string.h>

const int maxn=1e5+5;

char s[maxn];

int getterm(int l,int len){
	if(l>=len)return l;
	if(s[l]==' ')return getterm(l+1,len);
	else{
		int pos=l;
		if(s[l]>='0'&&s[l]<='9'){
			printf("%c",s[l]);
		}
		return pos;
	}
}

void getrest(int l,int len){
	if(l>=len)return;
	if(s[l]==' ')getrest(l+1,len);
	else if(s[l]=='+'||s[l]=='-'){
		int pos=getterm(l+1,len);
		printf("%c",s[l]);
		getrest(pos+1,len);
	}
}

void getexpr(int l,int len){
	if(l>=len)return;
	int pos=getterm(l,len);
	getrest(pos+1,len);
}

int main(){
	gets(s);
	int len=strlen(s);
	getexpr(0,len);
	printf("\n");
	return 0;
}
