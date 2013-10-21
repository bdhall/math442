
// Reads a file called "roomdefs.i" that is laid out as such:
// 
// NUMBER_OF_ROOMS
// ID1
// NAMEOFROOM1#
// DESCRIPTIONOFROOM1#
// ID2
// NAMEOFROOM2#
// DESCRIPTIONOFROOM2#
// ...
//
// For example:
//
// 2
// 0
// Room 1#
// This is room 1.#
// 1
// Room 2#
// This is room 2.#
//
//

#include <stdio.h>
#include <stdlib.h>

int main() {
  struct room{
    int id;
    char roomName[20];
    char roomDesc[200];
  };


  FILE *roomDefs;
  int amtRooms;
  int i = 0;
  int j = 0;
  int endSec = 0;

  // Open roomdefs.i for reading only
  roomDefs = fopen("roomdefs.i","r");
  // Put the amount of rooms into the amtRooms variable
  fscanf(roomDefs,"%d",&amtRooms);
  // Create an array of rooms with a length amtRooms
  struct room rooms[amtRooms];
  // For every room in rooms...
  for (j; j< amtRooms; j++) {
    // Set rooms[j].id
    fscanf(roomDefs,"%d",&(rooms[j].id));
    // Read the name from the file. If we hit a #, stop,
    // then set the last character from # to \0
    while (endSec != 1) {
      rooms[j].roomName[i] = fgetc(roomDefs);
      if (rooms[j].roomName[i] == '#') {
	rooms[j].roomName[i] = '\0';
	endSec = 1;
      } else {
	endSec = 0;
      }
      i++;
    } 
    i = 0;
    endSec = 0;
    // Do the same as above for description.
    while (endSec != 1) {
      rooms[j].roomDesc[i] = fgetc(roomDefs);
      if (rooms[j].roomDesc[i] == '#') {
	rooms[j].roomDesc[i] = '\0';
	endSec = 1;
      } else {
	endSec = 0;
      }
      i++;
    } 
    i=0;
    endSec = 0;
  }
  j = 0;

  // Print out.
  for(j; j<amtRooms; j++) {
    printf("%d",rooms[j].id);
    printf("%s",rooms[j].roomName);
    printf("%s\n",rooms[j].roomDesc);
  }
  fclose(roomDefs);
}
