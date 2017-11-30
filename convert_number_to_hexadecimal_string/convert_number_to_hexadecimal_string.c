/*
 * This program converts a number to hexadecimal string.
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>

char* convert_number_to_hexadecimal_str (int num)
{
    char* hexa_str;
    int hexa_str_len;
    int nibble;
    int nibble_num;
    int msb_mask = 0xf0000000;
    int lsb_mask = 0x0000000f;
    int index;
    bool if_non_zero_entered;
    char char_mapping[16] = {'0',
                             '1',
                             '2',
                             '3',
                             '4',
                             '5',
                             '6',
                             '7',
                             '8',
                             '9',
                             'a',
                             'b',
                             'c',
                             'd',
                             'e',
                             'f'};

    hexa_str_len = sizeof(int) * 2 + 1;

    hexa_str = (char*)malloc(sizeof(char) * hexa_str_len);

    if (!hexa_str) {
        return(NULL);
    }

    memset(hexa_str, 0, sizeof(char) * hexa_str_len);

    if (num == 0) {
        hexa_str[0] = char_mapping[num];
        return(hexa_str);
    }

    index = 0;
    if_non_zero_entered = false;
    nibble_num = 0;
    while (nibble_num < (sizeof(int) * 2)) {
        nibble = num & msb_mask;
        nibble >>= 28;
        nibble &= lsb_mask;
        num <<= 4;
        ++nibble_num;

        if (nibble > lsb_mask) {
            continue;
        }

        if (!if_non_zero_entered && (nibble == 0)) {
            continue;
        }

        hexa_str[index] = char_mapping[nibble];
        ++index;

        if (!if_non_zero_entered) {
            if_non_zero_entered = true;
        }

    }

    return(hexa_str);
}

int main ()
{
    char* ch0 = convert_number_to_hexadecimal_str(0);
    assert(0 == strcmp(ch0, "0"));

    char* ch1 = convert_number_to_hexadecimal_str(15);
    assert(0 == strcmp(ch1, "f"));

    char* ch2 = convert_number_to_hexadecimal_str(16);
    assert(0 == strcmp(ch2, "10"));

    char* ch3 = convert_number_to_hexadecimal_str(-1);
    assert(0 == strcmp(ch3, "ffffffff"));

    char* ch4 = convert_number_to_hexadecimal_str(INT_MAX);
    assert(0 == strcmp(ch4, "7fffffff"));

    char* ch5 = convert_number_to_hexadecimal_str(INT_MIN);
    assert(0 == strcmp(ch5, "80000000"));

    char* ch6 = convert_number_to_hexadecimal_str(26);
    assert(0 == strcmp(ch6, "1a"));

    return(0);
}
