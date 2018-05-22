#include "program4.h"

//GLOBALS...
FILE *fp;

//CONSTRUCTORS...
void giveSuperBlock(struct ext2_super_block *p);
void giveInodes(struct ext2_inode *p);

int main(int argc, char *argv[]){
   char *fileName, *destination;
   int iNodesPerGroup;
   struct ext2_super_block supB;
   struct ext2_inode iNode;

   fileName = argv[1];
   if(argc > 1)
      destination = argv[2];
   else{
      printf("Usage: ext2reader <flags> <filename> <directory>\n");
      exit(0);
   }
   if((fp = fopen(fileName, "r")) == NULL){
         printf("cant find file '%s'!", fileName);
         exit(0);
   }
   giveSuperBlock(&supB);
   printf("s_inodes_count = %u\n", supB.s_inodes_count);
   printf("s_inodes_per_group = %u\n", supB.s_inodes_per_group);

   printf("s_first_data_block %%u = %u\n", supB.s_first_data_block);
   printf("s_first_data_block %%x = %x\n", supB.s_first_data_block);


   iNodesPerGroup = supB.s_inodes_per_group;

   giveInodes(&iNode);
   printf("i_size = %x\n", iNode.i_size);
   printf("i_blocks = %u\n", iNode.i_blocks);
   printf("i_links_count = %u\n", iNode.i_links_count);



}

void giveInodes(struct ext2_inode *p){
   read_data(6, 0, (uint8_t*)p, sizeof(struct ext2_inode));
}

void giveSuperBlock(struct ext2_super_block *p){
   read_data(2, 0, (uint8_t*)p, sizeof(struct ext2_super_block));
   return;
}
