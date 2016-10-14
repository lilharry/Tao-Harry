#include <stdio.h>
#include <stdlib.h>
/*
typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;
*/

struct song_node * table[26];

int main(){
	print_list(table);
	return 0;
}





















