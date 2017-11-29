/*
 * Given an integer, return its base 7 string representation.
 *
 * Example 1:
 *      Input: 100
 *      Output: "202"
 * Example 2:
 *      Input: -7
 *      Output: "-10"
 *
 * Note: The input will be in range of [-1e7, 1e7].
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>

#define MAX_LEN 20

void reverse_str_section (char* ch, int low, int high)
{
    if (!ch || (low < 0) || (high < 0) || (low > high)) {
        return;
    }

    while (low < high) {
        if (ch[low] != ch[high]) {
            ch[low] ^= ch[high];
            ch[high] ^= ch[low];
            ch[low] ^= ch[high];
        }

        ++low;
        --high;
    }
}

/*
 * This function converts an integer to base seven.
 */
char* convertToBase7(int num)
{
    char* base7_str;
    int index, rem;
    bool if_negative;

    if (num < 0) {
        num *= -1;
        if_negative = true;
    } else {
        if_negative = false;
    }

    base7_str = (char*)malloc(sizeof(char) * MAX_LEN);

    if (!base7_str) {
        return(NULL);
    }

    memset(base7_str, 0, sizeof(char) * MAX_LEN);
    index = 0;
    do {
        rem = num % 7;

        num /= 7;

        base7_str[index] = '0' + rem;

        ++index;

    } while (num > 0);

    if (if_negative) {
        base7_str[index] = '-';
        ++index;
    }

    reverse_str_section(base7_str, 0, index - 1);

    return(base7_str);
}

int main ()
{
    assert(!strcmp("0", convertToBase7(0)));
    assert(!strcmp("1", convertToBase7(1)));
    assert(!strcmp("-1", convertToBase7(-1)));
    assert(!strcmp("10", convertToBase7(7)));
    assert(!strcmp("202", convertToBase7(100)));
    assert(!strcmp("150666343", convertToBase7(10000000)));
    assert(!strcmp("-150666343", convertToBase7(-10000000)));

    return(0);
}
