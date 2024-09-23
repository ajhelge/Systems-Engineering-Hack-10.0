//Author: Alec Helgeson
//Date: 11/7/2022
//Purpose: To practice input and output from a file.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "file_utils.h"

char *getFileContents(const char *filePath){
    if(filePath == NULL){
        return NULL;
    }

    FILE *in = fopen(filePath, "r");
    if(in == NULL){
    fprintf(stderr, "Error|Failed to open file: %s\n", filePath);
    return NULL;
    }
    int length = 0;
    while(fgetc(in) != EOF){
        length++;
    }
    rewind(in);
    int i = 0;
    char *string = (char *) malloc(sizeof(char) * (length + 1));
    for(i = 0; i < length; i++){
        string[i] = fgetc(in);
    }
    string[i] = '\0';
    fclose(in);
    return string;
}

char **getFileLines(const char *filePath, int *numLines) {
    if((filePath == NULL) || (numLines == NULL)){
        return NULL;
    }

    FILE *in = fopen(filePath, "r");
    if(in == NULL){
        fprintf(stderr, "Error | Failed to open file: %s\n", filePath);
        return NULL;
    }


    char tempBuffer[10000];
    int lines = 0;
    while(fgets(tempBuffer, 10000, in)) {
            lines++;
    }
    *numLines = lines;
    rewind(in);

    char **stringLib = (char**) malloc(sizeof(char*) * (lines + 1));
    for(int i = 0; i < lines; i++){
        fgets(tempBuffer, 10000, in);
            int length = strlen(tempBuffer);
            stringLib[i] = (char *)malloc(sizeof(char) * (length + 1));
            if(tempBuffer[strlen(tempBuffer) - 1] == '\n') {
                tempBuffer[(strlen(tempBuffer) - 1)] = '\0';
            } else {
                tempBuffer[(strlen(tempBuffer))] = '\0';
            }
            strcpy(stringLib[i], tempBuffer);
    }

    fclose(in);
    return stringLib;
}

void replaceChar(char *s, char oldChar, char newChar){
    if((s == NULL)){
        return;
    }
    else{
        int length = strlen(s);
        for(int i = 0; i < length; i++){
            if(s[i] == oldChar){
                s[i] = newChar;
            }
        }
    }
    return;
}


void removeChar(char *s, char c){
    if((s == NULL)){
            return;
    }
    int length = strlen(s);
    for(int i = 0; i < length; i++){
        if(s[i] == c){
            for(int j = i; j <= length; j++){
                if(j == length){
                    s[j] = '\0';
                }
                else{
                    s[j] = s[j + 1];
                }
            }
        i--;
        }
    }
}


char **lengthSplit(const char *s, int n){
   if((s == NULL) || (n < 1)){
            return NULL;
    }

    int numGroups = ceil(strlen(s) / (double) n);
    char **Array = (char**)malloc(sizeof(char*) * numGroups);
    for(int i = 0; i < numGroups; i++){
        Array[i] = (char*)malloc(sizeof(char) * (n + 1));
    }

    int index = 0;
    for(int i = 0; i < numGroups; i++){
        for(int j = 0; j < n; j++){
            Array[i][j] = s[index];
            index++;
        }
        Array[i][n] = '\0';
    }

    return Array;
}