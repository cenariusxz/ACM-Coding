#include<stdio.h>
#include<string.h>
typedef unsigned int ui;

int a,b,c,d,n,l1,r1;

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int q=1;q<=T;q++){
			scanf("%d%d%d%d%d%d%d",&n,&l1,&r1,&a,&b,&c,&d);
			bool ff=0;
			ui l=l1,r=r1;
			if(l1>r1){
				int t=l1;
				l1=r1;
				r1=t;
				ff=1;
			}
			int i;
			ui ml=l1,mr=r1;
			if(ff){
				int t=l1;
				l1=r1;
				r1=t;
			}
			for(i=2;i<=n;i++){
				l=(l*a+b);
				r=(r*c+d);
				bool f=0;
				if(l>r){
					ui t=l;
					l=r;
					r=t;
					f=1;
				}
				if(l>ml)ml=l;
				if(r<mr)mr=r;
				if(f){
					ui t=l;
					l=r;
					r=t;
				}
			}
			bool f=0;
			ff=0;
			if(l1>r1){
				int t=l1;
				l1=r1;
				r1=t;
				ff=1;
			}
			if(r1<ml&&l1>mr)f=1;
			if(ff){
				int t=l1;
				l1=r1;
				r1=t;
			}
			l=l1;r=r1;
			for(i=2;i<=n&&!f;i++){
				l=(l*a+b);
				r=(r*c+d);
				ff=0;
				if(l>r){
					ui t=l;
					l=r;
					r=t;
					ff=1;
				}
				if(l>mr&&r<ml)f=1;
				if(ff){
					ui t=l;
					l=r;
					r=t;
					ff=1;
				}
			}
			if(f)printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
