#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int *newQueue(int capacity) {
  int *Q = (int *)malloc((capacity+1)*sizeof(int));
  Q[-1] = 0;
  return &Q[0];
}

int isQEmpty(int *Q) {
  return (sizeQ(Q) == 0);
}

int sizeQ(int *Q) {
  return Q[-1];
}

void decreaseQ(int *Q) {
  Q[-1]--;
}

void increaseQ(int *Q) {
  Q[-1]++;
}


void enqueue(int x, int *Q) {
  int i = sizeQ(Q);
  increaseQ(Q);
  // Shift all elements of the queue 1 to the right
  while (0 <= i) {
    Q[i+1] = Q[i];
    i--;
  }
  Q[0] = x;  
}

int dequeue(int *Q) {
  int j = 0;
  int d = Q[sizeQ(Q)];
  decreaseQ(Q);
  return d;
}

void outputQ(int *Q) {
  int k;
  if (isQEmpty(Q)) {
    printf("[ ]");
  } else {
    printf("[");
    for (k=0; k<sizeQ(Q); k++) {
      printf("%d ",Q[k]);
    }
    printf("]");
  }
}

