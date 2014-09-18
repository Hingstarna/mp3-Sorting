#include "song.h"
song* create_song(char *artist, char *album, char *title, char *year) {
  song *s = malloc(sizeof(song));
  memset(s,0,sizeof(struct Song));
  
  s->artist = malloc(*artist);
  s->album  = malloc(*album);
  s->title  = malloc(*title);
  s->year   = malloc(*year);

  return s;
}
void destroy_song(song *s) {
  free(s->artist);
  free(s->album);
  free(s->title);
  free(s->year);
  free(s); 
}
void set_artist(song *s, char *string){
  *(s->artist) = *string;
}
void set_album(song *s, char *string){
  *(s->album) = *string;
}
void set_title(song *s, char *string){
  *(s->title) = *string;
}
void set_year(song *s, char *string){
  *(s->year) = *string;
}




char * get_artist(song *s) {
  return s->artist;
}
char *get_album(song *s) {
  return s->album;
}
char *get_title(song *s) {
  return s->title;
}
char *get_year(song *s) {
  return s->year;
}