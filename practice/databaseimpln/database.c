
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

struct database *newDB() {
  struct database *newDB = (struct database*)malloc(sizeof(struct database));
  newDB->size = 10;
  return newDB;
}

int main() {
  struct database *myDB = newDB();
  int i = 0;
  for (i; i < myDB->size; i++) {
    printf("Please enter id then name then email: \n");
    scanf("%d",&(myDB->elements[i].id));
    scanf("%c",&(myDB->elements[i].name));
    scanf("%c",&(myDB->elements[i].email));
  }

}
