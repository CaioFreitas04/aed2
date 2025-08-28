#include <stdio.h>
#include <stdlib.h>
#include "data_def.h"
#include "binary_search.h"
#include "binary_tree.h"

int main() {
	tree *t   = initialise_tree();
	tree *avl = initialise_tree();
	word_t input;
	
	for(int i = 0; i < 10; i++) {
		sprintf(input.word, "%d", i);
		
		insert_node(input, t);
		insert_node_avl(input, avl);
	}
	
	printf("Standard Tree Height: %d.\n", tree_height(t));
	printf("AVL Tree Height: %d.\n", tree_height(avl));
	traversal(*t, INFIX);
	printf("\n");
	traversal(*avl, INFIX);
	
	return 0;
}