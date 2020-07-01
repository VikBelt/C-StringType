#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct {
    int length;
    char* charArray;
} String;

//string methods
void createString(String*, const char*);
void append(String*, const char*);
void deleteString(String*);
void println(String);
