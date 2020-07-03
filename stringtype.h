#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Adding bool 
typedef enum {
    false = 0,
    true
} bool;

//Basic string type
typedef struct {
    int length;
    char* charArray;
} String;

//string methods
String* createString();
void setString(String*, const char*);
void append(String*, const char*);
void deleteString(String*);
void println(String*);
bool empty(String*);
char* toCharArray(String*);
void copyString(String*,String*);
void swapString(String*,String*);
