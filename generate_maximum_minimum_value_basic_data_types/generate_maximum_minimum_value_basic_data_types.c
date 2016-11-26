/*
 * This program generates maximum and minimum values for basic data types
 * like short, int, char and long using bitwise operators.
 */
#include<limits.h>
#include<stdio.h>
#include<assert.h>

/*
 * This function gets the maximum unsigned integer value which
 * is simply setting all the bits in unsigned integer.
 */
unsigned int get_unsigned_int_max ()
{
    unsigned int max = ~0;

    return(max);
}

/*
 * This function gets the minimum unsigned integer value which
 * is zero.
 */
unsigned int get_unsigned_int_min ()
{
    unsigned int min = 0;

    return(min);
}

/*
 * This function gets the maximum signed integer value which is
 * simply setting all the bits in signed integer except the signed
 * bit or MSB.
 */
int get_signed_int_max ()
{
    int max = ((int)1 << (sizeof(int) * CHAR_BIT - 1));

    return(~max);
}

/*
 * This function gets the minimum signed integer value which is
 * simply setting the signed bit that is the MSB of the integer.
 */
int get_signed_int_min ()
{
    int min = ((int)1 << (sizeof(int) * CHAR_BIT - 1));

    return(min);
}

/*
 * This function gets the maximum unsigned short value which
 * is simply setting all the bits in unsigned short.
 */
unsigned short get_unsigned_short_max ()
{
    unsigned short max = ~0;

    return(max);
}

/*
 * This function gets the minimum unsigned short value which
 * is zero.
 */
unsigned short get_unsigned_short_min ()
{
    unsigned short min = 0;

    return(min);
}

/*
 * This function gets the maximum signed short value which is
 * simply setting all the bits in signed short except the signed
 * bit or MSB.
 */
short get_signed_short_max ()
{
    short max = ((short)1 << (sizeof(short) * CHAR_BIT - 1));

    return(~max);
}

/*
 * This function gets the minimum signed short value which is
 * simply setting the signed bit that is the MSB of the short.
 */
short get_signed_short_min ()
{
    short min = ((short)1 << (sizeof(short) * CHAR_BIT - 1));

    return(min);
}

/*
 * This function gets the maximum unsigned char value which
 * is simply setting all the bits in unsigned char.
 */
unsigned char get_unsigned_char_max ()
{
    unsigned char max = ~0;

    return(max);
}

/*
 * This function gets the minimum unsigned char value which
 * is zero.
 */
unsigned char get_unsigned_char_min ()
{
    unsigned int min = 0;

    return(min);
}

/*
 * This function gets the maximum signed char value which is
 * simply setting all the bits in signed char except the signed
 * bit or MSB.
 */
char get_signed_char_max ()
{
    char max = ((char)1 << (sizeof(char) * CHAR_BIT - 1));

    return(~max);
}

/*
 * This function gets the minimum signed char value which is
 * simply setting the signed bit that is the MSB of the char.
 */
char get_signed_char_min ()
{
    char min = ((char)1 << (sizeof(char) * CHAR_BIT - 1));

    return(min);
}

/*
 * This function gets the maximum unsigned long value which
 * is simply setting all the bits in unsigned long.
 */
unsigned long get_unsigned_long_max ()
{
    unsigned long max = ~0;

    return(max);
}

/*
 * This function gets the minimum unsigned long value which
 * is zero.
 */
unsigned long get_unsigned_long_min ()
{
    unsigned long min = 0;

    return(min);
}

/*
 * This function gets the maximum signed long value which is
 * simply setting all the bits in signed long except the signed
 * bit or MSB.
 */
long get_signed_long_max ()
{
    long max = ((long)1 << (sizeof(long) * CHAR_BIT - 1));

    return(~max);
}

/*
 * This function gets the minimum signed long value which is
 * simply setting the signed bit that is the MSB of the long.
 */
long get_signed_long_min ()
{
    long min = ((long)1 << (sizeof(long) * CHAR_BIT - 1));

    return(min);
}

int main ()
{
    /*
     * Test 0: Test all unsigned minimum and maximum values against
     *         standard limit constants
     */
    assert(0 == get_unsigned_char_min());
    assert(UCHAR_MAX == get_unsigned_char_max());
    assert(0 == get_unsigned_short_min());
    assert(USHRT_MAX == get_unsigned_short_max());
    assert(0 == get_unsigned_int_min());
    assert(UINT_MAX == get_unsigned_int_max());
    assert(0 == get_unsigned_long_min());
    assert(ULONG_MAX == get_unsigned_long_max());

    /*
     * Test 1: Test all signed minimum and maximum values against
     *         standard limit constants
     */
    assert(CHAR_MIN == get_signed_char_min());
    assert(CHAR_MAX == get_signed_char_max());
    assert(SHRT_MIN == get_signed_short_min());
    assert(SHRT_MAX == get_signed_short_max());
    assert(INT_MIN == get_signed_int_min());
    assert(INT_MAX == get_signed_int_max());
    assert(LONG_MIN == get_signed_long_min());
    assert(LONG_MAX == get_signed_long_max());

    return(0);
}
