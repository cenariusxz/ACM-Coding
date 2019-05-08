#include<stdio.h>
#include<string.h>
int main(){
	int N;
	while(scanf("%d",&N)!=EOF){
		for(int i=1;i<=N;i++){
			int K,j;
			int C[100],S[100];
			char q[100];
			for(j=1;j<=K;j++){
				gets(q);
				scanf("%d%d",&C[j],&S[j]);				
			}
			double GKP=0,s;
			for (j=1;j<=K;j++){
				GKP+=S[j]*C[j];
				s+=C[j];
			}
			GKP=GKP/s;
			if(GKP>=60)printf("%.2lf\n",GKP);
			else printf("Sorry!");
			if(i!=N){
				printf("\n");
			}
		}
	} 
	return 0;
}

