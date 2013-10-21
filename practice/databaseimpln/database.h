#ifndef DATABASE_H
#define DATABASE_H

struct item {
  int id;
  char name;
  char email;
};

struct database {
  int size;
  struct item elements[10];
};

struct database *newDB();

#endif
