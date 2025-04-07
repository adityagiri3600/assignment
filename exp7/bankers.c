#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void bankersAlgorithm(int N, int M, int * safeSeq, int * unsafeSeq) {

int alloc[N][M], max[N][M], available[M];
bool finish[N];

for (int i = 0; i < N; i++) {
finish[i] = false;
}

printf("\nEnter a %d X %d Maximum demand matrix of each process:\n", N, M);
for (int i = 0; i < N; i++) {
for (int j = 0; j < M; j++) {
scanf("%d", &max[i][j]);
}
}

printf("\nEnter a %d X %d Allocation matrix of each process:\n", N, M);
for (int i = 0; i < N; i++) {
for (int j = 0; j < M; j++) {
scanf("%d", &alloc[i][j]);
}
}

printf("\nEnter the %d types of available resources:\n", M);
for (int i = 0; i < M; i++) {
scanf("%d", &available[i]);
}

int count = 1, safeSeqIdx = 0, executedProcessCount = 0;
bool deadlock = false;
while(count <= N) {
bool isProcessExecuted = false;
printf("\n# Iteration: %d\n\n", count);
for (int i = 0; i < N; i++) {
printf("\t-> Process: %d\n", i);
printf("\tFinish: %d\n\n", finish[i]);
if (finish[i]) continue;
bool isResourceAvailable = true;
for (int j = 0; j < M; j++) {
int need = max[i][j] - alloc[i][j];
if (need > available[j]) {
isResourceAvailable = false;
printf("\tneed(%d)(%d) > available(%d) i.e. %d > %d\n",
i, j, j, need, available[j]);
printf("\tSince, available resources are not enough,
thus process p%d will wait.\n\n", i);
break;
} else {
printf("\tneed(%d)(%d) <= available(%d) i.e. %d <=
%d\n", i, j, j, need, available[j]);
}
}
if (isResourceAvailable) {
printf("\tSince, resources are available, thus process p%d will
execute.\n\n", i);

executedProcessCount++;
finish[i] = true;
safeSeq[safeSeqIdx++] = i;
printf("\tNew Available resources are: [ ");
for (int j = 0; j < M; j++) {
available[j] += alloc[i][j];
printf("%d ", available[j]);
}
printf("]\n\n");
isProcessExecuted = true;
if (executedProcessCount == N) break;
}
}
if (executedProcessCount == N) break;
if (isProcessExecuted) count++;
else {
deadlock = true;
break;
}
}

if (deadlock) {
printf("Processes during execution goes into deadlock i.e. unsafe state with
unsafeSequence = [ ");
int unsafeSeqIdx = 0;
for (int j = 0; j < N; j++) {
if (!finish[j]) {
printf("p%d ", j);
unsafeSeq[unsafeSeqIdx++] = j;
}
}
printf("]\n");
} else {
printf("All processes executes without any deadlock i.e. safe state with
safeSequence = [ ");
for (int j = 0; j < N; j++) {
printf("p%d ", safeSeq[j]);
}
printf("]\n");
}

int newProcessNeed[M];
printf("\nEnter the new process's resource requirement:\n");
for (int i = 0; i < M; i++) {
scanf("%d", &newProcessNeed[i]);
}

bool isResourceAvailable = true;
for (int j = 0; j < M; j++) {
if (newProcessNeed[j] > available[j]) {
isResourceAvailable = false;
printf("\tnewProcessNeed(%d) > available(%d) i.e. %d > %d\n", j, j,
newProcessNeed[j], available[j]);
printf("\tSince, available resources are not enough, thus new process
will wait.\n\n");
break;
} else {
printf("\tnewProcessNeed(%d) <= available(%d) i.e. %d <= %d\n", j, j,
newProcessNeed[j], available[j]);
}
}

if (isResourceAvailable) {
printf("The new process's resource requirement can be granted immediately.\n");
} else {
printf("The new process's resource requirement cannot be granted immediately.\n");
}
}

int main() {

int N, M;
printf("\nEnter number of processes: ");
scanf("%d", &N);
printf("\nEnter number of types of resources: ");
scanf("%d", &M);

int safeSeq[N], unsafeSeq[N];

bankersAlgorithm(N, M, safeSeq, unsafeSeq);

return 0;

}
