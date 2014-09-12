#include <stdio.h>

char header[10];
int size = 0;
FILE *infile;

int main(void) {
  infile = fopen("music0.mp3", "r");
  if (infile == NULL) {
    puts("File not found");
  }
  
  char ch;

  for (int i = 0; i < 10; i++){
    ch = getc(infile);
    header[i] = ch;
    printf("%d ",ch);
  }
  
  for (int i = 5; i < 10; i++){
    header[i] = header[i];
    size += header[i];
    // if (i < 9)
      size = size << 7;
    
  }
 
  int body[size];

  for (int i = 10; i < size; ++i){
    body[i] = getc(infile);
    printf("%d", body[i]);
  
  }

  //hej igen


}
    // CH = getc(infile);
    //printf("%c\n",ch);
    /*
    for(int i = 5; i < 10; i++){
      size += sizeOfFile[i];
      size = size << 7;
    */
    
  //    fseek(infile, 0,SEEK_CUR);
    
  //    printf("id: %c%c%c%c%c\nflag:%c\nsize:%c%c%c%c\n",h.id[0],h.id[1],h.id[2],h.id[3],h.id[4],h.flag, h.size[0], h.size[1], h.size[2], h.size[3]);


