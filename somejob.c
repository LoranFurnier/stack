#include <stdio.h>
#include <stdlib.h>
#include "stack.c"
#include "stack.h"
int main(){
    char str[];
    int i = 0;
    do{
        str[i] = getchar();
        i++;
    } while (str[i]!="\n");
}
