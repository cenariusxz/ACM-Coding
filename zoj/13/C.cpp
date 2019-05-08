#include<stdio.h>
#include<string.h>

int pos[10],lab[10];
int num[10];

void s1(){
	int d;
	scanf("%d%d%d%d%d",&d,&num[1],&num[2],&num[3],&num[4]);
	if(d==1||d==2){
		pos[1]=2;
		lab[1]=num[2];
	}
	if(d==3){
		pos[1]=3;
		lab[1]=num[3];
	}
	if(d==4){
		pos[1]=4;
		lab[1]=num[4];
	}
	printf("%d %d\n",pos[1],lab[1]);
}

void s2(){
	int d;
	scanf("%d%d%d%d%d",&d,&num[1],&num[2],&num[3],&num[4]);
	if(d==1){
		for(int i=1;i<=4;++i){
			if(num[i]==4){
				pos[2]=i;
				lab[2]=num[i];
			}
		}
	}
	if(d==2||d==4){
		pos[2]=pos[1];
		lab[2]=num[pos[1]];
	}
	if(d==3){
		pos[2]=1;
		lab[2]=num[1];
	}
	printf("%d %d\n",pos[2],lab[2]);
}

void s3(){
	int d;
	scanf("%d%d%d%d%d",&d,&num[1],&num[2],&num[3],&num[4]);
	if(d==1){
		for(int i=1;i<=4;++i){
			if(num[i]==lab[2]){
				pos[3]=i;
				lab[3]=num[i];
			}
		}
	}
	if(d==2){
		for(int i=1;i<=4;++i){
			if(num[i]==lab[1]){
				pos[3]=i;
				lab[3]=num[i];
			}
		}
	}
	if(d==3){
		pos[3]=3;
		lab[3]=num[3];
	}
	if(d==4){
		for(int i=1;i<=4;++i){
			if(num[i]==4){
				pos[3]=i;
				lab[3]=num[i];
			}
		}
	}
	printf("%d %d\n",pos[3],lab[3]);
}

void s4(){
	int d;
	scanf("%d%d%d%d%d",&d,&num[1],&num[2],&num[3],&num[4]);
	if(d==1){
		pos[4]=pos[1];
		lab[4]=num[pos[1]];
	}
	if(d==2){
		pos[4]=1;
		lab[4]=num[1];
	}
	if(d==3||d==4){
		pos[4]=pos[2];
		lab[4]=num[pos[2]];
	}
	printf("%d %d\n",pos[4],lab[4]);
}

void s5(){
	int d;
	scanf("%d%d%d%d%d",&d,&num[1],&num[2],&num[3],&num[4]);
	if(d==1||d==2){
		for(int i=1;i<=4;++i){
			if(num[i]==lab[d]){
				pos[5]=i;
				lab[5]=num[i];
			}
		}
	}
	if(d==3){
		for(int i=1;i<=4;++i){
			if(num[i]==lab[4]){
				pos[5]=i;
				lab[5]=num[i];
			}
		}
	}
	if(d==4){
		for(int i=1;i<=4;++i){
			if(num[i]==lab[3]){
				pos[5]=i;
				lab[5]=num[i];
			}
		}
	}
	printf("%d %d\n",pos[5],lab[5]);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		s1();
		s2();
		s3();
		s4();
		s5();
	}
}
