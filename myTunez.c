#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "nodeFunctions.h"
#include "playlistFunctions.h"


song_node* table[26];


int main(){
	srand(time(NULL));


	int i = 0;
	while (i<26){		
		table[i] = (song_node *)malloc(sizeof(song_node));
		i++;
	}


	//testing inserts
	table[0] = insert_front(table[0],"this is 3rd","gerge");
	print_list(table[0]);

	table[0] = insert_inorder(table[0],"this is 2nd","babab");
	table[0] = insert_inorder(table[0],"this is 1st","ababa");
	
	//testing searches
	song_node* n = searchSong(table[0],"this is 2nd");
    n = searchSong(table[0],"this is 3rd");	
	n = searchSong(table[0],"this isnt 3rd");
	n = searchArtist(table[0],"gerge");
	n = searchArtist(table[0],"babab");
	n = searchArtist(table[0],"gergee");
	
	//testing randNode
	
	n = randNode(table[0]);
	
	//testing deleteNode
	print_list(table[0]);
	n = deleteNode(table[0],"this is 2nd","babab");
	
	//testing free_list	
	table[0] = free_list(table[0]);
	print_list(table[0]);

	//testing playlist functions
	addSong(table, "b 1st", "a");
	addSong(table, "b 3rd", "a");
	addSong(table, "b 2st", "b");
	addSong(table, "b 4th", "a");
	return 0;
}























