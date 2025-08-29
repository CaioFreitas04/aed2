#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "data_def.h"
#include "binary_search.h"
#include "binary_tree.h"
#include "song_parser.h"

typedef struct {
	int begin_c;
	int end_c;
	double time;
} time_s;

typedef enum {ARRAY, BIN_T, AVL_T} ds_e;

typedef struct {
	ds_e label;
	char name[32];
	void *ds_pointer;
	insert_func insert;
	search_func search;
	sort_func sort;
	time_s time_data;
} ds_s;


int main() {
	tree *bnt   = initialise_tree();
	tree *avl   = initialise_tree();
	array *arr  = initialise_array();

	ds_s zdeus[] = {
		{ ARRAY, " Busca Binaria (array) ", arr, insert_array         , binary_search, array_quicksort, {0, 0, 0.0}},
		{ BIN_T, "Arvore de Busca Binaria", bnt, insert_node_void     , tree_search  , no_sort        , {0, 0, 0.0}},
		{ AVL_T, "  Arvore Binaria--AVL  ", avl, insert_node_avl_void , tree_search  , no_sort        , {0, 0, 0.0}}
	};
	
	while(1) {
		int op = 0;
		printf("\n\n%s\n%s\n%s\n%s\n\n\n",
		" _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ ",
		"|  _  |  _  |   __|     | __  |     |     |  |  |   __|     |     |",
		"|     |   __|   __|-   -|    -|  |  | | | |  |  |__   |-   -|   --|",
		"|__|__|__|  |_____|_____|__|__|_____|_|_|_|_____|_____|_____|_____|");
		
		printf("\t\t1. Carregar Novo Arquivo.\n");
		printf("\t\t2. Pesquisar Palavra.\n");
		printf("\t\t3. Pesquisar Por Frequencia.\n");
		printf("\t\t4. Sair.\n");
		
		printf("\n\t\t>> ");
		scanf("%d", &op);
		
		switch(op) {
			case 1:
				printf("\n\nInsira o nome do arquivo a ser lido.\n>> ");
				
				char filepath_in[256];
				fgetc(stdin);
				fgets(filepath_in, 256, stdin);
				filepath_in[strcspn(filepath_in, "\n")] = 0;
				
				FILE *testfp = fopen(filepath_in, "r");
				if(testfp == NULL) {
					printf("Arquivo inexistente! Ele esta na pasta do programa?\n\n");
					break;
				}
				for(int i = 0; i < 3; i++) {
					zdeus[i].time_data.begin_c = clock();							//início do clock;
					parse_file(filepath_in, zdeus[i].insert, zdeus[i].ds_pointer);	//lendo arquivo;
					zdeus[i].sort(zdeus[i].ds_pointer);								//ordenando (se necessário);
					zdeus[i].time_data.end_c = clock();								//fim do clock; //vv cálculo do tempo;
					zdeus[i].time_data.time = ((double) zdeus[i].time_data.end_c - zdeus[i].time_data.begin_c) / CLOCKS_PER_SEC;
					printf("\t\t===%s============\n", zdeus[i].name);
					printf("\t\tInsercao concluida em: %lf segundos.\n", zdeus[i].time_data.time);
					printf("\t\t======================================\n\n");
				}
				
			break;
			
			case 2:
			
			break;
			
			case 3:
			
			break;
			
			case 4:
				printf("\n\n\t\tEncerrando...\n\n");
				return 0;
			break;
		}
    }                                                                                                                                      
	return 0;
}