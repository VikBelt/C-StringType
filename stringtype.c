
#include "stringtype.h"

//create the String
String* createString(){
    String* initString = (String*)malloc(sizeof(String));
    initString->length = 0;
    return initString;
}

//void setString
void setString(String* source, const char* text){
    //remove the orginal string, if it exists
    if(!empty(source)){
        char* buf = source->charArray;
        free(buf);
        buf = NULL;
    }
    //set the string now
    source->length = strlen(text);
    source->charArray = (char*)malloc(sizeof(char)*source->length+1);
    memcpy(source->charArray,text,source->length+1);
}

//delete the string
void deleteString(String* source){
    source->length = 0;
    free(source->charArray);
    source->charArray = NULL;
    free(source);
    source = NULL;
}

//print the string
void println(String *source) {
    //case of  NO string
    if(source->charArray == NULL){
        printf("string has been deleted\n");
        return;
    }
    //case of empty string
    if(empty(source)){
        printf("empty string - nothing to print\n");
        return;
    }
    //normal case
    int i = 0;
    for(i = 0; i<source->length; i++){
        printf("%c",source->charArray[i]);
    }
    printf("\n");
}

//append to another string
void append(String* source, const char* text){
    //safety check
    if(source->charArray == NULL|| text == NULL){
        printf("error: cannot append\n");
        return;
    }
    //code to append
    int textSize = strlen(text)+1;
    int newSize = source->length + textSize;
    char* temp = (char*)malloc(sizeof(char)*(newSize));
    memcpy(temp,source->charArray,source->length+1);
    strcat(temp,text);
    source->length = newSize-1;
    //switch around the pointers
    char* buf = source->charArray;
    source->charArray = temp;
    temp = NULL;
    free(buf);
    buf = NULL;
}

//is empty
bool empty(String* source){
    if(source->length == 0){
        return true;
    }
    else {
        return false;
    }
}

//return a charArray
char* toCharArray(String* source){
    char* array;
    array = (char*)malloc(sizeof(char) * source->length+1);
    memcpy(array,source->charArray,source->length+1);
    return array;
}

//copy strings 
void copyString(String* destination, String* source){
    //safety check
    if(destination->charArray == NULL || source->charArray == NULL){
        printf("error: cannot copy\n");
        return;
    }
    //copy code
    destination->length = source->length;
    char* buf = destination->charArray;
    destination->charArray = (char*)malloc(sizeof(char)*destination->length + 1);
    memcpy(destination->charArray,source->charArray,source->length);
    free(buf);
    buf = NULL;
}

//swap string
void swapString(String* stringOne, String* stringTwo){
    //swap pointers
    char* buf = stringOne->charArray;
    stringOne->charArray = stringTwo->charArray;
    stringTwo->charArray = buf;
    buf = NULL;
    //swap length
    int temp = stringOne->length;
    stringOne->length = stringTwo->length;
    stringTwo->length = temp;
}
