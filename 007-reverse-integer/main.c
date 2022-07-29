#include <stdio.h>

#ifndef INT_MAX
#define INT_MAX     ((int)(~0U>>1))
#endif

#ifndef INT_MIN
#define INT_MIN     (-INT_MAX - 1)
#endif

int reverse(int x){
    int retint = 0;

    while (x != 0) {
        retint = retint * 10 + (x % 10);
        x = x / 10;

        if (((retint == INT_MAX / 10) && x > 7) || ((retint > INT_MAX / 10) && x > 0)) {
            return 0;
        }
        if (((retint == INT_MIN / 10) && x < -8) || ((retint < INT_MIN / 10) && x < 0)) {
            return 0;
        }
    }

    return retint;
}

static void test(int x)
{
    printf("%d\n", reverse(x));
}

int main(int argc, char *argv[])
{
    test(123);
    test(-123);

    return 0;
}
