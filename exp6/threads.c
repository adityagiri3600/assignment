#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread1(void *arg)
{
for (int i = 1; i <= *(int *)arg; i++)
{
printf("this is thread 1\n");
sleep(1);
}
}

void *thread2(void *arg)
{
for (int i = 1; i <= *(int *)arg; i++)
{
printf("this is thread 2\n");
sleep(1);
}

}

int main()
{
pthread_t t1, t2;
int range = 5;
pthread_create(&t1, NULL, thread1, &range);
pthread_create(&t2, NULL, thread2, &range);
pthread_join(t1, NULL);
pthread_join(t2, NULL);
return 0;
}
