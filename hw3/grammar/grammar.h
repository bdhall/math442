#ifndef _GRAMMAR_H
#define _GRAMMAR_H



typedef struct {
  char symbol;
  char *LHS;
  char *RHS;
} production;

typedef struct {
  int amount;
  production *elements;
  char start;
} grammar;

production *newProd(char symb);
grammar *newGram(char start, int amount);


#endif
