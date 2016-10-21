#ifndef playlist_functions_h
#define playlist_functions_h

void shuffleLibrary(song_node*table[]);
int lenLibrary(song_node*table[]);
void printLibrary(song_node*table[]);
void printArtistSongs(song_node*table[], char*artist);
void printLetter(song_node*table[], char*letter);
song_node* findArtist(song_node*table[], char*artist);
song_node* findSong(song_node*table[],char*name);
int addSong(song_node*table[],char*name,char*artist);

#endif
