#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct n{ 
  char name[256];
  char artist[256];
  struct n *next;
} song_node;


void print_list( song_node *n ) {

  printf("[ ");
  
  while(n) {
    printf("%s %s", n->name, n->artist );
    n = n->next;
  }
  printf("]\n");
}


song_node * insert_front( song_node *n, char* name, char*artist) {

  song_node *new = (song_node *)malloc(sizeof(song_node));

  new->next = n;
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  
  return new;
}

song_node * insert_inorder(song_node*n,char*name,char*artist){
	
	song_node *new = (song_node *)malloc(sizeof(song_node));
	while (n){
		if (strcmp(n->name,name) < 0){
			break;
		}
		n++;
	}
	
	new->next = n;
	strcpy(new->name, name);
	strcpy(new->artist, artist);
	
	return n;
	
}

song_node * searchSong(song_node *n, char* name){
	while (n){
		if (!strcmp(name,n->name)){
			break;
		}
		n++;
	}
	return n;
}

song_node * searchArtist(song_node *n, char*artist){
	while (n){
		if (!strcmp(name,n->artist)){
			break;
		}
		n++;
	}
	return n;
}

song_node* randNode(song_node *n){
	
}

song_node * free_list( song_node *n ) {

  song_node *f = n;
  while ( n ) {
    n = n->next;
    free(f);
    f = n;    
  }
  return n;
}

/*
#ifndef SHAIK 
#define SHAIK



















