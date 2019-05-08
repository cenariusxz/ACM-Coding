#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define eps 1e-5

const int maxn=5;

int num[25];
int x[25],y[25],z[25],ansx[25],ansy[25],ansz[25],ans[5];
char s[100];
int anss[8005][3];

int main(){
	int p,q;
	while(scanf("%d%d",&p,&q)!=EOF&&(p+q)){
		int i,j,k;
		memset(ans,0,sizeof(ans));
		memset(num,0,sizeof(num));
		for(i=0;i<p+q;i++){
			x[i+1]=x[i];
			y[i+1]=y[i];
			z[i+1]=z[i];
			scanf("%s",s);
			bool f=1;
			for(j=0;j<strlen(s);j++){
				if(f&&s[j]=='.'){
					num[i]++;
				}
				else f=0;
				if(s[j]=='(')x[i+1]++;
				if(s[j]==')')x[i+1]--;
				if(s[j]=='[')y[i+1]++;
				if(s[j]==']')y[i+1]--;
				if(s[j]=='{')z[i+1]++;
				if(s[j]=='}')z[i+1]--;
			}
		}
	//	for(i=0;i<p+q;i++)printf("%d %d %d %d\n",x[i],y[i],z[i],num[i]);
		memset(ansx,0,sizeof(ansx));
		memset(ansy,0,sizeof(ansy));
		memset(ansz,0,sizeof(ansz));
		int c=0;
		for(i=1;i<=20;i++){
			for(j=1;j<=20;j++){
				for(k=1;k<=20;k++){
					bool f=1;
					for(int o=1;o<p&&f;o++){
						if(x[o]*i+y[o]*j+z[o]*k!=num[o])f=0;
					}
					if(f){
						++c;
						anss[c][0]=i;
						anss[c][1]=j;
						anss[c][2]=k;

						ansx[i]=1;
						ansy[j]=1;
						ansz[k]=1;
					}
				}
			}
		}
		int cnt=0;
		for(i=1;i<=20;i++){
			if(ansx[i]){
				cnt++;
				ans[0]=i;
			}
		}
		if(cnt!=1)ans[0]=0;
		cnt=0;
		for(i=1;i<=20;i++){
			if(ansy[i]){
				cnt++;
				ans[1]=i;
			}
		}
		if(cnt!=1)ans[1]=0;
		cnt=0;
		for(i=1;i<=20;i++){
			if(ansz[i]){
				cnt++;
				ans[2]=i;
			}
		}
		if(cnt!=1)ans[2]=0;
	/*	for(i=0;i<=2;i++)printf("%d ",ans[i]);
		printf("\n");
	*/	for(i=p;i<p+q;i++){
			if((x[i]&&ans[0]==0)||(y[i]&&ans[1]==0)||(z[i]&&ans[2]==0)){
				bool f=1;
				int res=0;
				for(j=1;j<=c&&f;j++){
					if(j==1)res=x[i]*anss[j][0]+y[i]*anss[j][1]+z[i]*anss[j][2];
					else if(res!=x[i]*anss[j][0]+y[i]*anss[j][1]+z[i]*anss[j][2]){
						f=0;
					}
				}
				if(f)printf("%d",res);
				else printf("-1");
			}
			else printf("%d",x[i]*(int)ans[0]+y[i]*(int)ans[1]+z[i]*(int)ans[2]);
			if(i==p+q-1)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
