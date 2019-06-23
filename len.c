#include <stdlib.h>
#include <stdio.h>

/*** 

Name = len.c
Author = Cobraxo
Date = ?

download:
    git clone https://github.com/Cobraxo/Misc.git
 
 comile:
    gcc len.c -o len
set command:
    sudo cp len /bin/my_len

Quality is more important than quantity. One home run is much better than two doubles. hihi xD

***/

int strlen_function(char str[]){

    unsigned int i;
    for (i = 0; str[i] != '\0' ; i++);                                          //i = numbers of char in str[]
    return i;

}

int main(int argc, char *argv[]) {

    if (argc < 2) printf("Usage: %s <string>\n", argv[0]), exit(EXIT_FAILURE);  //If there are no arguments, exit
    printf("%d\n", strlen_function(argv[1]));                                   //Print the len
    return EXIT_SUCCESS;

}
