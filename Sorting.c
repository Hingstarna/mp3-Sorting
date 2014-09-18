/*
  H20 sum_header_size 1 & 2
  M36 get_header
  M38
*/

#include <stdio.h>
#include <dirent.h>
#include "song.h"
#define MAX_SIZE 100

//Calculate the size of the header
<<<<<<< HEAD

int get_header_size(char * header) {
  int size = 0;
  for (int i = 5; i < 10; i++){
    header[i] = header[i] & 127;
    size += header[i];
    // if (i < 9)
      size = size << 7
  
}
  return size;

}

//Save the first 10 bits of the mp3 file (the header)
void get_header(FILE* infile, char *header) {
  for (int i = 0; i < 10; i++){
    header[i] = getc(infile);    
    //*(header+i) = getc(infile);
  }
}


void load_frames(FILE* infile, char* frames, int size) {
  for (int i = 0; i < size;i++) {
    frames[i] = getc(infile);
    //    printf("%c",frames[i]);
  }
}

void search_frames(int size, char* frames) {
  for (int i = 0; i < size; i++) {
    if (frames[i] == 'T' && frames[i+1] == 'P' && frames[i+2] == 'E' && frames[i+3] == '1') {
      int frame_size = 0;
      i += 4;
      frame_size += frames[i] & 127;
      frame_size = frame_size << 7;

      frame_size += frames[i+1] & 127;
      frame_size = frame_size << 7;
     
      frame_size += frames[i+2] & 127;
      frame_size = frame_size << 7;

      frame_size += frames[i+3] & 127;
      //frame_size += byte4;
      i += 7  ;//+7 för att hoppa över storleks bytes, flaggor och textencoding
      printf("Artists name is: ");
      for (int j = 0;j <= frame_size-3; j++) {//3 för att jag har hoppat över 3 flaggor
		    printf("%c", frames[i+j]?frames[i+j]:'#');
      }
      puts("\n");
    }
    //if (frames[i] == 'T' && frames[i+1] == 'A' && frames[i+2] == 'L' && frames[i+3] == 'B')
    // puts("found TALB\n");
  }
}


//Sorts mp3 files och så.
void sort_file(char file_name[]) {

  
  FILE* infile;

  char header[10];
  int header_size = 0;
 
  infile = fopen("music0.mp3", "r");
  if (infile == NULL) {
    puts("File not found\n");
  }
 
  get_header(infile,header);

  //Value
  //header_size = sum_header_size(header,header_size);

  //Reference
  sum_header_size2(header,&header_size);
  
  
  
  char frames[header_size];
  load_frames(infile,frames,header_size);
  //printf("%c%c%c\n",frames[0],frames[1],frames[2]);
  //  printf("%d",header_size);
  //  struct song s;
  search_frames(header_size,frames);

  fclose(infile);
}

void read_dir(char* path) {
  DIR* d = opendir(path);
  struct dirent *dir;

  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n",dir->d_name);
    }
  } else {puts("fel");}
  closedir(d);
}

int main(void) {
  char name[10] = "music0.mp3";
  sort_file(name);
  //read_dir("/home/micael/Downloads/");
  return 0;
}


