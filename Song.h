#ifndef SONG_H
#define SONG_H

struct Song {
  char *artist; //fix size later
  char *album;
  char *title;
  char *year;
};
typedef struct Song song;

song *create_song(char *artist, char *album, char *title, char *year);



void destroy_song(song *s);

char *get_artist(song *s);
char *get_album(song *s);
char *get_title(song *s);
char *get_year(song *s);

#endif // SONG_H
