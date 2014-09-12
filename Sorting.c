#include <stdio.h>

//Calculate the size of the header
int get_header_size(char * header) {
  int size = 0;
  for (int i = 5; i < 10; i++){
    header[i] = header[i] & 127;
    size += header[i];
    // if (i < 9)
      size = size << 7;
  }
  return size;
}

//Save the first 10 bits of the mp3 file (the header)
void get_header(FILE * infile,char * header) {
  
  for (int i = 0; i < 10; i++){
    header[i] = getc(infile);
  }
}

//Sorts mp3 files och så.
void sort_file(char file_name[]) {
  
  FILE *infile;
  char header[10];
  int header_size = 0;

  infile = fopen("music0.mp3", "r");
  if (infile == NULL) {
    puts("File not found");
  }
 
  get_header(infile,header);

  header_size = get_header_size(header);
  
  printf("%d",header_size);
}


int main(void) {
  char name[10] = "music0.mp3";
  sort_file(name);
  return 0;
}
