#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "data_def.h"

//definições gerais da árvore;
//begin;
typedef struct node *tree;

typedef struct node {
	word_t data;
	int factor;
	tree l;
	tree r;
} node;

tree *initialise_tree();
int is_empty(tree *t);
word_t *word_tsearch(char *key, tree *t);
int freq_tsearch(char *key, tree *t);
int tree_height(tree *t);
//end;

//funções para árvore convencional;
//begin;
int insert_node(word_t input, tree *t);
//end;

//funções para árvore AVL;
int insert_node_avl(word_t input, tree *t);

//TODO: definir rotações da árvore AVL;

#endif