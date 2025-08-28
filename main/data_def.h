#ifndef DATA_DEF_H
#define DATA_DEF_H

typedef struct {
	char title[50];
	char artist[50];
	char lyric[100];
	int freq;
} song;

typedef struct {
	char word[32];
	song sample;
	int freq;
} word_t;

#endif