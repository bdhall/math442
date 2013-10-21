#include "sequence.h"
#include <stdlib.h>

char *new(int len) {
  int i;
  char *str;
  str = (char *)malloc((len+1)*sizeof(char));
  for (i = 0; i <= len; i++) {
    str[i] = '\000';
  }
  return str;
}

char *copy(char *str) {
  int i;
  int len = length(str);
  char *cpy = new(len);
  for (i=0; i<len; i++) {
    cpy[i] = str[i];
  }
  cpy[i] = '\000';
  return cpy;
}

int length(char *str) {
  int i=0;
  while (str[i] != '\000') {
    i++;
  }
  return i;
}

// Append two strings together
char *append(char *src1, char *src2) {
  // Determine the sum of the lengths of the input strings
  int newlength = length(src1)+length(src2);
  // Create a new empty string by reserving enough space for
  // the length of the sum
  char *newstr = (char *)malloc((newlength+1)*sizeof(char));
  int i=0;
  int j=0;
  // Run through the first string, setting the new string's characters
  // one by one
  while (i < length(src1)) {
    newstr[i] = src1[i];
    i++;
  }
  // Run through the second string, doing the same thing
  while (j < length(src2)) {
    newstr[i] = src2[j];
    i++;
    j++;
  }
  // Return our string
  return newstr;
}

char *substring(char *src, int start, int end) {
  int i;
  int len = end-start+1;
  char *dst = new(len);

  for (i=start; i<=end; i++) {
    dst[i-start] = src[i];    
  }
  dst[len] = '\000';

  return dst;
}




