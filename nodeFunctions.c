#include <stdio.h>
#include <stdlib.h>

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;


void print_list( struct song_node *n ) {

  printf("[ ");
  
  while(n) {
    printf("%d ", n->data );
    n = n->next;
  }
  printf("]\n");
}


struct song_node * insert_front( struct song_node *n, int  d ) {

  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));

  new->next = n;
  new->data = d;

  return new;
}

struct song_node * free_list( struct song_node *n ) {

  struct song_node *f = n;
  while ( n ) {
    n = n->next;
    free(f);
    f = n;    
  }
  return n;
}






















