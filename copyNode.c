/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* copies the directory into a new directory recursivly*/
/* Probably the sexiest c file that I have ever written, but it probably contains some wrong things */
void copyNode(Folder *head, Folder *firstFolder, Folder *secondFolder) {
    int i, j;
    if((firstFolder->folderNum) > 0 || (firstFolder->fileNum) > 0 || firstFolder->name[0] != '\0') {
        /* copy all of the raw data */
        strcpy(secondFolder->name, firstFolder->name);
        secondFolder->fileNum = firstFolder->fileNum;
        secondFolder->folderNum = firstFolder->folderNum;
        secondFolder->prev = head;

        /* use the copy files function to copy all of the files' contents from the first directory to the second directory */
        for(j = 0; j < firstFolder->fileNum; j++) {
            copyFileContents(firstFolder->files[j], secondFolder->files[j]);
        }

        if(firstFolder->folderNum > 0) {
            /* recursive call */
            for(i = 0; i < firstFolder->folderNum; i++) {
                /* need to make sure that we aren't trying to access something that is null and if it is, we create memory*/
                if ((secondFolder->folders[i]) == NULL) {
                    secondFolder->folders[i] = makeFolder(head, firstFolder->folders[i]->name);
                    if (secondFolder->folders[i] == NULL) {
                        printf("couldn't make the folder sorry\n");
                    }
                }
                /* make the recursive call baby */
                if (secondFolder->folders[i] != NULL) {
                    copyNode(secondFolder, firstFolder->folders[i], secondFolder->folders[i]);
                }
            }
        }
    }
    return;
}