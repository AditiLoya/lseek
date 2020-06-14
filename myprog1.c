#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include "file.h"

int main(argc, *argv[]){
  int fd;
  int off;
  int len;
  char *str1, *str2;
  if(argc != 5){
    printf("Please give all arguments");
    exit(0);
  }
  fd = open(argv[1],O_RDONLY);
  off = atoi(argv[2]);
  lseek(fd, off, SEEK_SET);
  len = atoi(argv[3]);
  str2 = argv[4];
  read(fd, str1, len);
  if (strcmp(str1, str2) == 0)
    printf("lseek works");
  else
    printf("lseek doesn't work");
  return 0;
}
