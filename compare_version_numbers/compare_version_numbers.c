/*
 * This program compares two version numbers in the decimal form. For more
 * information on the problem, please refer to the following link:-
 * https://leetcode.com/problems/compare-version-numbers/
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int compare_num_as_string (char* num1, char* num2)
{
    int len1, len2;
    int index1, index2;

    len1 = strlen(num1);
    len2 = strlen(num2);

    if (len1 > len2) {
        return(1);
    }

    if (len2 > len1) {
        return(-1);
    }

    index1 = 0;
    index2 = 0;
    while ((index1 < len1) && (index2 < len2)) {
        if (num1[index1] > num2[index2]) {
            return(1);
        }

        if (num2[index2] > num1[index1]) {
            return(-1);
        }

        ++index1;
        ++index2;
    }

    return(0);
}

int compare_version_num_as_string (char* num1, char* num2)
{
    char* dec1;
    char* dec2;
    char* fra1;
    char* fra2;
    int result;

    /*
     * Tokenize the entire first string so that the decimal
     * and fractional parts of the version are obtained.
     */
    dec1 = strtok(num1, ".");
    fra1 = strtok(NULL, ".");

    /*
     * Tokenize the entire second string so that the decimal
     * and fractional parts of the version are obtained.
     */
    dec2 = strtok(num2, ".");
    fra2 = strtok(NULL, ".");

    result = compare_num_as_string(dec1, dec2);
    if (result != 0) {
        return(result);
    }

    result = compare_num_as_string(fra1, fra2);

    return(result);
}

int main ()
{
    char ver10[] = "0.1";
    char ver20[] = "1.1";
    assert(-1 == compare_version_num_as_string(ver10, ver20));

    char ver11[] = "1.1";
    char ver21[] = "0.1";
    assert(1 == compare_version_num_as_string(ver11, ver21));

    char ver12[] = "1.1";
    char ver22[] = "1.1";
    assert(0 == compare_version_num_as_string(ver12, ver22));

    char ver13[] = "1.0";
    char ver23[] = "1.1";
    assert(-1 == compare_version_num_as_string(ver13, ver23));

    char ver14[] = "1.1";
    char ver24[] = "1.0";
    assert(1 == compare_version_num_as_string(ver14, ver24));

    char ver15[] = "123.0";
    char ver25[] = "1.0";
    assert(1 == compare_version_num_as_string(ver15, ver25));

    char ver16[] = "1.0";
    char ver26[] = "123.0";
    assert(-1 == compare_version_num_as_string(ver16, ver26));

    char ver17[] = "1.0";
    char ver27[] = "123.0";
    assert(-1 == compare_version_num_as_string(ver17, ver27));
    return(0);
}
