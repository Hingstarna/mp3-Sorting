struct Song {
  char *artist; //fix size later
  char *album;
  char *title;
  char *year;
};
typedef struct Song song;

song* create_song(char *artist, char *album, char *title, char *year);

void destroy_song(song *s);
void set_artist(song *s);
void set_album(song *s);
void set_year(song *s);

char *get_artist(song *s);
char *get_album(song *s);
char *get_title(song *s);
char *get_year(song *s);
