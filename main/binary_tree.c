#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"

//definições gerais da árvore;
//begin;

tree *initialise_tree() {
	tree *t = (tree*) malloc(sizeof(node));
	*t = NULL;
}

int is_empty(tree *t) {
	return (*t == NULL);
}

word_t *word_tsearch(char *key, tree *t) {
	if(is_empty(t)) {
		return NULL;
	}
	if(strcmp(key, (*t)->data.word) < 0) {
		return word_tsearch(key, &(*t)->l);
	}
	if(strcmp(key, (*t)->data.word) > 0) {
		return word_tsearch(key, &(*t)->r);
	}
	else {
		return (&(*t)->data);
	};
}

int freq_tsearch(char *key, tree *t) {
	if(is_empty(t))
		return 0;
	
	if(strcmp(key, (*t)->data.word) < 0)
		return freq_tsearch(key, &(*t)->l);
	
	if(strcmp(key, (*t)->data.word) > 0)
		return freq_tsearch(key, &(*t)->r);
	
	else
		return ((*t)->data.freq);
}

int tree_height(tree *t) {
	int lh, rh;
	
	if(is_empty(t))
		return 0;
	
	lh = tree_height(&((*t)->l));
	rh = tree_height(&((*t)->r));
	
	if(lh > rh) return lh + 1;
	else return rh + 1;
}

//end;

//funções para árvore convencional;
//begin;

int insert_node(word_t input, tree *t) {
	if(is_empty(t)) {
		*t = (tree) malloc(sizeof(node));
		(*t)->data = input;
		(*t)->l = NULL;
		(*t)->r = NULL;
		return 0;
	}
	if(strcmp(input.word, (*t)->data.word) < 0) {
		insert_node(input, &(*t)->l);
		return 0;
	}
	if(strcmp(input.word, (*t)->data.word) > 0) {
		insert_node(input, &(*t)->r);
		return 0;
	}
	else return 1;
}

//end;

//funções para árvore AVL;
//begin;

int insert_node_avl(word_t input, tree *t);

//TODO: definir rotações da árvore AVL;

//end;