//Author: Alec Helgeson
//Date: 11/7/2022
//Purpose: To practice input and output from a file.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_utils.h"

int main(){
    const char *filePath = "new.txt";


    // char *new = getFileContents(filePath);
    // FILE *in = fopen(filePath, "r");
    // int length = 0;
    // while(fgetc(in) != EOF){
    //     length++;
    // }
    // fclose(in);
    // for(int i = 0; i < length; i++){
    //     printf("line %d: %c\n", i, new[i]);
    // }

    int lines = 0;
    char **fileArray = getFileLines(filePath, &lines);
    printf("Lines: %d\n", lines);
    for(int i = 0; i < lines; i++) {
        printf("%s\n", fileArray[i]);
    }

    return 0;

}