#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<time.h>

char s[3][100] = {"石头","剪刀","布"};


int main(){
	pid_t pid;
	int fd[2][2];
	int result = -1, ans[2];
	int *write_fd = &fd[0][1];
	int *read_fd = &fd[0][0];
	int *write_fd1 = &fd[1][1];
	int *read_fd1 = &fd[1][0];

	srand(time(NULL));

	for(int i = 1 ; i <= 10 ; ++i ){
		int p0 = rand(), p1 = rand();
		result = pipe(fd[0]);
		if(-1 == result){
			printf("建立管道失败！\n");
			return -1;
		}
		pid = fork();
		if(-1 == pid){
			printf("进程创建失败!\n");
			return -1;
		}
		else if(0 == pid){
			close(*read_fd);
			srand(p0);
			int num = rand() % 3;
			result = write(*write_fd,&num,sizeof(num));
			return 0;
		}
		else{
			close(*write_fd);
			read(*read_fd,&ans[0],sizeof(ans[0]));
		}

		result = pipe(fd[1]);
		if(-1 == result){
			printf("建立管道失败！\n");
			return -1;
		}
		pid = fork();
		if(-1 == pid){
			printf("进程创建失败!\n");
			return -1;
		}
		else if(0 == pid){
			close(*read_fd1);
			srand(p1);
			int num = rand() % 3;
			result = write(*write_fd1,&num,sizeof(num));
			return 0;
		}
		else{
			close(*write_fd1);
			read(*read_fd1,&ans[1],sizeof(ans[1]));
		}

		printf("子进程1：%s\n",s[ans[0]]);
		printf("子进程2：%s\n",s[ans[1]]);
		if(ans[0] == ans[1])printf("打平！\n");
		else if((ans[0] + 1) % 3 == ans[1])printf("子进程1胜！\n");
		else printf("子进程2胜！\n");

		printf("\n\n");
	}
	return 0;
}
