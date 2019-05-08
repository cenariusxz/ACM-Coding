#include<stdio.h>
#include<string.h>

int fa[605],num[605],n,num1[605],num2[605],p[605],dp[605][605],fat[605][605],num3[605];
int p1,p2;
char s[5];

int mmax(int a,int b){
	return a>b?a:b;
}

void init(){
	for(int i=1;i<=p1+p2;i++){
		fa[i]=i;
		num1[i]=1;
	}
	memset(num,0,sizeof(num));
	memset(num2,0,sizeof(num2));
}

int find(int x){
	int r=x,t1,t2,c=0;
	while(r!=fa[r]){
		c+=num[r];
		r=fa[r];
	}
	while(r!=x){
		t1=fa[x];
		t2=c-num[x];
		num[x]=c%2;
		fa[x]=r;
		x=t1;
		c=t2;
	}
	return r;
}

int main(){
	while(scanf("%d%d%d",&n,&p1,&p2)!=EOF&&n!=0||p1!=0||p2!=0){
		int i;
		init();
		for(i=1;i<=n;i++){
			int a,b,v;
			scanf("%d%d%s",&a,&b,s);
			if(s[0]=='y')v=0;
			else v=1;
			int x=find(a),y=find(b);
			if(x!=y){
				num[x]=((num[b]+v-num[a])%2+2)%2;
				if(num[x]==0){
					num1[y]+=num1[x];
					num2[y]+=num2[x];
				}
				else{
					num1[y]+=num2[x];
					num2[y]+=num1[x];
				}
				fa[x]=y;
			}
		}
		bool f=1;
		if(p1==p2)printf("no\n");
		else{
			int cnt=0,j;
			for(i=1;i<=p1+p2;i++){
				if(fa[i]==i){
					p[++cnt]=i;
					if(num1[i]==num2[i])f=0;
				}
			}
			if(f){
				memset(dp,0,sizeof(dp));
				dp[0][0]=1;
				for(i=1;i<=cnt;i++){
					for(j=0;j<=p1;j++){
						if(dp[i-1][j]){
							dp[i][j+num1[p[i]]]+=dp[i-1][j];
							fat[i][j+num1[p[i]]]=j;
							dp[i][j+num2[p[i]]]+=dp[i-1][j];
							fat[i][j+num2[p[i]]]=j;
						}
					}
				}
				if(dp[cnt][p1]!=1)f=0;
			}
			if(!f)printf("no\n");
			else{
				int father=p1;
				for(i=cnt;i>=1;i--){
					if(father-fat[i][father]==num1[p[i]]){
						num3[p[i]]=0;
					}
					else num3[p[i]]=1;
					father=fat[i][father];
				}
				for(i=1;i<=p1+p2;i++){
					int x=find(i);
					if(num[i]==num3[x])printf("%d\n",i);
				}
				printf("end\n");
			}
		}
	}
	return 0;
}
