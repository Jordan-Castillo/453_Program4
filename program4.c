#include "program4.h"

FILE *fp;

int main(int argc, char *argv[]){
   char *fileName;
   uint8_t arr[1024];
   if(argc > 1){
      fileName = argv[1];
      fp = fopen(fileName, "r");
      if(fp == NULL){
         printf("cant find file '%s'!", fileName);
         exit(0);
      }
      else{//start the work here....
         read_data(0, 0, &arr, 1024);
         printf("first byte... arr[0] = '%d'", arr[0]);
      }
   }
   else{ //error message
      printf("Usage: ext2reader <flags> <filename> <directory>\n");
   }
   return 0;
}
