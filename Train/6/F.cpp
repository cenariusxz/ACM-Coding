#include<stdio.h>
#include<string.h>

int main()
{
	int u,r,d,l,q;
	int t;
	char s[100010];
	scanf("%d",&t);
	while(t-->0){
		scanf("%s",s);
		u=r=d=l=q=0;
		int ll=strlen(s);
		for(int i=0;i<ll;i++){
			switch(s[i]){
				case('U'):u++;break;
				case('R'):r++;break;
				case('D'):d++;break;
				case('L'):l++;break;
				case('?'):q++;break;
			}
		}
		//printf("%d %d %d %d %d\n",u,r,d,l,q);
		printf("%d %d %d %d\n",-l-q+r,-d-q+u,r+q-l,u+q-d);
	}
}
