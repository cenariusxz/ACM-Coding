#include<stdio.h>
#include<string.h>
bool hash[16000005];
int c[128];
char s[16000005];

int main(){
	int N,nC;
	while(scanf("%d%d",&N,&nC)!=EOF){
		memset(c,-1,sizeof(c));
		memset(hash,0,sizeof(hash));
		scanf("%s",s);
		int t=0,tmp=1,NC = nC,ans=0,l=strlen(s),i,m=0,j;
		for(i=0;i<l;i++){
			if(c[s[i]]==-1){
				c[s[i]]=m;
				m++;}
			if(i==N-1){
				for(j=0;j<=N-1;j++){
					t+=c[s[j]]*tmp;
					tmp*=NC;}
				hash[t]=1;
				ans++;
				tmp/=NC;}
			else if(i>N-1){
				t/=NC;
				t+=c[s[i]]*tmp;
				if(!hash[t]){
					hash[t]=1;
					ans++;}	}}
		printf("%d\n",ans);
	
	}

	return 0;
}
