#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodeFunctions.h"


int addSong(song node*table[],char*name,char*artist){
	int row = name[0] % 'a';
	table[row] = insert_inorder(table[row],name,artist);
	return 1;
}

song_node* findSong(song node*table[],char*name){
	int row = name[0] % 'a';
	return searchSong(table[row],name);
}
song_node* findArtist(song node*table[], char*artist){
	int i = 0;
	while ((i++) < 26){
		song_node * temp = searchArtist(table[row],artist);
		if (temp){
			return temp;
		}
	}
	return 0;
}

void printLetter(song node*table[], char*letter){
	int row = letter % 'a';
	print_list(table[row]);
}
void printArtistSongs(song node*table[], char*artist){
	printf("Songs by %s\n------------",artist);
	int i = 0;
	while ((i++)<26){
		int counter = 0;
		song_node* temp = searchArtist(table[i],artist);
		while(temp){
			printf("%d: %s -- %s\n",counter,temp->artist,temp->name);
			temp = searchArtist(temp->next,artist);
			counter++;
		}
		
	}
	
	
}

void printLibrary(song node*table[]){
	int i = 0;
	while ((i++)<26){
		print_list(table[i]);
	}
}
int lenLibrary(song node*table[]){
	int len = 0;
	int i = 0;
	while ((i++)<26){
		len += len(table[i]);
	}
	return len;
}

void shuffleLibrary(song node*table[]){
	srand(time(NULL));
	int randNum = rand() % lenLibrary(table);
	
	song_node* shuffled[randNum];
	int i = 0;
	int counter = 1;
	while ((i++)<randNum){
		int randrow = rand() % 26;
		song_node* randnode = randNode(table[i]);
		printf("%d: %s -- %s\n",counter++,randnode->artist,randnode->name);	
	}		
}


