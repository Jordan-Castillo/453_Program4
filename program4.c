#include "program4.h"

FILE *fp;

int main(int argc, char *argv[]){
   char *fileName;
   if(argc > 1){
      fileName = argv[1];
      fp = fopen(fileName, "r");
   }
   else{ //error message
      printf("Usage: ext2reader <flags> <filename> <directory>\n");
   }
   return 0;
}
