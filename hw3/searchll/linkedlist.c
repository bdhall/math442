#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// Function that creates a new node with a value
struct node *newNode(int value) {
  struct node *nNode = (struct node*)malloc(sizeof(struct node));
  nNode->value = value;
  return nNode;
}

// Function that creates a new list and initiates its head, tail
// and length
struct list *newList(int value) {
  struct list *nList = (struct list*)malloc(sizeof(struct list));
  struct node *nNode = newNode(value);
  nList->head = nNode;
  nList->tail = nNode;
  nList->length = 1;
  return nList;
}

int size(struct list *l) {
  return l->length;
}

int isEmpty(struct list *l) {
  return (l->length == 0);
}

struct list *enqueue(struct list *l, int value) {
  // Create a new node with the value requested
  struct node *nNode = newNode(value);
  // Set the node BEFORE the head to our new node
  l->head->prev = nNode;
  // Set the node AFTER our NEW node to the current
  // head of the list
  nNode->next = l->head;
  // Set the head of our list to the new node
  l->head = nNode;
  // Increase the length of the list
  l->length++;
  return l;
}

int dequeue(struct list *l) {
  int result = l->tail->value;
  // Set the tail of the list to the node before
  // the current tail
  l->tail = l->tail->prev;
  // The the old tail to NULL
  l->tail->next = NULL;
  // Decrease length
  l->length--;
  return result;
}

void output(struct list *l) {
  int i = 0;
  struct node *curNode = l->head;
  printf("{ ");
  // Walk through the linked list, printing values
  while (i < l->length) {
    printf("(%d)",curNode->value);
    curNode = curNode->next;
    i++;
  }
  printf(" }");
}

int main() {
  int i = 0;
  struct list *firstList = newList(1);
  for (i; i < 10; i++) {
    enqueue(firstList,i);
  }
  output(firstList);
  dequeue(firstList);
  dequeue(firstList);
  output(firstList);
}
