main: program4.c
	gcc program4.c -o ext2reader

clean:
		rm -fr *.elf *.hex *.o ext2reader
