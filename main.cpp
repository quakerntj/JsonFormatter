#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int gChar;
FILE * gFpIn;
FILE * gFpOut;
int gIndent;

static void outputNewline() {
    putchar('\n');
}

static void outputIndent() {
    const int indent = gIndent;
    for (int i = 0; i < indent; i++) {
        putchar('\t');
    }
}

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
        if (first) {
            outputNewline();
            outputIndent();
            first = false;
        }
        if (gChar == '{') {
            first = true;
            gIndent++;
        } else if (gChar == '}') {
            gIndent--;
            outputNewline();
            outputIndent();
        } else if (gChar == ',') {
            first = true;
        } else if (gChar == '[') {
            first = true;
            gIndent++;
        } else if (gChar == ']') {
            gIndent--;
            outputNewline();
            outputIndent();
        }
        putchar(gChar);
    }

    outputNewline();
    fclose(gFpIn);
    return 0;
}
