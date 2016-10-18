#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;


void print_list( song_node *n ) {

  printf("[ ");
  
  while(n) {
    printf("%s %s", n->name, n->artist );
    n = n->next;
  }
  printf("]\n");
}


struct song_node * insert_front( struct song_node *n, char* name, char*artist) {

  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));

  new->next = n;
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  
  return new;
}

struct song_node * insert_inorder(struct song_node*n,char*name,char*artist){
	
	struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
	while (n){
		if (strcmp(n->name,name) < 0){
			break;
		}
		n++;
	}
	
	new->next = n;
	strcpy(new->name, name);
	strcpy(new->artist, artist);
  
	
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






















