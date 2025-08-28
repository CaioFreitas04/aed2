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

//defs e funções adicionadas para funcionar com parse_file;
#define BASE_ARRAY_SIZE 128

typedef struct {
	word_t *arr;
	int size;
	int size_max;
} array;

array *initialise_array();
int insert_array(word_t input, void *data_structure);

#endif