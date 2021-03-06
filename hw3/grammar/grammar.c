

#include <stdio.h>
#include <stdlib.h>
#include "grammar.h"


production *newProd(char symb) {
  production *prod = malloc(sizeof(production));
  prod->symbol = symb;
  prod->LHS = "a";
  prod->RHS = "a";
  return prod;
}

grammar *newGram(char start, int amount) {
  grammar *gram = malloc(sizeof(grammar));
  production elements[amount];
  int i = 0;
  gram->amount = amount;
  gram->start = start;
  for (i; i<amount ; i++) {
    gram->elements[i] = elements[i];
    gram->elements[i].symbol = "S";
    gram->elements[i].LHS = "a";
    gram->elements[i].RHS = "b";
    i++;
  }
  return gram;
}

int main() {
  production *prod1;
  production *prod2;
  production *prod3;
  grammar *gram;
  gram = newGram('S',3);
  printf("whee!");
}
