#include "Song.h"
Song create_song(char *artist, char *album, char *title) {
  Song s = malloc(sizeof(Song));
  
  s->artist = artist;
  s->album  = album;
  s->title  = title;

  return s;
}
void destroy_song(Song s) {
  free(s->artist);
  free(s->album);
  free(s->title);
  free(s); 
}

char *song_get_artist(Song s) {
  return s->artist;
}
char *song_get_album(Song s) {
  return s->album;
}
char *song_get_title(Song s) {
  return s->title;
}
char *song_get_year(Song s) {
  return s->year;
}
