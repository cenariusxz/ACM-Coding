#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
	int a,b,c,x,y,z;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&x,&y,&z);
	if(a>b)swap(a,b);
	if(a>c)swap(a,c);
	if(b>c)swap(b,c);
	if(x>y)swap(x,y);
	if(x>z)swap(x,z);
	if(y>z)swap(y,z);
	int ans=0;
	bool f=0;
	if(x==a&&y==b&&z==c){
		printf("YES\n0\n");
		return 0;
	}
	while((z-y!=y-x)&&z>=c&&x<=a&&!f){
		if(z-y<y-x){
			if(a==x&&(z-y)==(c-b)&&!((z-c)%(z-y))){
				f=1;
				int num=(z-c)/(z-y),dis=z-y;
				ans+=num;
				z-=dis*num;
				y-=dis*num;
			}
			else{
				int num=(y-x)/(z-y),dis=z-y;
				ans+=num;
				z-=dis*num;
				y-=dis*num;
			}
		}
		else{
			if(z==c&&(y-x)==(b-a)&&!((a-x)%(y-x))){
				f=1;
				int num=(a-x)/(y-x),dis=y-x;
				ans+=num;
				x+=dis*num;
				y+=dis*num;
			}
			else{
				int num=(z-y)/(y-x),dis=y-x;
				ans+=num;
				x+=dis*num;
				y+=dis*num;
			}
		}
	}
	if(f)printf("YES\n%d\n",ans);
	else printf("NO\n");
	return 0;
}
