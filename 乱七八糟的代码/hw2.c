#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	pid_t pid1 = fork(),pid2 = fork();
	if( pid1 == 0 ){
		execl("./jcA","jcA",NULL);
	}
	if( pid2 == 0 ){
		execl("./jcB","jcB",NULL);
	}
	return 0;
}
