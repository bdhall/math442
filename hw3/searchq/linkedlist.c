#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

node *newNode(int value) {
  node *n;
  n->value = value;
  n->nextLoc = 0;
}

linkedlist *newList(int value) {
  linkedlist *list;
  node *h = newNode(value);
  node *t = newNode(NULL);
  h->nextLoc = &t;
  list->head = *h;
  list->tail = *t;
  list->size = 0;
}

int isEmpty(linkedlist *list) {
  return (list->size == 0);
}

int size(linkedlist *list) {
  return (list->size);
}

void enqueue(int x, linkedlist *list) {
  n = newNode(x,list);
  n->nextLoc = &(list->head);
  list->head = *n;
  list->size++;
}

int dequeue(linkedlist *list) {
  
}

void output(linkedlist *list) {
  return;
}

int main() {
  printf("ur mom");
}


