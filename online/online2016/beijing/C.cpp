#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
const int maxn=505*55;

string tmp,res;
char s[1005];
map<string,int> M;
int ans;

int main(){
	ans=0;
	while(gets(s)!=NULL){
		if(s[0]=='#'){
			printf("%s:%d\n",res.c_str(),ans);
			M.clear();
			ans=0;
		}
		else{
			bool f=0;
			int len=strlen(s);
			string t[505];
			int cnt=0;
			for(int i=0;s[i];++i){
				if(s[i]==','||s[i]=='.'){
					if(f&&i>0&&s[i-1]>='a'&&s[i-1]<='z'){
						tmp=t[cnt-1]+' '+t[cnt];
						M[tmp]++;
						if(M[tmp]>ans){
							ans=M[tmp];res=tmp;
						}
						else if(M[tmp]==ans&&tmp<res)res=tmp;
					}
					f=0;
					if(i>0&&s[i-1]>='a'&&s[i-1]<='z')cnt++;
				}
				else if(s[i]==' '){
					if(f&&i>0&&s[i-1]>='a'&&s[i-1]<='z'){
						tmp=t[cnt-1]+' '+t[cnt];
						M[tmp]++;
						if(M[tmp]>ans){
							ans=M[tmp];res=tmp;
						}
						else if(M[tmp]==ans&&tmp<res)res=tmp;
					}
					if(i>0&&s[i-1]>='a'&&s[i-1]<='z'){
						f=1;
						cnt++;
					}
				}
				else if(s[i]>='a'&&s[i]<='z'){
					t[cnt]+=s[i];
				}
			}
			int i=len-1;
			if(f&&i>0&&s[i]>='a'&&s[i]<='z'){
				tmp=t[cnt-1]+' '+t[cnt];
				M[tmp]++;
				if(M[tmp]>ans){
					ans=M[tmp];res=tmp;
				}
				else if(M[tmp]==ans&&tmp<res)res=tmp;
			}

		}
	}
}
