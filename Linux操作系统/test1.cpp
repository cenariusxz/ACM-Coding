#include <sys/types.h>
#include <stdlib.h>

#include <unistd.h>

#include <stdio.h>

#include <sys/wait.h>

//pid_t wait(int *stat_loc);

void perror(const char *s);

#include <errno.h>

int errno;

int global;



main() {

	int local,i;

	pid_t child;



	if ((child=fork()) == -1)

	{	// 创建失败

		printf("Fork Error.\n");

	}

	if (child == 0)

	{// 子进程

		printf("Now it is in child process.\n");

		if (execl("/home/xyong/work/ttt","ttt",NULL) == -1)

		{	// 加载程序失败

			perror("Error in child process");

		}

		global=local + 2;

		exit(0);

	}



	// 父进程

	printf("Now it is in parent process.\n");

	for (i=0; i<10; i++)

	{

		sleep(2);

		printf("Parent:%d\n",i);

		if (i==2)

		{

			if ((child=fork()) == -1)

			{	// 创建失败

				printf("Fork Error.\n");

			}

			if (child == 0)

			{// 子进程

				printf("Now it is in child process.\n");

				if (execl("/home/xyong/work/ttt","ttt",NULL) == -1)

				{	// 加载程序失败

					perror("Error in child process");

				}

				global=local + 2;

				exit(0);

			}

		}

		if (i==3)

		{

			pid_t temp;

			temp=wait(NULL);

			printf("Child process ID: %d\n", temp);

		}

	}

	global=local + 1;

	exit(0);

}


