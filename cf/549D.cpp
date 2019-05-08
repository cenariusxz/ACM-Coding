#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int MAX=140;

int data[MAX][MAX];
int ss[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	int N, M, ans = 0;
	string strTmp;
	scanf("%d%d",&N,&M);
	memset(data,0,sizeof(data));
	memset(ss,0,sizeof(ss));
	for(int i=1;i<=N;i++){
		cin>>strTmp;
		for(int j=1;j<=M;j++){
			if(strTmp[j-1]=='B'){data[i][j]=-1;}
			if(strTmp[j-1]=='W'){data[i][j]=1;}
		}
	}
	for(int i=N;i>=1;i--){
		for(int j=M;j>=1;j--){
			ss[i][j]=ss[i][j+1]+ss[i+1][j]-ss[i+1][j+1];
			if(ss[i][j]==data[i][j]){continue;}
			else{
				int k=data[i][j]-ss[i][j];
				if(k!=0){ss[i][j]+=k;}
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
