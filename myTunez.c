#include <stdio.h>
#include <stdlib.h>

#include "nodeFunctions.h"

#include <time.h>

song_node* table[26];

int main(){
	srand(time(NULL));
	insert_front(table[0],"aba","abababa");
	print_list(table[0]);
	return 0;
}























