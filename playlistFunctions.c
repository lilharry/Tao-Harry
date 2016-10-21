#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodeFunctions.h"


int addSong(song_node*table[],char*name,char*artist){	
	int row = name[0] % 'a';
	printf("Adding %s -- %s to row %d...\n",artist,name,row);
	table[row] = insert_inorder(table[row],name,artist);
	return 1;
}

song_node* findSong(song_node*table[],char*name){
	int row = name[0] % 'a';
	printf("Looking in row %d for song %s...\n",row,name);
	return searchSong(table[row],name);
}
song_node* findArtist(song_node*table[], char*artist){
	int i = 0;
	printf("Looking for artist %s...\n",artist);
	while (i < 26){
		printf("row %d: ",i);
		song_node * temp = searchArtist(table[i],artist);
		if (temp){
			printf("%s -- %s",temp->artist,temp->name); 
			return temp;
		}
		i++;
	}
	return 0;
}

void printLetter(song_node*table[], char*letter){
	int row = letter[0] % 'a';
	printf("in row %d...\n",row);
	print_list(table[row]);
}
void printArtistSongs(song_node*table[], char*artist){
	printf("Songs by %s\n------------",artist);
	int i = 0;
	while (i<26){
		int counter = 0;
		song_node* temp = searchArtist(table[i],artist);
		while(temp){
			printf("%d: %s -- %s\n",counter,temp->artist,temp->name);
			temp = searchArtist(temp->next,artist);
			counter++;
		}
		i++;
	}
	
	
}

void printLibrary(song_node*table[]){
	int i = 0;
	while (i<26){
		printf("%c list\n",i+'a');
		print_list(table[i]);
		i++;
	}
}
int lenLibrary(song_node*table[]){
	int length = 0;
	int i = 0;
	while (i<26){
		length += len(table[i]);
		i++;
	}
	return length;
}


song_node* randrow(song_node*table[]){
	song_node* x = table[rand()%26];
	while (len(x) == 0){
		x = table[rand()%26];
	}
	return x;
}
void shuffleLibrary(song_node*table[]){
	int i = 0;
	int counter = 1;
	while (i<lenLibrary(table)){
		song_node* randnode = randNode(randrow(table));
		if (randnode){
			printf("%d: %s -- %s\n",counter++,randnode->artist,randnode->name);
			i++;
			counter++;
		}
	}
}


song_node* deleteSong(song_node*table[],char*name,char*artist){
	int row = name[0] % 'a';
	table[row] = deleteNode(table[row],name,artist);
	return table[row];
}

song_node* clearLibrary(song_node*table[]){
	int i = 0;
	while (i<26){
		free_list(table[i]);
		i++;
	}
	return 0;
}





