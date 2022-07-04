#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv [] )
{
  struct dirent *pDirent;
  DIR *pDir;
  char name;
  FILE *f;
  char s;
  char *myarg = NULL;
  char buffer[64];


  if(argc != 2){ //checks to make sure user inputed a second input into commmand line
    printf("\n You need to enter a directory path");
    printf("\n");
    return 1;
  }
  /*myarg = argv[1];
  for(int i = 1; i<argc ;i++){
    printf("%s",argv[i]);
    printf("\n");
  }
  */
  pDir = opendir (argv[1]);
  if(pDir == NULL){ //checks to see if the directory exists and if it can be opened
    printf("cannot open directory '%s' \n", argv[1]);
    printf("\n");
    exit(1);
  }
  while((pDirent = readdir(pDir)) != NULL){ //while the spot in the directory is not null
    char *ext = strrchr(pDirent->d_name, '.');
    if(ext == NULL)
      continue;
    if ( strcmp(ext, ".txt") == 0){ //checks to see if the file has .txt in it
      printf ("%s\n", pDirent->d_name); //prints the name of the text file
      for(int i = 1; i<argc ;i++){
        strcpy(buffer,argv[i]);
        strcat(buffer, pDirent->d_name);
      }

      f=fopen(buffer,"r"); //opens the text file
      if(f != NULL){
        while(( s=fgetc(f))!=EOF){ //goes down characters in the file
          printf("%c",s); //prints the characters
          }
        printf("\n"); //prints blank line
        fclose(f); //closes file
        }
        else{
        printf("file is empty\n");
        }
      }

  }
  closedir(pDir); //closes directory
  return 0;

}
