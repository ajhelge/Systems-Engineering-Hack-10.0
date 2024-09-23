//Author: Alec Helgeson
//Date: 11/7/2022
//Purpose: To practice input and output from a file.

// Takes the input file and places its entire contents into a single string.
char *getFileContents(const char *filePath);

// Takes the input file and places its entire contents into an array of strings
// with each line of the file being its own string.
char **getFileLines(const char *filePath, int *numLines);

//replaces an oldchar with a new char for a given string
void replaceChar(char *s, char oldChar, char newChar);

//removes a given char from a given string
void removeChar(char *s, char c);

//breaks a large string into smaller strings of a given size.
char **lengthSplit(const char *s, int n);