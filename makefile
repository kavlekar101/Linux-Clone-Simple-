# Shashwat Rao

# Makefile for lab 1-4.

#change the last dependency for each new lab
all: lab3

#this entry has to change for lab 2 - 4
# NEVER compile .c files with this rule - it lacks needed compile time flags
# There is an entry below that turns .c files into .o files

lab3: part1 lab3.zip part2 part3

part1: recursivlyRemoveFolder.o moveFolder.o moveFile.o copyFileContents.o copyFile.o copyNode.o copyFolder.o getLastPart.o fillFileInIndex.o removeFile.o removeFiles.o removeFoldersIfEmpty.o printWorkingDirectory.o moveBackToFolder.o printFileContents.o findFile.o printFile.o readFullLine.o fileTheContents.o createMemoryForFile.o createFile.o fillFolderInIndex.o removeFolderIfEmpty.o makeFolders.o moveBackward.o findFolder.o moveForward.o getNextDirName.o changeDirectories.o printCommandInfo.o listFiles.o listFolders.o listDirectoryContents.o insertFolder.o executeCommand.o readInCommand.o makeFolder.o main.o
	gcc -g -o $@ $^

part2: dirPrint.o numberOfFilesAndFolders.o longestFileName.o longestFolderName.o recursivlyRemoveFolder.o moveFolder.o moveFile.o copyFileContents.o copyFile.o copyNode.o copyFolder.o getLastPart.o fillFileInIndex.o removeFile.o removeFiles.o removeFoldersIfEmpty.o printWorkingDirectory.o moveBackToFolder.o printFileContents.o findFile.o printFile.o readFullLine.o fileTheContents.o createMemoryForFile.o createFile.o fillFolderInIndex.o removeFolderIfEmpty.o makeFolders.o moveBackward.o findFolder.o moveForward.o getNextDirName.o changeDirectories.o printCommandInfo.o listFiles.o listFolders.o listDirectoryContents.o insertFolder.o executeCommandForPart2.o readInCommand.o makeFolder.o main.o
	gcc -g -o $@ $^

part3: commandLineArgsDirectory.o dirPrint.o numberOfFilesAndFolders.o longestFileName.o longestFolderName.o recursivlyRemoveFolder.o moveFolder.o moveFile.o copyFileContents.o copyFile.o copyNode.o copyFolder.o getLastPart.o fillFileInIndex.o removeFile.o removeFiles.o removeFoldersIfEmpty.o printWorkingDirectory.o moveBackToFolder.o printFileContents.o findFile.o printFile.o readFullLine.o fileTheContents.o createMemoryForFile.o createFile.o fillFolderInIndex.o removeFolderIfEmpty.o makeFolders.o moveBackward.o findFolder.o moveForward.o getNextDirName.o changeDirectories.o printCommandInfo.o listFiles.o listFolders.o listDirectoryContents.o insertFolder.o executeCommandForPart2.o readInCommand.o makeFolder.o mainPart3.o
	gcc -g -o $@ $^

clear: makefile
	rm *.o

#this is where you create an entry to build your zip file
#it will also update with new labs
lab3.zip: makefile *.c *.h lab3readme
	zip lab3.zip makefile *.c *.h lab3readme

#this entry stays for C code labs
tags: *.c
	ctags -R .

# this entry stays for C code labs
headers: *.c tags
	headers.sh


# this entry takes care of C files depending on header files
# It has the flags for compiling the c code
# It you don't like makefiles, consider typing the following line a few
# thousand times this semester and reconsider.
# Be sure that this one doesn't get an inserted line break anywhere
%.o:%.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@


