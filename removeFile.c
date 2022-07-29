/* Shashwat Rao */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fakeFiles.h"

/* removes the file */
void removeFile(Folder **head, char *rest){
    int index = findFile(head, rest);
    
    if (index != -1){
        /* remove the file, free the pointer, reduce the number of files in the parent directory, which is the current directory, and move a file at the end to fill in the space in which it was taken out.*/
        free((**head).files[index]);
        (**head).files[index] = NULL;
        (**head).fileNum--;
        fillFileInIndex(head, index);
    } else {
        printf("Please enter the name of a file that exists\n");
    }
}
