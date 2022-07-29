/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

void longestFileName(Folder *head) {
    int numFiles = head->fileNum;
    int i;
    struct File *longestName = head->files[i];
    for(i = 0; i < numFiles; i++) {
        if (strlen(head->files[i]->name) > strlen(longestName->name)){
            longestName = head->files[i];
        }
    }
    if(numFiles == 0) {
        printf("There are no files in this directory to compare.\n");
    } else {
        printf("The longest name of a file in this directory is %s, and it is %d characters long. \n", 
            longestName->name, strlen(longestName->name));
    }
}
