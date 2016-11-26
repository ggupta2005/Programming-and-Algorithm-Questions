/*
 * This program generates maximum and minimum values for basic data types
 * like short, int, char and long using bitwise operators.
 */
import java.io.*;
import java.util.*;

public class generate_maximum_minimum_value_basic_data_types
{
    /*
     * This function gets the maximum signed integer value which is
     * simply setting all the bits in signed integer except the signed
     * bit or MSB. Integer is 32 bits in java.
     */
    public static int get_signed_int_max ()
    {
        int max = (1 << (32 - 1));

        return(~max);
    }

    /*
     * This function gets the minimum signed integer value which is
     * simply setting the signed bit that is the MSB of the integer.
     * Integer is 32 bits in java.
     */
    public static int get_signed_int_min ()
    {
        int min = (1 << (32 - 1));

        return(min);
    }

    /*
     * This function gets the maximum signed short value which is
     * simply setting all the bits in signed short except the signed
     * bit or MSB. Short is 16 bits in java.
     */
    public static short get_signed_short_max ()
    {
        /*
         * Here we typecast the left shift result to 'short' because
         * by default '1' is integer here.
         */
        short max = ~((short)(1 << (16 - 1)));

        return(max);
    }

    /*
     * This function gets the minimum signed short value which is
     * simply setting the signed bit that is the MSB of the short.
     * Short is 16 bits in java.
     */
    public static short get_signed_short_min ()
    {
        /*
         * Here we typecast the left shift result to 'short' because
         * by default '1' is integer here.
         */
        short min = (short)(1 << (16 - 1));

        return(min);
    }

    /*
     * This function gets the maximum signed byte value which is
     * simply setting all the bits in signed byte except the signed
     * bit or MSB. Byte is 8 bits in java.
     */
    public static byte get_signed_byte_max ()
    {
        /*
         * Here we typecast the left shift result to 'byte' because
         * by default '1' is integer here.
         */
        byte max = ~((byte)(1 << (8 - 1)));

        return(max);
    }

    /*
     * This function gets the minimum signed byte value which is
     * simply setting the signed bit that is the MSB of the byte.
     * Byte is 8 bits in java.
     */
    public static byte get_signed_byte_min ()
    {
        /*
         * Here we typecast the left shift result to 'byte' because
         * by default '1' is integer here.
         */
        byte min = (byte)(1 << (8 - 1));

        return(min);
    }

    /*
     * This function gets the maximum signed long value which is
     * simply setting all the bits in signed long except the signed
     * bit or MSB. Long is 64 bits in java.
     */
    public static long get_signed_long_max ()
    {
        /*
         * Here we typecast '1' to 'long' because by default
         * '1' is integer here and left shift by 63 fails during
         * compile time if we do not typecast to 'long'.
         */
        long max = (long)1 << (64 - 1);

        return(~max);
    }

    /*
     * This function gets the minimum signed long value which is
     * simply setting the signed bit that is the MSB of the long.
     * Long is 64 bits in java.
     */
    public static long get_signed_long_min ()
    {
        /*
         * Here we typecast '1' to 'long' because by default
         * '1' is integer here and left shift by 63 fails during
         * compile time if we do not typecast to 'long'.
         */
        long min = (long)1 << (64 - 1);

        return(min);
    }

    public static void main (String[] args)
    {
        /*
         * Test 1: Test all signed minimum and maximum values against
         *         standard limit constants
         */
        assert(Byte.MIN_VALUE == get_signed_byte_min());
        assert(Byte.MAX_VALUE == get_signed_byte_max());
        assert(Short.MIN_VALUE == get_signed_short_min());
        assert(Short.MAX_VALUE == get_signed_short_max());
        assert(Integer.MIN_VALUE == get_signed_int_min());
        assert(Integer.MAX_VALUE == get_signed_int_max());
        assert(Long.MIN_VALUE == get_signed_long_min());
        assert(Long.MAX_VALUE == get_signed_long_max());
    }
}
