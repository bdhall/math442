#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H


typedef struct {
  int value;
  int nextLoc;
} node;

typedef struct {
  node head;
  node tail;
  int size;
} linkedlist;

typedef struct {
  int headLoc;
  int size;
} queue;


node *newNode(int value);
linkedlist *newList(int value);
queue *newQueue(int size);
int isEmpty(linkedlist *list);
int size(linkedlist *list);
void enqueue(int x, linkedlist *list);
int dequeue(linkedlist *list);
void output(linkedlist *list);


#endif
  


