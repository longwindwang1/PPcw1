#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]) {
  FILE *pgm1, *pgm2;
  int ch1, ch2;
 
  /* Must have to parameters*/
  if (argc < 3) {
    printf("Usage: %s <PGM file 1> <PGM file 2>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
 
  /* 1st file exist? */
  if ((pgm1 = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Error while opening %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
 
  /* 2nd file exist?*/
  if((pgm2 = fopen(argv[2],"r")) == NULL){
    fprintf(stderr,"Error while opening %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }
 
  /* Check: are they same */
  while (((ch1 = fgetc(pgm1)) != EOF) && ((ch2 = fgetc(pgm2)) != EOF)) {
    if (ch1 != ch2) {
      printf("Files are not identical\n");
      break;
    }
  }
 
  /* if not over,two files are not of equal length */
  if ((ch1 != EOF) || (ch2 != EOF))
    printf("Files are not of equal length\n");
  else
    printf("Input files are identical\n");
 
  fclose(pgm1);
  fclose(pgm2);
  return 0;
}
