#include <bits/stdc++.h>
using namespace std;

char s[1005],t[1005],x;

void get(char *s,int& a,int &b){
	int d = 1, t1 = 0, t2 = 0, flag = 0;
	for(int i = 0 ; s[i] ; ++ i){
		if(s[i] == '-' || s[i] == '+'){
			a += d*t1;
			b += d*t2;
			t1 = 0;
			t2 = 0;
			flag = 0;
			if(s[i] == '-')d = -1;
			else d = 1;
		}
		else if(s[i] >= 'a' && s[i] <= 'z'){
			x = s[i];
			swap(t1,t2);
			if(flag == 0)t1 = 1;
		}
		else{
			t2 = t2 * 10 + s[i] - '0';
			flag = 1;
		}
	}
	a += d*t1;
	b += d*t2;
}

void solve(){
	for(int i = 0 ; s[i] ; ++ i){
		if(s[i] == '='){
			strcpy(t,s+i+1);
			s[i] = 0;
			break;
		}
	}
	int a=0,b=0,c=0,d=0;
	get(s,a,b);
	get(t,c,d);
	if(b==d)printf("%c=0.000\n",x);
	else printf("%c=%.3lf\n",x,(d-b)*1.0/(a-c));
}

int main(){
	while(scanf("%s",s)!=EOF)solve();
	return 0;
}
