#include<stdio.h>
#include<string.h>

bool vis[5][14];
char s[5][3];

int gcd(int a,int b){
	for(;a>0&&b>0;a>b?a%=b:b%=a);
	return a+b;
}

int judge(int a,int b){
	bool f=0;
	bool vis2[14];
	memset(vis2,0,sizeof(vis2));
	int pos=a;
	int i,j;
	vis2[b]=1;
	for(i=1;i<=13;i++){
		for(j=1;j<=4;j++){
			if(vis[j][i]){
				vis2[i]=1;
				if(pos!=j)f=1;
			}
		}
	}
/*	for(i=1;i<=13;i++)if(vis2[i])printf("%d ",i);
	printf("\n");
*/	if(!f)return 0;
	f=0;
	bool ff=1;
	for(i=1;i<=9;i++){
		ff=1;
		for(j=0;j<=4&&ff;j++){
			if(!vis2[i+j])ff=0;
		}
		if(ff)return 1;
	}
	if(vis2[1]&&vis2[10]&&vis2[11]&&vis2[12]&&vis2[13])return 1;
	return 0;

}

int main(){
	int i;
	while(scanf("%s",s[1])!=EOF){
		memset(vis,0,sizeof(vis));
		for(i=2;i<=4;i++)scanf("%s",s[i]);
//		for(i=1;i<=4;i++)printf("%s\n",s[i]);
		for(i=1;i<=4;i++){
			if(s[i][0]=='1'){
				if(s[i][2]=='S')vis[1][10]=1;
				if(s[i][2]=='H')vis[2][10]=1;
				if(s[i][2]=='C')vis[3][10]=1;
				if(s[i][2]=='D')vis[4][10]=1;
			}
			else if(s[i][0]=='J'){
				if(s[i][1]=='S')vis[1][11]=1;
				if(s[i][1]=='H')vis[2][11]=1;
				if(s[i][1]=='C')vis[3][11]=1;
				if(s[i][1]=='D')vis[4][11]=1;
			}
			else if(s[i][0]=='Q'){
				if(s[i][1]=='S')vis[1][12]=1;
				if(s[i][1]=='H')vis[2][12]=1;
				if(s[i][1]=='C')vis[3][12]=1;
				if(s[i][1]=='D')vis[4][12]=1;
			}
			else if(s[i][0]=='K'){
				if(s[i][1]=='S')vis[1][13]=1;
				if(s[i][1]=='H')vis[2][13]=1;
				if(s[i][1]=='C')vis[3][13]=1;
				if(s[i][1]=='D')vis[4][13]=1;
			}
			else if(s[i][0]=='A'){
				if(s[i][1]=='S')vis[1][1]=1;
				if(s[i][1]=='H')vis[2][1]=1;
				if(s[i][1]=='C')vis[3][1]=1;
				if(s[i][1]=='D')vis[4][1]=1;
			}
			else{
				if(s[i][1]=='S')vis[1][s[i][0]-'0']=1;
				if(s[i][1]=='H')vis[2][s[i][0]-'0']=1;
				if(s[i][1]=='C')vis[3][s[i][0]-'0']=1;
				if(s[i][1]=='D')vis[4][s[i][0]-'0']=1;
			}
		}
		int ans=0;
		for(i=1;i<=4;i++){
			for(int j=1;j<=13;j++){
				if(!vis[i][j]){
					ans+=judge(i,j);
				}
			}
		}
		if(ans==0){printf("0/1\n");continue;}
		int g=gcd(48,ans);
		printf("%d/%d\n",ans/g,48/g);
	}
	return 0;
}
