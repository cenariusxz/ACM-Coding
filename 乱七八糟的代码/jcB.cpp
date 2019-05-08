#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <error.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SHM_SIZE  4096
#define SHM_MODE  (SHM_R|SHM_W|IPC_CREAT)

typedef struct{
	char buf[255];
	int  tag;
}Shminfo;

int main(void){
	int shmid;
	char *shmptr;
	Shminfo *pnode;

	if((shmid = shmget(0x44,SHM_SIZE,SHM_MODE|IPC_CREAT))<0)
		perror("shmget");

	if ((shmptr = (char*)shmat(shmid,0,0))==(void*)-1)
		perror("shmat");

	pnode = (Shminfo *)shmptr;

	while(1){
		sleep(1);

		if(pnode->tag==0x12){ 
			printf("从共享内存中读出的数据是:%s\n",pnode->buf);

			memset(pnode,0x00,sizeof(Shminfo));
		}
	}

	exit(0);
}

