#include <stdio.h>
#define MAX_PARTITIONS 10

void firstFit(int partitions[], int m, int processes[], int n) {
int allocation[n];
for (int i = 0; i < n; i++)
allocation[i] = -1;

for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
if (partitions[j] >= processes[i]) {
allocation[i] = j;
partitions[j] -= processes[i];
break;
}
}
}

printf("Process No.\tProcess Size\tBlock No.\n");
for (int i = 0; i < n; i++) {
printf("%d\t\t%d\t\t", i + 1, processes[i]);
if (allocation[i] != -1)
printf("%d\n", allocation[i] + 1);
else
printf("Not Allocated\n");
}
}

void bestFit(int partitions[], int m, int processes[], int n) {
int allocation[n];
for (int i = 0; i < n; i++)
allocation[i] = -1;

for (int i = 0; i < n; i++) {
int bestIdx = -1;
for (int j = 0; j < m; j++) {
if (partitions[j] >= processes[i]) {
if (bestIdx == -1 || partitions[j] < partitions[bestIdx]) {
bestIdx = j;
}
}
}
if (bestIdx != -1) {
allocation[i] = bestIdx;
partitions[bestIdx] -= processes[i];
}
}

printf("Process No.\tProcess Size\tBlock No.\n");
for (int i = 0; i < n; i++) {
printf("%d\t\t%d\t\t", i + 1, processes[i]);
if (allocation[i] != -1)
printf("%d\n", allocation[i] + 1);
else
printf("Not Allocated\n");
}
}

int main() {
int partitions[MAX_PARTITIONS], partitions2[MAX_PARTITIONS], processes[MAX_PARTITIONS];
int m, n;

printf("Enter the number of partitions: ");
scanf("%d", &m);

printf("Enter the partition sizes: ");
for (int i = 0; i < m; i++) {
scanf("%d", &partitions[i]);
}

for (int i = 0; i < m; i++) {
partitions2[i] = partitions[i];
}

printf("Enter the number of processes: ");
scanf("%d", &n);
printf("Enter the process sizes: ");
for (int i = 0; i < n; i++) {
scanf("%d", &processes[i]);
}

printf("\nFirst Fit Allocation:\n");
firstFit(partitions, m, processes, n);

printf("\nBest Fit Allocation:\n");
bestFit(partitions2, m, processes, n);

return 0;
}
