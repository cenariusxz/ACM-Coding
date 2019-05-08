#include<stdio.h>
#include<string.h>

char a[11],b[11];
int po[15];

int C(int m,int n){
	if(n==0)return 1;
	int i,s=1;
	for(i=1;i<=n;i++){
		s*=m-i+1;
		s/=i;
	}
	return s;
}

int p(int c0){
	if(po[c0])return po[c0];
	po[c0]=2*p(c0-1);
	return po[c0];
}

int main(){
	memset(po,0,sizeof(po));
	po[0]=1;
	int c1=0,c2=0,c0=0;
	scanf("%s%s",a,b);
	int l=strlen(a);
	int i;
	for(i=0;i<l;i++){
		if(a[i]=='+')c1++;
		if(b[i]=='+')c2++;
		else if(b[i]=='?')c0++;
	}
	int c=c1-c2;
	if(c>c0||c<0){
		printf("%.12lf\n",0.0);
	}
	else{
		int t=C(c0,c);
		int m=p(c0);
	//	printf("%d %d %d %d %d %d\n",c1,c2,c,c0,t,m);
		printf("%.12lf\n",t*1.0/m*1.0);
	}
	return 0;
}
