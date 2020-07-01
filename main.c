#include <stdio.h>
#include "stringtype.h"

int main(){
    String str;
    createString(&str,"Hello");
    append(&str,"World");
    println(str);
    deleteString(&str);
    return 0;
}
