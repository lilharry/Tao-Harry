#ifndef nodeFunctions_H
#define nodeFunctions_H
#endif

typedef struct n{ 
  char name[256];
  char artist[256];
  struct n *next;
} song_node;


void print_list( song_node *n );
song_node * insert_front( song_node *n, char* name, char*artist);
song_node * free_list( song_node *n );
song_node * insert_inorder(song_node*n,char*name,char*artist);
song_node * searchSong(song_node *n, char* name);
song_node * searchArtist(song_node *n, char*artist);
song_node* randNode(song_node *n);
song_node* deleteNode(song_node*n, char*name,char*artist);

