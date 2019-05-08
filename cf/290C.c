#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
char s[105][105];
int l[105];

int main(){
	int n,i,j;
	scanf("%d",&n);
	vector<char>le;
	for(i=1;i<=n;i++){
		scanf("%s",s[i]);
		l[i]=strlen(s[i]);
	}
	bool f=1;
	for(i=2;i<=n;i++){
		int m=(l[i]<l[i-1])?l[i]:l[i-1];
		for(j=0;j<m;j++){
			if(s[i][j]!=s[i-1][j]){
				find(s[i][j],s[i-1][j])
				break;
			}
			if(j==m-1&&l[i-1]>l[i])f=0;
		}
	}
	return 0;
}
