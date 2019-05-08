#include<stdio.h>
#include<string.h>

char a[4005],b[1005];
int c[1005],d[1005],p[1005];

int main(){
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	while(scanf("%s%s",a+1,b+1)!=EOF){
	int l1=strlen(a+1),l2=strlen(b+1);
	int i,j,cnt1=0;
	for(i=1;i<=l1;i++){
		if(a[i]>='a'&&a[i]<='z'){
			if(a[i]!=a[cnt1]){
				a[++cnt1]=a[i];
				c[cnt1]=1;
			}
			else{
				c[cnt1]++;
			}
		}
		if(a[i]=='['){
			i++;
			c[cnt1]--;
			int tmp=0;
			while(a[i]!=']'){
				tmp=tmp*10+(a[i]-'0');
				i++;
			}
			c[cnt1]+=tmp;
		}
	}
	int cnt2=0;
	for(i=1;i<=l2;i++){
		if(i==1){
			b[++cnt2]=b[1];
			d[cnt2]=1;
		}
		else{
			if(b[i]==b[i-1])d[cnt2]++;
			else{
				b[++cnt2]=b[i];
				d[cnt2]=1;
			}
		}
	}/*
	for(i=1;i<=cnt1;i++){
		printf("%c%d",a[i],c[i]);
	}
	printf("\n");
	for(i=1;i<=cnt2;i++){
		printf("%c%d",b[i],d[i]);
	}
	printf("\n");*/
	p[1]=0;
	i=0,j=1;
	bool f=0;
	for(i=1;i<=cnt1+1-cnt2;i++){
		f=1;
		for(j=1;j<=cnt2;j++){
			if(j==1||j==cnt2){
				if(a[i+j-1]!=b[j]||c[i+j-1]<d[j]){
					f=0;
					break;
				}
			}
			else{
				if(a[i+j-1]!=b[j]||c[i+j-1]!=d[j]){
					f=0;
					break;
				}
			}
		}
		if(f)break;
	}
	if(f)printf("True\n");
	else printf("False\n");
	}
}
