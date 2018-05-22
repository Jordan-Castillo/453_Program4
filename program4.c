#include "program4.h"

FILE *fp;

int main(int argc, char *argv[]){
   char *fileName;
   struct ext2_super_block *supB;
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
         read_data(0, 1024, p, 1024);
         supB = (struct ext2_super_block *)p;
         printf("form: %%x %%u %%d\n");
         printf("sB.s_inodes_count = %x %u %d\n", supB -> s_inodes_count,
         supB -> s_inodes_count, supB -> s_inodes_count);
         printf("sB.s_blocks_count = %x %u %d\n", supB -> s_blocks_count,
         supB -> s_blocks_count, supB -> s_blocks_count);
         printf("sB.s_r_blocks_count = %x %u %d\n", supB -> s_r_blocks_count,
         supB -> s_r_blocks_count, supB -> s_r_blocks_count);
         printf("sB.s_free_blocks_count = %x %u %d\n", supB -> s_free_blocks_count,
         supB -> s_free_blocks_count, supB -> s_free_blocks_count);
         printf("sB.s_free_inodes_count = %x %u %d\n", supB -> s_free_inodes_count,
         supB -> s_free_inodes_count, supB -> s_free_inodes_count);
         printf("sB.s_log_block_size = %x %u %d\n", supB -> s_log_block_size,
         supB -> s_log_block_size, supB -> s_log_block_size);
      }
   }
   else{ //error message
      printf("Usage: ext2reader <flags> <filename> <directory>\n");
   }
   return 0;
}
