#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<set>
using namespace std;

const int maxn=25e5+5;

char s[maxn];
int cnt=0,n;
char word[1005][25],w[1005][25];
set<string>S;

void read(){
	int c=0;
	for(int i=0;s[i];++i)if(s[i]>='A'&&s[i]<='Z')s[i]=s[i]-'A'+'a';
	int l=strlen(s);
	for(int i=0;i<=l;++i){
		if(s[i]>='a'&&s[i]<='z')word[cnt][c++]=s[i];
		else{
			if(c){
				word[cnt][c]=0;
				c=0;
				++cnt;
			}
			if(s[i]!=' '&&s[i]!=0){
				if(cnt){
					for(int j=0;j<cnt;++j){
						string tmp;
						for(int k=0;k<n&&j+k<cnt;++k){
							tmp+=string(word[j+k])+' ';
							S.insert(tmp);
						}
					}
					cnt=0;
				}
			}
		}
	}
}

void solve(){
	int c=0;
	int l=strlen(s);
	for(int i=0;i<=l;++i){
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))word[cnt][c++]=s[i];
		else{
			if(c){
				word[cnt][c]=0;
				c=0;
				++cnt;
			}
			if(s[i]!=' '&&s[i]!=0){
				if(cnt){
					for(int j=0;j<cnt;++j){
						int l=strlen(word[j]);
						for(int k=0;k<=l;++k){
							if(word[j][k]>='A'&&word[j][k]<='Z'){
								w[j][k]=word[j][k]-'A'+'a';
							}
							else w[j][k]=word[j][k];
						}
					}
					bool f=0;
					for(int j=0;j<cnt;++j){
						string tmp=string(w[j])+' ';
						if(S.find(tmp)==S.end()){
							printf("What does the word \"%s\" mean?\n",word[j]);
							S.insert(tmp);
						}
					}
					for(int j=0;j<cnt;++j){
						string tmp;
						for(int k=0;k<n&&j+k<cnt;++k){
							tmp+=string(w[j+k])+' ';
							if(S.find(tmp)==S.end()){
								f=1;
								S.insert(tmp);
							}
						}
					}
					if(f){
						printf("What does the sentence \"");
						for(int j=0;j<cnt;++j){
							if(j)putchar(' ');
							printf("%s",word[j]);
						}
						printf("\" mean?\n");
					}
					cnt=0;
				}
			}
		}
	}

}

int main(){
	int q=0;
	while(scanf("%d",&n)!=EOF){
		gets(s);
		if(q)printf("\n");
		printf("Learning case %d\n",++q);
		S.clear();
		S.insert(string("joe "));
		while(gets(s)&&s[0]!='*')read();
		s[0]='.';
		s[1]=0;
		read();
		while(gets(s)&&s[0]!='#')solve();
		s[0]='.';
		s[1]=0;
		solve();
	}
	return 0;
}
