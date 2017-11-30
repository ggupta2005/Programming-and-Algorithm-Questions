/*
 * This program checks if the IPv4 address string is a valid IPv4
 * address.
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>

bool if_char_is_digit (char ch)
{
    if ((ch >= '0') && (ch <= '9')) {
        return(true);
    }

    return(false);
}

bool validate_byte_for_ipv4_address (char* str)
{
    int len, index, byte_value;

    if (!str || !strlen(str)) {
        return(false);
    }

    len = strlen(str);

    index = 0;
    byte_value = 0;
    while (index < len) {

        if (if_char_is_digit(str[index])) {
            byte_value = byte_value * 10 + (str[index] - '0');
        } else {
            return(false);
        }

        ++index;
    }

    return((byte_value >= 0) && (byte_value <= 255));
}

bool if_ipv4_address_str_is_valid (char* str)
{
    char* byte_ptr, num_bytes;

    if (!str || !strlen(str)) {
        return(false);
    }

    byte_ptr = strtok(str , ".");

    if (!byte_ptr) {
        return(false);
    }

    num_bytes = 0;
    while (byte_ptr) {

        if (!validate_byte_for_ipv4_address(byte_ptr)) {
            return(false);
        }

        ++num_bytes;

        if (num_bytes > 4) {
            return(false);
        }

        byte_ptr = strtok(NULL, ".");
    }

    if (num_bytes < 4) {
        return(false);
    }

    return(true);
}

int main ()
{
    char ip0[] = "123.0.0.1";
    assert(true == if_ipv4_address_str_is_valid(ip0));

    char ip1[] = "123.0.0.256";
    assert(false == if_ipv4_address_str_is_valid(ip1));

    char ip2[] = "123.0.0";
    assert(false == if_ipv4_address_str_is_valid(ip2));

    char ip3[] = "123.0.0";
    assert(false == if_ipv4_address_str_is_valid(ip3));

    char ip4[] = "123.0.0.1.100";
    assert(false == if_ipv4_address_str_is_valid(ip4));

    char ip5[] = "123.a.a.a1";
    assert(false == if_ipv4_address_str_is_valid(ip5));

    char ip6[] = "255.255.255.255";
    assert(true == if_ipv4_address_str_is_valid(ip6));

    char ip7[] = "0.0.0.0";
    assert(true == if_ipv4_address_str_is_valid(ip7));

    return(0);
}
