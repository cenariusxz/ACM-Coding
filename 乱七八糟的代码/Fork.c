#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	pid_t pid = fork();
	if( pid == 0 ){
		execl("./helloworld","helloworld",NULL);
	}
	return 0;
}
