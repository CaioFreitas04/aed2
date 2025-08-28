#ifndef SONG_PARSER_H
#define SONG_PARSER_H

typedef int (*insert_func)(word_t input, void *data_structure);

void normalise_word(char *input);
void parse_file(char *file, insert_func insert, void *data_structure);

#endif