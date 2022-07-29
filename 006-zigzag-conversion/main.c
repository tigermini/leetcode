#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * convert(char * s, int numRows){
    int strsize;
    char *tmpstr = NULL;
    int i, j;
    int loopsize, index;

    if (s == NULL || numRows < 1) {
        return NULL;
    }

    strsize = strlen(s);

    tmpstr = (char *)malloc(sizeof(char) * (strsize + 1));
    if (tmpstr == NULL) {
        return NULL;
    }
    memset(tmpstr, 0, sizeof(char) * (strsize + 1));

    if (numRows == 1) {
        strncpy(tmpstr, s, strsize);
        return tmpstr;
    }

    index = 0;
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < strsize; j++) {
            loopsize = 2 * numRows - 2;
            if ((j % loopsize == i) || (j % loopsize == loopsize - i)) {
                tmpstr[index++] = s[j];
            }
        }
    }

    return tmpstr;
}

static void test(char *s,int numRows)
{
    char *tmpstr = NULL;

    tmpstr = convert(s, numRows);
    printf("%s\n", tmpstr);
    free(tmpstr);
    tmpstr = NULL;
}

int main(int argc, char *argv[])
{
    test("PAYPALISHIRING", 3);
    test("A", 1);
    test("AB", 1);

    return 0;
}
