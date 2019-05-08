#include<stdio.h>
#include<string.h>

int t[6]={12,6,4,3,2,1};
bool f[13][13];

int main(){
	int n;
	scanf("%d",&n);
	for(int q=1;q<=n;q++){
		getchar();
		memset(f,0,sizeof(f));
		int i,j;
		for(i=1;i<=12;i++){
			char a=getchar();
			if(a=='O'){
				for(j=0;j<6;j++){
					f[t[j]][i%t[j]]=1;
				}
			}
		}/*
		for(i=1;i<=12;i++){
			for(j=1;j<=12;j++){
				printf("%3d",f[i][j]);
			}
			printf("\n");
		}*/
		bool fi[6];
		int ans=0;
		for(j=0;j<6;j++){
			fi[j]=1;
			for(i=0;i<t[j];i++){
				if(!f[t[j]][i]){
					fi[j]=0;
					ans++;
					break;
				}
			}
		}
		printf("%d",ans);
		for(j=0;j<6;j++){
			if(!fi[j])printf(" %dx%d",12/t[j],t[j]);
		}
		printf("\n");
	}
	return 0;
}
