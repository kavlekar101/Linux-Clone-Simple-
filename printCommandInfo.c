/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* prints everything needed to know about the command */
void printCommandInfo() {
	printf("cd: changes directories.\n");
	printf("ls: lists all of the files and folders in the current directory.\n");
	printf("pwd: prints the path to get to the current working directory.\n");
	printf("cat: prints the contents of the file specified.\n");
	printf("cp: copies the contents of the current file to another file.\n");
	printf("mv: moves the current files to the new location specified.\n");
	printf("rm: removes the file specified.\n");
	printf("mkdir: makes a new directory with the specified name in the current directory.\n");
	printf("rmdir: removes the specified directory and makes its contents children of this directory.\n");
	printf("file: creates a new file with the specified name and then enters a pseudo text editor where you can enter up to 256 characters. Every time you press enter, that will be counted as a string, so you can only hit enter 4 times. After that, the text editor will close. Each string also needs to be less than 64 characters, if it is greater than 64, then the extra characters will either be cut off or removed based on how many newline characteres were entered.\n");
	printf("help: you alread pressed help, so you probably know what this is. It's worth noting that the usual flags that are added to the linux/unix commands aren't supported in this fake file system, simply because of time constraints. They may be added in the future.\n");
	printf("For part 2 of the lab: \n");
	printf("longestFolderName: prints out the name and the length of the longest folder name in the current directory, if present.\n");
	printf("longestFileName: prints out the name and the length of the longest file name in the current directory, if present.\n");
	printf("numberOfFilesAndFolders: prints how many files and folders there are combined in the folder.\n");
}
