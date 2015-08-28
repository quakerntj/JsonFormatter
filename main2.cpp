#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int gChar;
FILE * gFpIn;
FILE * gFpOut;
int gIndent;

static int getNext() {
    return gChar = getc(gFpIn);
}

int main(int argc, char ** argv) {
    if (argc != 2)
        return 0;

    gIndent = 0;
    gFpIn = fopen(argv[1], "r");
    if (gFpIn == NULL)
        return ENOENT;

    bool first = false;
    while (getNext() != EOF) {
        if (gChar == '\r') {
            continue;
        } if (gChar == '\n') {
            continue;
        } else if (gChar == '\t') {
            continue;
        }
        putchar(gChar);
    }

    fclose(gFpIn);
    return 0;
}
