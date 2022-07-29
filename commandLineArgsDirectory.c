/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"
#include <dirent.h>
#include <sys/types.h>

void commandLineArgsDirectory(Folder **head, char *input){
    /* has to be called with the name */
    /* So basically, you should open the current directory, 
        use the string splitting algorithm to split the strings into parts 
        Then open those directories recursivly, 
        then keep doing that until you find the directory. 
        Copy all of those contents into your home directory in the program 
        then initialize them with some stupid stuff. */
    
    DIR *dir; /* will hold the folder whose contents we are looking through */
    struct dirent *current; /* will find the file and copy those */
    int i = 0;
    struct File *newFile;

    dir = opendir(input);
    if(dir){
        while(i < 64 && (current=readdir(dir)) != NULL) {
            if (current->d_type == 8){
                printf(">> %s\n", current->d_name);
                newFile = createMemoryForFile();
                strcpy(newFile->name, current->d_name);
                strcpy(newFile->contents[0], "something");
                strcpy(newFile->contents[1], "something");
                strcpy(newFile->contents[2], "something");
                strcpy(newFile->contents[3], "something");
                (*head)->files[i] = newFile;
                (*head)->fileNum++;
                i++;
            }
        }
    } else {
        printf("Duuuuuuuuuuuude. You totally [don't] rock - turtle guy from Nemo. \n");
        printf("Please enter a folder path that actually exists next time. \n");
    }
    closedir(dir);
}