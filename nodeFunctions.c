#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct n{ 
  char name[256];
  char artist[256];
  struct n *next;
} song_node;


void print_list( song_node *n ) {
  int counter = 1;
  while(n) {
    printf("%d: %s -- %s\n",counter, n->artist, n->name );
    n = n->next;
	counter++;
  }
  printf("\n");
}


song_node * insert_front( song_node *n, char* name, char*artist) {
  printf("before insert_front:\n ");
  print_list(n);
  
  song_node *new = (song_node *)malloc(sizeof(song_node));

  new->next = n;
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  
  printf("\nafter insert_front:\n ");
  print_list(new);
  printf("\n\n");
  return new;

}

song_node * insert_inorder(song_node*n,char*name,char*artist){
	
	song_node *new = (song_node *)malloc(sizeof(song_node));
	
	while (n){
		//					insert
		if (strcmp(n->name,name) < 0){
			break;
		}
		n = n->next;
 	}
    printf("before insert_inorder:\n");
    print_list(n);
 
	new->next = n->next;
	n->next = new;
	strcpy(new->name, name);
	strcpy(new->artist, artist);
    
	printf("\nafter insert_front:\n");
    print_list(n);
	printf("\n\n");
 
	
	return n;
	
}

song_node * searchSong(song_node *n, char* name){
	printf("searching for song %s...",name);
	while (n){
		if (!strcmp(name,n->name)){
			printf("found!\n\n");
			return n;
		}
		n = n->next;
	}
	printf("not found!\n\n");
	return 0;
}

song_node * searchArtist(song_node *n, char*artist){
	printf("searching for artist %s...",artist);
	while (n){
		if (!strcmp(artist,n->artist)){
			printf("found!\n\n");
			return n;
		}
		n = n->next;
	}
	printf("not found!\n\n");
	return 0;
}

int len(song_node *n){
	int len = 0;
	while (n){
		len++;
		n = n->next;
	}
	return len;
}

song_node* randNode(song_node *n){
	int i = rand()%len(n);
	printf("rand num between 0 and %d: %d\n\n",len(n), i);
	while(i--){
		n = n->next;
	}
	return n;
}

song_node* deleteNode(song_node*n, char*name,char*artist){
	printf("deleting %s -- %s: ",artist,name);
	//head
	if (!strcmp(name,n->name) && !strcmp(artist,n->artist)){
		song_node*temp = n->next;
		free(n);
		printf("deleted, it was the head node");
		return temp;
	}
	
	//if middle
	song_node* head = n;
	song_node*temp = n;
	n = n->next;
	while (n){
		if (!strcmp(name,n->name) && !strcmp(artist,n->artist)){
			temp->next = n->next;
			free(n);
			printf("deleted, it was not the head node");
			return head;
		}
		temp = n;
		n= n->next;
	}
	printf("song not found!");
	return 0;
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



















