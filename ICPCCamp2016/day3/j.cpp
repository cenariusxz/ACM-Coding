#include<stdio.h>
#include<string.h>

int ans[1005][1005];
int sz=48;
int n,nn;

void split(int a)
{
	int i,j,p,q,k,l;
	for(i=0;i<sz/a;i++){
		for(j=0;j<sz/a;j++){
			for(k=0;k<=1;k++){
				for(l=0;l<=1;l++){
					if(k==0&&l==0) continue;

			for(p=i*a+k*a/2;p<i*a+(k+1)*a/2;p++){
				for(q=j*a+l*a/2;q<j*a+(l+1)*a/2;q++){
					ans[p][q]=nn;
				}
			}
			nn--;
			if(nn==0) return;

				}
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	int id = n % 3,i,j;
	if(n == 3 || n == 5 || n == 2){
		printf("Impossible\n");
		return 0;
	}
	printf("Possible\n");
	//if(n == 1){
	//	printf("1\n");
//		return 0;
//	}
	if(id==0) nn=n-5;
	else if(id==2) nn=n-7;
	else nn=n;
	int a=48;
	for(i=0;i<sz;i++)
		for(j=0;j<sz;j++)
			ans[i][j]=nn;
	nn--;
	while(nn){
		split(a);
		a/=2;
	}
	if(id==0){
		sz+=24;
		for(i=48;i<72;i++)
			for(j=0;j<24;j++)
				ans[i][j]=n;
		for(i=48;i<72;i++)
			for(j=24;j<48;j++)
				ans[i][j]=n-1;
		for(i=48;i<72;i++)
			for(j=48;j<72;j++)
				ans[i][j]=n-2;
		for(i=0;i<24;i++)
			for(j=48;j<72;j++)
				ans[i][j]=n-3;
		for(i=24;i<48;i++)
			for(j=48;j<72;j++)
				ans[i][j]=n-4;
	}
	else if(id==2){
		sz+=16;
		for(i=48;i<64;i++)
			for(j=0;j<16;j++){
				ans[i][j]=n;
				ans[i][j+16]=n-1;
				ans[i][j+32]=n-2;
				ans[i][j+48]=n-3;
				ans[i-16][j+48]=n-4;
				ans[i-32][j+48]=n-5;
				ans[i-48][j+48]=n-6;
			}
	}
	printf("%d\n",sz);
	for(i=0;i<sz;i++){
		for(j=0;j<sz-1;j++){
			printf("%d ",ans[i][j]);
		}
		printf("%d\n",ans[i][j]);
	}
	return 0;
}
