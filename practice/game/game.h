#ifndef GAME_H
#define GAME_H

struct room {
  char *name;
  char *description;  
  struct room *N;
  struct room *S;
  struct room *E;
  struct room *W;

};

struct map {
  struct room rooms[10];
};

struct player {
  struct room *curRoom;
};

struct room *init();


#endif
