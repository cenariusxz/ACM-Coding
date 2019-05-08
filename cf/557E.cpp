#include<stdio.h>
#include<string.h>
const int maxm=400005;

int nxt[maxm][2],cnt[maxm],tail[maxm];
int size=1,l,r,k,len;
char s[5005];
int dp[5005][5005];

void insert(int t){
	int p=0;
	for(int i=t;i<=len;i++){
		int &x=nxt[p][s[i]-'a'];
		if(!x)x=size++;
		if(dp[t][i]){
			cnt[x]+=dp[t][i];
			if(dp[t][i]==dp[t][i+1]+1)tail[x]++;
		}
		p=x;
	}
}

void find(int p){
	if(k>tail[p]){
		k-=tail[p];
		for(int i=0;i<=1;i++){
			int x=nxt[p][i];
			if(k>cnt[x]){
				k-=cnt[x];
			}
			else{
				printf("%c",'a'+i);
				find(x);
				break;
			}
		}
	}
}

int main(){
	scanf("%s%d",s+1,&k);
	int i,j;
	len=strlen(s+1);
	for(i=1;i<=len;i++){
		for(l=1;l<=len-i+1;l++){
			r=l+i-1;
			if(r-l<=3&&s[l]==s[r]){
				dp[l][r]=1;
			}
			else if(dp[l+2][r-2]&&s[l]==s[r]){
				dp[l][r]=1;
			}
		}
	}
	for(i=1;i<=len;i++){
		for(j=len-1;j>=i;j--){
			dp[i][j]+=dp[i][j+1];
		}
	}
	for(i=1;i<=len;i++)insert(i);
	find(0);
	printf("\n");
	return 0;
}
