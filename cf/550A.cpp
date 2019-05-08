#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

char s[100005];

int main(){
	s[0]=0;
	memset(s,0,sizeof(s));
	scanf("%s",s+1);
	int l=strlen(s+1),i;
	int a=0,b=0,ab=0,ba=0;
	for(i=1;i<l;i++){
		if(s[i]=='A'&&s[i+1]=='B'){
			ab++;
			a=i;
		}
		else if(s[i]=='B'&&s[i+1]=='A'){
			ba++;
			b=i;
		}
	}
	if(ab>=2&&ba>=2){
		printf("YES\n");
	}
	else if(ab==0||ba==0){
		printf("NO\n");
	}
	else if(ab==1){
		if(ba==1&&(s[a+2]=='A'||s[a-1]=='B'))printf("NO\n");
		else if(ba==2&&s[a+2]=='A'&&s[a-1]=='B')printf("NO\n");
		else printf("YES\n");
	}
	else if(ba==1){
		if(ab==2&&s[b-1]=='A'&&s[b+2]=='B')printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
