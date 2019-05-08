#include<stdio.h>
#include<stack>
using namespace std;

 bool run()
 {
 	char ch,ch2;
 	bool ok=1;
 	stack<char> s;
 	while(1){
 		ch=getchar();
 		if(ch=='\n') break;
 		if(ok)
 			if(ch=='('||ch=='[') s.push(ch);
 			else{
 				if(s.empty()){
 					ok=0;
 					continue;
 				}
 				ch2=s.top();
 				s.pop();
 				if(ch==']'&&ch2!='[') ok=0;
 				if(ch==')'&&ch2!='(') ok=0;
 			}
 	}
 	if(ok==0||!s.empty()) return 0;
 	return 1;
 }

int main()
{
	int n,i;
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++){
		printf(run()?"Yes\n":"No\n");
	}
 return 0;
}

