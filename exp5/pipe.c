#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
int p1[2], p2[2];
int status;
char buff[100], str[10];
int r = pipe(p1);
int s = pipe(p2);
if(r==0) printf("\n Pipe 1 is Created ...%d\n", r);
if (s==0) printf("\n Pipe 2 is created .. %d\n", s);
pid_t pid = fork();
if(pid>0) {
close(p1[0]);
close(p2[1]);
printf("\n Write data in Parent:");
scanf("%s",str);
write(p1[1],str,10);
read(p2[0],buff,100);
printf("\n data read in Parent:%s\n",buff);
} else {
close(p2[0]);
close(p1[1]);
read(p1[0],buff,100);
printf("\n Data read in Child:%s\n", buff);
printf("\n Write data in Child:");
scanf("%s",str);
write(p2[1],str,10);
}
return 0;
}
