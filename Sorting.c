#include <stdio.h>

struct Header_struct {
  char id[5];
  char flag;
  char size[4];
};

FILE *infile;


int main(void) {
  infile = fopen("music0.mp3", "r");
  if (infile == NULL) {
    puts("File not found");
  }

  //struct Header_struct h;
  int ch;
  //fread(&h,sizeof(h),1,infile);
  for (int i = 0; i < 10; ++i){

    ch = getc(infile);
    printf("%d ",ch);
    fseek(infile, 0,SEEK_CUR);
    // ch = getc(infile);
    //printf("%c\n",ch);
  }
  //    printf("id: %c%c%c%c%c\nflag:%c\nsize:%c%c%c%c\n",h.id[0],h.id[1],h.id[2],h.id[3],h.id[4],h.flag, h.size[0], h.size[1], h.size[2], h.size[3]);
}

