//
// highandlow.c
// 
// Blake Hall
// Math 442
// Jim Fix
// Fall 2013
//
// Picks a random number, then asks the user to guess that number.
// If guess is too high, it asks for a lower number; if too low,
// it asks for a higher number. Continues until correct number is
// guessed.
//
//

#include <stdio.h>
#include <time.h>

// Generate a random number.
int generateNum() {
  srand(time(NULL));
  int number = rand() % 100 + 1;
  return number;
}

// Plays the game!
int main() {

  // Initialize important values.
  int guess;
  int gameNum = generateNum();
  
  // Get guess from user.
  printf("What is your guess?: ");
  scanf("%d", &guess);

  // Simple if and while loops that ask the user for guesses until
  // he is correct.
  if (guess == gameNum) {
    printf("You're right!\n");
    return;
  } else {
    while (guess != gameNum) {
      if (guess <= gameNum) {
	printf("Higher! Try again!\n");
      } else {
	printf("Lower! Try again!\n");
      }
      printf("What is your next guess? ");
      scanf("%d",&guess);
    }
    printf("Yup! You got it!\n");
    return;
  }
}
  
