#include < stdio.h>
#include <string.h>
#include < sys/shm.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
int i, nochar;
void *sharedMem;
int shmid;
shmid = shmget((key_t)12347,1024,0666|IPC_CREAT|IPC_EXCL);
sharedMem = shmat(shmid,NULL,0);
printf("\n Enter data : \n");
nochar=read(0,sharedMem, 100);
printf("\n %d Characters entered: \n", nochar);
shmdt(sharedMem);
return 0 ;
}
