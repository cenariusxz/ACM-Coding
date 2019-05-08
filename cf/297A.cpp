#include<stdio.h>
#include<string.h>

char a[200000+5];
int b[30];

int main(){
	int n;
	scanf("%d%s",&n,a);
	int l=strlen(a);
	memset(b,0,sizeof(b));
	int ans=0;
	for(int i=0;i<l;i++){
		if(a[i]>='a'&&a[i]<='z'){
			b[a[i]-'a']++;
		}
		else if(a[i]>='A'&&a[i]<='Z'){
			if(b[a[i]-'A']>0)b[a[i]-'A']--;
			else ans++;
		}
	}
	printf("%d\n",ans);
	
	return 0;
}
