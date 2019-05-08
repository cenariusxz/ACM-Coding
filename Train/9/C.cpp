#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

int dx[30],dy[30];
char M[6][6];
int vis[30];
string s;

void print(int c1,int c2){
	if(dx[c1]==dx[c2]){
		printf("%c%c",M[dx[c1]][(dy[c1]+1)%5],M[dx[c2]][(dy[c2]+1)%5]);
	}
	else if(dy[c1]==dy[c2]){
		printf("%c%c",M[(dx[c1]+1)%5][dy[c1]],M[(dx[c2]+1)%5][dy[c2]]);
	}
	else{
		printf("%c%c",M[dx[c1]][dy[c2]],M[dx[c2]][dy[c1]]);
	}
}

void solve(){
	getline(cin,s);
	int l=s.length();
	int pos=0;
	int tmp=0;
	while(1){
		int c1=-1,c2=-1;
		bool f=0;
		for(pos;pos<l;++pos){
			if(s[pos]>='a'&&s[pos]<='z'){
				s[pos]=s[pos]-'a'+'A';
			}
			if(s[pos]>='A'&&s[pos]<='Z'){
				if(c1<0){
					c1=s[pos]-'A';
					continue;
				}
				else{
					if(s[pos]-'A'==c1){
						while(tmp=='J'-'A'||tmp==c1){
							tmp=(tmp+1)%26;
						}
						c2=tmp;
						tmp=(tmp+1)%26;
						break;
					}
					else{
						c2=s[pos]-'A';
						pos++;
						break;
					}
				}
			}
		}
		if(c1<0&&c2<0){
			break;
		}
		if(c2<0){
			while(tmp=='J'-'A'||tmp==c1){
				tmp=(tmp+1)%26;
			}
			c2=tmp;
			tmp=(tmp+1)%26;
			f=1;
		}
		print(c1,c2);
		if(f)break;
	}
	printf("\n");
}

void init(){
	getline(cin,s);
	int l=s.length();
	memset(vis,0,sizeof(vis));
	vis['j'-'a']=1;
	int x=0,y=0;
	for(int i=0;i<l;++i){
		if(s[i]>='a'&&s[i]<='z'){
			s[i]=s[i]-'a'+'A';
		}
		if(s[i]>='A'&&s[i]<='Z'){
			int c=s[i]-'A';
			if(!vis[c]){
				dx[c]=x;
				dy[c]=y;
				M[x][y]='A'+c;
				y++;
				if(y==5){
					x++;
					y=0;
				}
				vis[c]=1;
			}
		}
	}
	for(int i=0;i<26;++i){
		int c=i;
		if(!vis[c]){
			dx[c]=x;
			dy[c]=y;
			M[x][y]='A'+c;
			y++;
			if(y==5){
				x++;
				y=0;
			}
			vis[c]=1;
		}
	}
}

int main(){
	int n;
	cin>>n;
	getchar();
	for(int q=1;q<=n;++q){
		init();
		printf("Case %d: ",q);
		solve();
	}
	return 0;
}
