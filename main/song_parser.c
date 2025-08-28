#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "data_def.h"
#include "song_parser.h"

void normalise_word(char *input) {
	char *in = input, *out = input;
	while(*in) {
		if(isalpha((unsigned char) *src)) {
			*out = tolower((unsigned char) *src;
			out++;
		}
		in++;
	}
	*out = 0;
}

void parse_file(char *file, insert_func insert, void *data_structure) {
	
	FILE *fp = fopen(file, "r");
	//estrofe é "stanza" aparentemente. Palavra engraçada;
	char line[256], stanza[2048] = "";
	song curr;
	
	fgets(curr.title, sizeof(curr.title), fp);
	curr.title[strcspn(curr.title, "\n")] = 0;
	//confiem nas estruturas de dados alheias, crianças;
	//NUNCA deu errado e NUNCA causou problemas.
	fgets(curr.artist, sizeof(curr.artist), fp);
	curr.artist[strcspn(curr.artist, "\n")] = 0;
	
	while(fgets(line, sizeof(line), fp)) {
		
		if(strcmp(line, "\n") == 0) { //fim de estrofe;
			if(strlen(stanza) > 0) {
				strncpy(curr.lyric, stanza, sizeof(curr.lyric)-1);
				curr.lyric[sizeof(curr.lyric)-1] = '\0';
				
				char *token = strtok(stanza, " \n");
				while(token) {
					normalise_word(token);
					if(strlen(token) > 3 && *token != 0) {
						word_t word_in;
						strcpy(word_in.word, token);
						word_in.sample = curr;
						word_in.freq = 1;
						
						insert(word_in, data_structure);
					}
					token = strtok(NULL, " \n");
				}
				stanza[0] = 0;
			}
			
		} else {
			strncat(stanza, line, sizeof(stanza)-strlen(stanza)-1);
		}
	}
	//tem que repetir porque as músicas não terminam em linha vazia;
	if(strlen(stanza) > 0) {
		strncpy(curr.lyric, stanza, sizeof(curr.lyric)-1);
		curr.lyric[sizeof(curr.lyric)-1] = '\0';
				
		char *token = strtok(stanza, " \n");
		while(token) {
			normalise_word(token);
			if(strlen(token) > 3 && *token != 0) {
				word_t word_in;
				strcpy(word_in.word, token);
				word_in.sample = curr;
				word_in.freq = 1;
						
				insert(word_in, data_structure);
			}
		token = strtok(NULL, " \n");
		}
	}
	
	fclose(fp);
	
}