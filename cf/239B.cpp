#include<stdio.h>
#include<string.h>

char a[105];
	char tmp[105];

void solve(int l,int r){
	int vis[11],i;
	bool is[105];
	memset(vis,0,sizeof(vis));
	memset(is,0,sizeof(is));
	for(i=l;i<=r;i++){
		tmp[i-l+1]=a[i];
	}
	int len=r-l+1;
	int pos=1,pre=0;
	bool f=1;	//1 >  0 <;
	bool ff=0;
	while(pos<=len&&pos>=1){
		if(is[pos]){
			if(f)pos++;
			else pos--;
		}
		else if(tmp[pos]=='0'){
			vis[0]++;
			is[pos]=1;
			if(f)pos++;
			else pos--;
			ff=0;
		}
		else if(tmp[pos]>='1'&&tmp[pos]<='9'){
			vis[tmp[pos]-'0']++;
			tmp[pos]--;
			if(f)pos++;
			else pos--;
			ff=0;
		}
		else if(tmp[pos]=='>'){
			if(ff){
				is[pre]=1;
			}
			pre=pos;
			ff=1;
			f=1;
			if(f)pos++;
			else pos--;
		}
		else if(tmp[pos]=='<'){
			if(ff){
				is[pre]=1;
			}
			pre=pos;
			ff=1;
			f=0;
			if(f)pos++;
			else pos--;
		}
	}
	for(i=0;i<=9;i++)printf("%d ",vis[i]);
	printf("\n");
}

int main(){
	int n,p;
	scanf("%d%d",&n,&p);
	scanf("%s",a+1);
	int i;
	for(i=1;i<=p;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		solve(l,r);
	}
	return 0;
}
