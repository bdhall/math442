
#ifndef _QUEUE_H
#define _QUEUE_H

int *newQueue(int capacity);
int isQEmpty(int *Q);
int sizeQ(int *Q);
void decreaseQ(int *Q);
void increaseQ(int *Q);
void enqueue(int x, int *Q);
int dequeue(int *Q);
void outputQ(int *Q);

#endif
