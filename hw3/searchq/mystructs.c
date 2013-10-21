#include <stdio.h>
#include <stdlib.h>
#include "mystructs.h"



queue *newQueue(int capacity) {
  queue *Q = (queue *)malloc(sizeof(queue));
  Q->size = 0;
  Q->capacity = capacity;
  Q->elements = (int *)malloc(capacity*sizeof(int));
  return Q;
}

int isEmpty(queue *Q) {
  return (Q->size == 0);
}

void enqueue(int x, queue *Q) {
  int i = Q->size;
  Q->size++;
  while (0 <= i) {
    Q->elements[i+1] = Q->elements[i];
    i--;
  }
  Q->elements[0] = x;
}

int dequeue(queue *Q) {
  int j = 0;
  int d = Q->elements[Q->size];
  Q->size--;
  return d;
}

void output(queue *Q) {
  int k;
  if (isEmpty(Q)) {
    printf("[ ]");
  } else {
    printf("[");
    for (k=0; k<Q->size; k++) {
      printf("%d ",Q->elements[k]);
    }
    printf("]");
  }
}


