#include <stdlib.h>
#include <string.h>
#include "binary_search.h"

//implementação de quicksort para ordenação de palavras;
//begin;

void swap(word_t *x, word_t *y) {
	word_t temp = *x;
	*x = *y;
	*y = temp;
}

int wordcmp(word_t *x, word_t *y) {
	return strcmp(x->word, y->word);
}

int partition(word_t *arr, int p, int r) {	//utilizar r-1 no programa;
	word_t pivot = arr[r];
	int i = p-1;
	for(int j = p; j < r; j++) {
		if(wordcmp(&arr[j], &pivot) < 0) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[r]);
	return i+1;
}

void word_qsort(word_t *arr, int p, int r) {
	if(p < r) {
		int q = partition(arr, p, r);
		word_qsort(arr, p, q-1);
		word_qsort(arr, q+1, r);
	}
}

//end;

word_t *word_bsearch(word_t *arr, char *key, int p, int r) {
	if(r >= p) {
		int q = (p + r) / 2;
		
		int cmp_res = strcmp(key, arr[q].word);
		
		if(cmp_res == 0)
			return &arr[q];
		
		if(cmp_res > 0)
			return word_bsearch(arr, key, q+1, r);
		else
			return word_bsearch(arr, key, p, q-1);
	}
	return NULL;
}