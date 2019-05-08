#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

struct point{
	int x,y,z;
}p[5];

struct seg{
	int a,b;
	ll l;
}s[7];

bool cmp(seg a,seg b){
	return a.l>b.l;
}

int m[5];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int q=1;q<=n;q++){
			int i,j;
			for(i=1;i<=4;i++){
				scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
			}
			int c=0;
			for(i=1;i<=3;i++){
				for(j=i+1;j<=4;j++){
					++c;
					s[c].a=i;
					s[c].b=j;
					s[c].l=((ll)p[i].x-p[j].x)*(p[i].x-p[j].x)+((ll)p[i].y-p[j].y)*(p[i].y-p[j].y)+((ll)p[i].z-p[j].z)*(p[i].z-p[j].z);
				}
			}
			sort(s+1,s+c+1,cmp);
			m[1]=s[1].a;
			m[2]=s[1].b;
			m[3]=s[2].a;
			m[4]=s[2].b;
			bool f=1;
			if(s[1].l!=s[2].l)f=0;
			if(s[3].l!=s[4].l)f=0;
			if(s[4].l!=s[5].l)f=0;
			if(s[5].l!=s[6].l)f=0;
			if(s[3].l*2!=s[1].l)f=0;
			if(f)printf("Case #%d: Yes\n",q);
			else printf("Case #%d: No\n",q);
		}
	}
	return 0;
}
