#include "program4.h"

FILE *fp;

int main(int argc, char *argv[]){
   char *fileName;
   struct ext2_super_block *superBlock;
   uint8_t arr[1024];
   uint8_t *p = &arr[0];
   if(argc > 1){
      fileName = argv[1];
      fp = fopen(fileName, "r");
      if(fp == NULL){
         printf("cant find file '%s'!", fileName);
         exit(0);
      }
      else{//start the work here....
         read_data(0, 0, p, 1024);
         superBlock = (struct ext2_super_block *)p;
         printf("first byte... superBlock.s_inodes_count = '%u' or '%x', also does this explode?", superBlock -> s_inodes_count, superBlock -> s_inodes_count);

      }
   }
   else{ //error message
      printf("Usage: ext2reader <flags> <filename> <directory>\n");
   }
   return 0;
}
