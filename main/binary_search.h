#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "data_def.h"

//implementação de quicksort para ordenação de palavras;
//begin;

void swap(word_t *x, word_t *y);
int wordcmp(word_t *x, word_t *y);
int partition(word_t *arr, int p, int r);
void word_qsort(word_t *arr, int p, int r);

//end;

word_t *word_bsearch(word_t *arr, char *key, int p, int r);

#endif