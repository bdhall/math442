
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main() {
  struct map *mainMap = (struct map*)malloc(sizeof(struct map));
  struct room *mainRoom = (struct room*)malloc(sizeof(struct room));
  struct room *nRoom = (struct room*)malloc(sizeof(struct room));
  struct room *sRoom = (struct room*)malloc(sizeof(struct room));
  struct room *eRoom = (struct room*)malloc(sizeof(struct room));
  struct room *wRoom = (struct room*)malloc(sizeof(struct room));
  mainRoom->N = nRoom;
  mainRoom->S = sRoom;
  mainRoom->E = eRoom;
  mainRoom->W = wRoom;
  mainRoom->description = "The main room!\n";
  mainMap->rooms[0] = *mainRoom;
  printf("%s",mainMap->rooms[0].description);
}
