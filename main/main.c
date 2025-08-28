#include <stdio.h>
#include <stdlib.h>
#include "data_def.h"
#include "binary_search.h"
#include "binary_tree.h"
#include "song_parser.h"

int main() {
	tree *t     = initialise_tree();
	tree *avl   = initialise_tree();
	array *warr = initialise_array();

	for(int i = 0; i < 16; i++) {
		char parser_input[7];
		
		sprintf(parser_input, "%d.txt", i+1);
		
		parse_file(parser_input, insert_array, (void*) warr);
		
		parse_file(parser_input, insert_node_avl_void, (void*) avl);
	}
	word_qsort(warr->arr, 0, warr->size-1);
	
	traversal(*avl, INFIX);
	
	
	return 0;
}