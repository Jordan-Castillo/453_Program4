#include "program4.h"

FILE *fp;

int main(int argc, char *argv[]){
   char *fileName;
   if(argc > 1){
      fileName = argv[1];
      fp = fopen(fileName, "r");
      if(fp == NULL){
         printf("cant find file '%s'!", fileName);
         exit(0);
      }
      else{
         printf("all was fine\n");
      }
   }
   else{ //error message
      printf("Usage: ext2reader <flags> <filename> <directory>\n");
   }
   return 0;
}
