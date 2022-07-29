/* Shashwat Rao */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fakeFiles.h"

/* moves the head pointer backward one node*/
void moveBackward(Folder **head){
	*head = (*head)->prev;
}
