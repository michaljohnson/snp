
#ifndef STRINGS_H
#define STRINGS_H
#include <string.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

void createWordArray(char words[MAX_WORDS][MAX_WORD_LENGTH]);
void lowerToUpper(char words[MAX_WORDS][MAX_WORD_LENGTH]);
void quickSort(char words[][MAX_WORD_LENGTH], int first, int last);
void swap(char *a, char *b);
void printWords(char words[MAX_WORDS][MAX_WORD_LENGTH]);
int main(void);

#endif

