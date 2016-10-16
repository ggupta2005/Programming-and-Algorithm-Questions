/*
 * Write a program that outputs the string representation of numbers
 * from 1 to n.
 *
 * But for multiples of three it should output “Fizz” instead of the
 * number and for the multiples of five output “Buzz”. For numbers which
 * are multiples of both three and five output “FizzBuzz”.
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>

#define MAX_SIZE 20
#define THREE    3
#define FIVE     5
#define FIZZ     "Fizz"
#define BUZZ     "Buzz"

/*
 * This function returns an array of strings which contains the numbers as is or
 * the multiples of three or five are replaced by "fizz" or "Buzz". The numbers
 * which are multiples of both 3 and 5 are replaced by "FizzBuzz". If the input
 * number is less than or equal to zero, then this function returns NULL.
 */
char** fizz_buzz (int n)
{
    char** array;
    int index, inner_index;

    /*
     * If 'n' is less than or equal to zero, then return NULL
     */
    if (n <= 0) {
        return(NULL);
    }

    /*
     * Allocate an array of character pointers
     */
    array = (char**)malloc(sizeof(char*) * n);

    /*
     * If the array allocation fails, then return NULL
     */
    if (!array) {
        return(NULL);
    }

    /*
     * Allocate memory for each character array pointer
     */
    for (index = 0; index < n; ++index) {

        array[index] = (char*)malloc(sizeof(char) * MAX_SIZE);

        /*
         * If the memory allocation fails for a character pointer,
         * then free the previously allocated memory and return NULL
         */
        if (!array[index]) {
            for (inner_index = 0; inner_index < index; ++inner_index) {
                free(array[inner_index]);
            }

            return(NULL);
        }
    }

    /*
     * Iterate from one to 'n' and fill the required value in the
     * character array.
     */
    for (index = 1; index <= n; ++index) {

        /*
         * 1. If 'index' is a multiple of both 3 and 5, then fill
         *    "FizzBuzz" in character array.
         * 2. If 'index' is a multiple of both 3, then fill
         *    "Fizz" in character array.
         * 3. If 'index' is a multiple of both 5, then fill
         *    "Buzz" in character array.
         * 4. If 'index' is not a multiple of both 3 and 5, then fill
         *    number string in character array.
         */
        if ((index % (THREE * FIVE)) == 0) {
            snprintf(array[index-1], MAX_SIZE, "%s%s", FIZZ, BUZZ);
        } else if ((index % THREE) == 0) {
            snprintf(array[index-1], MAX_SIZE, "%s", FIZZ);
        } else if ((index % FIVE) == 0) {
            snprintf(array[index-1], MAX_SIZE, "%s", BUZZ);
        } else {
            snprintf(array[index-1], MAX_SIZE, "%d", index);
        }
    }

    /*
     * Return the character array
     */
    return(array);
}

/*
 * This function checks if all the character array entries in the
 * two arrays are equal. This function returns 'true' if the entriesg
 * are equal and false otherwise.
 */
bool if_array_of_string_is_equal (char** array1, int len1,
                                  char** array2, int len2)
{
    int i;

    /*
     * If lengths of the two character arrays is not legal or they
     * are not equal, then return 'false'.
     */
    if ((len1 <= 0) || (len2 <= 0) || (len1 != len2)) {
        return(false);
    }

    /*
     * Iterate over all the array entriesg
     */
    for (i = 0; i < len1; ++i) {

        /*
         * If the two strings are not equal, then return 'false'
         */
        if (strcmp(array1[i], array2[i])) {
            return(false);
        }
    }

    /*
     * Since both character array entries are equal, so return 'true'
     */
    return(true);
}

int main ()
{
    /*
     * Test 1: Test with 'n' as 15.
     */
    int n1 = 15;
    char** actual_array1 = fizz_buzz(n1);
    char* expected_array1[] =
                    {
                        "1",
                        "2",
                        "Fizz",
                        "4",
                        "Buzz",
                        "Fizz",
                        "7",
                        "8",
                        "Fizz",
                        "Buzz",
                        "11",
                        "Fizz",
                        "13",
                        "14",
                        "FizzBuzz"
                    };
    assert(true == if_array_of_string_is_equal(actual_array1, n1,
                                               expected_array1, n1));

    /*
     * Test 2: Test with 'n' as 0.
     */
    int n2 = 0;
    char** actual_array2 = fizz_buzz(n2);
    char** expected_array2 = NULL;
    assert(actual_array2 == expected_array2);

    /*
     * Test 3: Test with 'n' as less than zero.
     */
    int n3 = -10;
    char** actual_array3 = fizz_buzz(n3);
    char** expected_array3 = NULL;
    assert(actual_array3 == expected_array3);

    return(0);
}
