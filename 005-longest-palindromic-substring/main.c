#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * longestPalindrome(char * s){
    int strsize;
    int left = 0, right = 0;
    int center;
    int maxlength = 0;
    int maxleft = 0;
    char *tmpstr;

    strsize = strlen(s);

    /* 单独判断单个字符情况 */
    if (strsize < 2) {
        return s;
    }

    /* 回文数为奇数 */
    for (center = 0; center < strsize; center++) {
        left = center;
        right = center;
        while ((left >= 0) && (right < strsize)) {
            if (s[left] == s[right]) {
                if (maxlength < (right - left + 1)) {
                    maxlength = right - left + 1;
                    maxleft = left;
                }
                left--;
                right++;
            } else {
                break;
            }
        }
    }

    /* 回文数为偶数 */
    for (center = 0; center < strsize - 1; center++) {
        left = center;
        right = center + 1;
        while ((left >= 0) && (right < strsize)) {
            if (s[left] == s[right]) {
                if (maxlength < (right - left + 1)) {
                    maxlength = right - left + 1;
                    maxleft = left;
                }
                left--;
                right++;
            } else {
                break;
            }
        }
    }

    tmpstr = (char *)malloc(sizeof(char) * (maxlength + 1));
    if (tmpstr == NULL) {
        return NULL;
    }
    memset(tmpstr, 0, sizeof(char) * (maxlength + 1));

    strncpy(tmpstr, s + maxleft, maxlength);

    return tmpstr;
}

static void test(char *s)
{
    char *sret = NULL;

    sret = longestPalindrome(s);

    printf("%s\n", sret);
    free(sret);
    sret = NULL;
}

int main(int argc, char *argv[])
{
    test("babad");
    test("cbbd");
    test("ca");

    return 0;
}
