main: program4.c ext2.c
	gcc -o ext2reader program4.c ext2.c

clean:
		rm -fr *.elf *.hex *.o ext2reader
