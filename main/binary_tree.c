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

#define LEFT_LEFT 0
#define RIGHT_RIGHT 1
#define LEFT_RIGHT 2
#define RIGHT_LEFT 3

//rotações para a esquerda e direita como base para as outras;
void rotate_left(tree *t) {
    tree r = (*t)->r;
    (*t)->r = r->l;
    r->l = *t;
    *t = r;
}

void rotate_right(tree *t) {
    tree l = (*t)->l;
    (*t)->l = l->r;
    l->r = *t;
    *t = l;
}

//função de rotação geral porque somos gente por aqui;
void rotate(int rot, tree *t) {
    switch(rot) {
        case LEFT_LEFT:
            rotate_right(t);
            break;
        case RIGHT_RIGHT:
            rotate_left(t);
            break;
        case LEFT_RIGHT:
            rotate_left(&(*t)->l);
            rotate_right(t);
            break;
        case RIGHT_LEFT:
            rotate_right(&(*t)->r);
            rotate_left(t);
            break;
    }
}

int factor(tree *t) {
    if (*t == NULL) return 0;
    int lh = tree_height(&(*t)->l);
    int rh = tree_height(&(*t)->r);
    return lh - rh;
}

int insert_node_avl(word_t input, tree *t) {
    if(is_empty(t)) {
        *t = (tree) malloc(sizeof(node));
        (*t)->data = input;
        (*t)->l = NULL;
        (*t)->r = NULL;
        (*t)->factor = 0;
        return 0;
    }

    if(strcmp(input.word, (*t)->data.word) < 0) {
        insert_node_avl(input, &(*t)->l);
    } else if(strcmp(input.word, (*t)->data.word) > 0) {
        insert_node_avl(input, &(*t)->r);
    } else {
        return 1;
    }

    (*t)->factor = factor(t);
	//balanceamento;
    if((*t)->factor > 1) {
        if(strcmp(input.word, (*t)->l->data.word) < 0) {
            rotate(LEFT_LEFT, t);
        } else {
            rotate(LEFT_RIGHT, t);
        }
    }
    else if((*t)->factor < -1) {
        if(strcmp(input.word, (*t)->r->data.word) > 0) {
            rotate(RIGHT_RIGHT, t);
        } else {
            rotate(RIGHT_LEFT, t);
        }
    }

    return 0;
}

//end;
