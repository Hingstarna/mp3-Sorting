#ifndef SONG_H
#define SONG_H

struct Song {
	///Name of artist
  char *artist; //fix size later
  	///Name of album
  char *album;
  	///Name of title
  char *title;
  	///Year
  char *year;
};
typedef struct Song *Song;

Song create_song(char *artist, char *album, char *title);



void destroy_song(Song s);

char *song_get_artist(Song s);
char *song_get_album(Song s);
char *song_get_title(Song s);
char *song_get_year(Song s);

#endif // SONG_H
