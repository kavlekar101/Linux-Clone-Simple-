/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

void longestFolderName(Folder *head) {
    int numFolders = head->folderNum;
    int i;
    Folder *longestName = head->folders[0];
    for(i = 0; i < numFolders; i++) {
        if (strlen(head->folders[i]->name) > strlen(longestName->name)){
            longestName = head->folders[i];
        }
    }
    if(numFolders == 0) {
        printf("There are no folders in this directory to compare.\n");
    } else {
        printf("The longest name of a folder in this directory is %s, and it is %d characters long. \n", 
            longestName->name, strlen(longestName->name));
    }
}