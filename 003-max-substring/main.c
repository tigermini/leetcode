#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
    int slen;
    int i;
    int maxcount = 0, curcount = 0, preloc = 0, curloc = 0;
    int ascii[256] = {0};

    if (s == NULL) {
        return 0;
    }

    slen = strlen(s);
    for (i = 0; i < slen; i++) {
        if (ascii[(int)s[i]] != 1) {
            ascii[(int)s[i]] = 1;
            curloc++;
            curcount++;
            maxcount = maxcount < curcount ? curcount : maxcount;
        } else {
            ascii[(int)s[preloc]] = 0;
            preloc++;
            curcount--;
            i--;
        }
    }

    return maxcount;
}

static void test(char *s)
{
    int ret = 0;

    ret = lengthOfLongestSubstring(s);

    printf("%d\n", ret);
}

int main(int argc, char *argv[])
{
    char *s1 = "abcabcbb";
    char *s2 = "bbbbb";
    char *s3 = "pwwkew";
    char *s4 = "abcaefgh";
    char *s5 = "aab";
    char *s6 = "abab";

    test(s1);
    test(s2);
    test(s3);
    test(s4);
    test(s5);
    test(s6);

    return 0;
}