
#include "stringtype.h"

//create the String
void createString(String* initString,const char* source){
    initString->length = strlen(source);
    int size = initString->length;
    initString->charArray = (char*)malloc((size+1)*sizeof(char));
    memcpy(initString->charArray,source,size+1);
}

//delete the string
void deleteString(String* source){
    source->length = 0;
    free(source->charArray);
    source->charArray = NULL;
}

//print the string
void println(String source) {
    int i = 0;
    for(i = 0; i<source.length; i++){
        printf("%c",source.charArray[i]);
    }
    printf("\n");
}

//append to another string
void append(String* source, const char* text){
    int i,j;
    int textSize = strlen(text);
    int size = (source->length)+textSize+1;
    char* ptr = (char*)malloc(sizeof(char)*(textSize+1));
    memcpy(ptr,text,textSize+1);
    printf("%d\n",source->length);
    char* temp = (char*)malloc(size*sizeof(char));
    for(i = 0; i<(source->length); i++){
        temp[i] = source->charArray[i];
    }   
    //appending
    for(j = source->length; j<size-1; j++){
        temp[j] = ptr[j];
    }
    source->length = size - 1;
    printf("%d\n",source->length);
    //pointer games
    char* buffer = source->charArray;
    source->charArray = temp;
    free(buffer);
    free(ptr);
    temp = NULL;
}
