#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;


void print_list( struct song_node *n );
struct song_node * insert_front( struct song_node *n, char* name, char*artist);
struct song_node * free_list( struct song_node *n );