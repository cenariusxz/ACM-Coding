#include<sys/types.h>  
#include<sys/ipc.h>  
#include<sys/shm.h>  
#include<stdio.h>  
#include<error.h> 
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


#define SHM_SIZE    4096  
#define SHM_MODE    (SHM_R | SHM_W)


struct Shminfo{
	char buf[255];
	int  tag;
};

int main(void){  
	int shmid;  
	char *shmptr;  
	Shminfo *pnode;

	if ( (shmid = shmget(0x44, SHM_SIZE, SHM_MODE | IPC_CREAT)) < 0)  
		perror("shmget");  

	if ( (shmptr = (char*)shmat(shmid, 0, 0)) == (void*) -1)  
		perror("shmat");  

	pnode = (Shminfo *)shmptr;

	memset(pnode,0,sizeof(Shminfo));
	while(1){
		sleep(1);
		if(pnode->tag!=0x12){
			printf("请输入要写进共享内存中的数据:\n");
			scanf("%s",pnode->buf);
			pnode->tag = 0x12;
		}
	}

	exit(0);  
}  

