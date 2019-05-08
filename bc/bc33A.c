#include<stdio.h>
#include<string.h>

char a[105][205],cc[40];
int l[105],ii[500],ans[205];

int read(int i){
	int m=0;
	char c=getchar();
	while(c==' '||c=='\n'){
		c=getchar();
	}
	while((c>='0'&&c<='9')||(c>='a'&&c<='z')){
		a[i][++m]=c;
		c=getchar();
	}
	return m;
}

void init(){
	int i;
	for(i=0;i<=9;i++){
		cc[i]=i+'0';
	}
	for(i=10;i<=35;i++){
		cc[i]=i-10+'a';
	}
}

int main(){
	int n,b;
	init();
	while(scanf("%d%d",&n,&b)!=EOF){
		memset(l,0,sizeof(l));
		int i,ll=0;
		for(i=1;i<=n;i++){
			l[i]=read(i);
			if(l[i]>ll)ll=l[i];
		}
		for(i=1;i<=ll;i++){
			ans[i]=0;
		}
		for(i=1;i<=n;i++){
			int cl,j;
			cl=ll-l[i];
			for(j=1;j<=l[i];j++){
				int num;
				if(a[i][j]>='0'&&a[i][j]<='9')num=a[i][j]-'0';
				else if(a[i][j]>='a'&&a[i][j]<='z')num=a[i][j]-'a'+10;
				ans[j+cl]=(ans[j+cl]+num)%b;
			}
		}
		bool f=1;
		for(i=1;i<=ll;i++){
			if(i!=ll&&ans[i]==0&&f){
				
			continue;
			}
			else f=0;
			printf("%c",cc[ans[i]]);
		}
		printf("\n");
	}
	return 0;
}
