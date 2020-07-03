//Using this main.c to check the code in stringtype

#include <stdio.h>
#include "stringtype.h"

int main(){
    String* str = createString(&str,"Hello");
    append(str,"World");
    //I added a print function
    println(str);
    deleteString(str);
    return 0;
}
