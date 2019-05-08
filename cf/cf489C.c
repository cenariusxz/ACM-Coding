#include<stdio.h>
#include<string.h>

int a[105],b[105];

int main(){
	int m,s,i,t;
	scanf("%d%d",&m,&s);
	if((m>1&&s==0)||s>9*m)printf("-1 -1\n");
	else if(m==1&&s==0)printf("0 0\n");
	else{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int tmp;
		t=s;
		tmp=s-9*(m-1);
		if(tmp<=1)
		{
			a[1]=1;
			t-=1;
		}
		else{
			a[1]=tmp;
			t-=tmp;
		}
		i=m;
		while(t){
			if(t>=9){
				a[i]=9;
				t-=9;
			}
			else{
				a[i]=t;
				t-=t;
			}
			i--;
		}
		for(i=1;i<=m;i++)printf("%d",a[i]);
		printf(" ");
		t=s;
		i=1;
		while(t){
			if(t>=9){
				b[i]=9;
				t-=9;
			}
			else{
				b[i]=t;
				t-=t;
			}
			i++;
		}
		for(i=1;i<=m;i++)printf("%d",b[i]);
		printf("\n");
	}
	return 0;
}
