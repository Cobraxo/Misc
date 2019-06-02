#include <stdlib.h>
#include <stdio.h>

/***
Add in linux command:

gcc len.c -o len && sudo mv len /bin/len && cd

Have fun ! :)
***/

int main(int argc, char *argv[]) {

    int len = 0;

    if (argc < 2) printf("Usage: %s <string>\n", argv[0]), exit(1); //If there are no arguments, exit
    
    for (int i; argv[1][i] != '\0' ; i++, len++);                   //len = numbers of char in argv[1]
    printf("%d\n", len);

    return 0;

}
