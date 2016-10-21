#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "nodeFunctions.h"
#include "playlistFunctions.h"


song_node* table[26];


int main(){
	srand(time(NULL));

	int i = 26;
	while (--i>=0){		
		table[i] = (song_node *)malloc(sizeof(song_node));
	}
	
	
	
	table[0] = insert_front(table[0],"aba","abababa");
	print_list(table[0]);
	table[0] = insert_inorder(table[0],"bab","bababa");
	print_list(table[0]);
	
	
	return 0;
}























