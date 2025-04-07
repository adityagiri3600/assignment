#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

int main() {
int i;
void *sharedMem;
char buff[100];
int shmid;
char str[100]= {0};
int len, num, slen, temp;
shmid = shmget((key_t)12347,1024,0666); //ftok()
sharedMem = shmat(shmid, NULL,0);
printf("\n Process attached at %p: ",sharedMem);
printf("\n data read: %s",(char *)sharedMem);
strcpy(str, sharedMem);
slen = strlen(str);
for (i=0; i<slen/2; i++) {
temp = str[i];
str[i] = str[slen - i - 1];
str[slen - i - 1] = temp;
}
printf("\n Reverse of data is : %s\n", str);
shmdt(sharedMem);
shmctl(shmid, IPC_RMID, NULL);
return 0;
}
