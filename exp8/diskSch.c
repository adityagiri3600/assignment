#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_REQUESTS 100

void FCFS(int requests[], int n, int head) {
int seek_time = 0;
printf("FCFS Order: %d", head);
for (int i = 0; i < n; i++) {
printf(" -> %d", requests[i]);
seek_time += abs(requests[i] - head);

head = requests[i];
}
printf("\nTotal Seek Time: %d\n", seek_time);
}

void SSTF(int requests[], int n, int head) {
int seek_time = 0, completed[MAX_REQUESTS] = {0};
printf("SSTF Order: %d", head);
for (int i = 0; i < n; i++) {
int min_distance = 1e9, min_index = -1;
for (int j = 0; j < n; j++) {
if (!completed[j] && abs(requests[j] - head) < min_distance) {
min_distance = abs(requests[j] - head);
min_index = j;
}
}
completed[min_index] = 1;
printf(" -> %d", requests[min_index]);
seek_time += min_distance;
head = requests[min_index];
}
printf("\nTotal Seek Time: %d\n", seek_time);
}

void SCAN(int requests[], int n, int head, int disk_size, int direction) {
int seek_time = 0;
printf("SCAN Order: %d", head);
for (int i = 0; i < n - 1; i++) {
for (int j = i + 1; j < n; j++) {
if (requests[i] > requests[j]) {
int temp = requests[i];
requests[i] = requests[j];
requests[j] = temp;
}
}
}
if (direction == 0) {
for (int i = n - 1; i >= 0; i--) {
if (requests[i] <= head) {

printf(" -> %d", requests[i]);
seek_time += abs(head - requests[i]);
head = requests[i];
}
}
printf(" -> 0");
seek_time += head;
} else {
for (int i = 0; i < n; i++) {
if (requests[i] >= head) {
printf(" -> %d", requests[i]);
seek_time += abs(head - requests[i]);
head = requests[i];
}
}
printf(" -> %d", disk_size - 1);
seek_time += abs(head - (disk_size - 1));
}
printf("\nTotal Seek Time: %d\n", seek_time);
}

void C_SCAN(int requests[], int n, int head, int disk_size) {
int seek_time = 0;
printf("C-SCAN Order: %d", head);
for (int i = 0; i < n; i++) {
printf(" -> %d", requests[i]);
seek_time += abs(requests[i] - head);
head = requests[i];
}
printf("\nTotal Seek Time: %d\n", seek_time);
}

void LOOK(int requests[], int n, int head) {
int seek_time = 0;
printf("LOOK Order: %d", head);
for (int i = 0; i < n; i++) {
printf(" -> %d", requests[i]);
seek_time += abs(requests[i] - head);
head = requests[i];

}
printf("\nTotal Seek Time: %d\n", seek_time);
}

void C_LOOK(int requests[], int n, int head) {
int seek_time = 0;
printf("C-LOOK Order: %d", head);
for (int i = 0; i < n; i++) {
printf(" -> %d", requests[i]);
seek_time += abs(requests[i] - head);
head = requests[i];
}
printf("\nTotal Seek Time: %d\n", seek_time);
}

int main() {
int n, head, disk_size, direction;
int requests[MAX_REQUESTS];

printf("Enter number of requests: ");
scanf("%d", &n);
printf("Enter request queue: ");
for (int i = 0; i < n; i++) {
scanf("%d", &requests[i]);
}
printf("Enter initial head position: ");
scanf("%d", &head);
printf("Enter disk size: ");
scanf("%d", &disk_size);
printf("Enter direction (0 for left, 1 for right): ");
scanf("%d", &direction);

printf("\n--- FCFS ---\n");
FCFS(requests, n, head);

printf("\n--- SSTF ---\n");
SSTF(requests, n, head);

printf("\n--- SCAN ---\n");

SCAN(requests, n, head, disk_size, direction);

printf("\n--- C-SCAN ---\n");
C_SCAN(requests, n, head, disk_size);

printf("\n--- LOOK ---\n");
LOOK(requests, n, head);

printf("\n--- C-LOOK ---\n");
C_LOOK(requests, n, head);

return 0;
}
