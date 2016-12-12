/*
 * This program finds the longest common prefix string for an array or list
 * of strings. For more iformation on the problem, please refer to the
 * following link:- http://www.geeksforgeeks.org/longest-common-prefix-set-1-word-by-word-matching/
 */
import java.io.*;
import java.util.*;

public class find_longest_common_prefix_for_array_of_strings
{
    /*
     * This function returns the longest common prefix string for the list of
     * string. If this is no common prefix string, then this function returns
     * null. The time complexity of this function is O(m * n), where 'm' is the
     * number of string and 'n' is the maximum length of the string in this
     * list of strings. The space complexity of this function is O(p), where
     * 'p' is the length of the shortest length of the string in this list of
     * strings.
     */
    public static String longestCommonPrefix(String[] strs)
    {

        int index, len;
        int min_len, common_prefix_index;
        char[] common_prefix = null;

        /*
         * If the array of string is empty or its length is
         * invalid, then return null as the longest common
         * prefix
         */
        if ((strs == null) || (strs.length <= 0)) {
            return(null);
        }

        len = strs.length;

        /*
         * Find the minimum length of a string among the list
         * of strings
         */
        min_len = Integer.MAX_VALUE;
        for (index = 0; index < len; ++index) {
            if (strs[index] == null) {
                min_len = 0;
            } else {
                if (min_len > strs[index].length()) {
                    min_len = strs[index].length();
                }
            }
        }

        /*
         * If the minimum length of the string is found to be zero,
         * then return null
         */
        if (min_len == 0) {
            return(null);
        }

        /*
         * Allocate a string which can store 'min_len' characters
         */
        common_prefix = new char[min_len];

        /*
         * If the memory alloation fails, then return null
         */
        if (common_prefix == null) {
            return(null);
        }

        /*
         * Iterate over the number of characters in the smallest
         * string among the list of strings
         */
        for (common_prefix_index = 0; common_prefix_index < min_len;
             ++common_prefix_index) {

            /*
             * Iterate over all the strings to check if the character
             * at index position 'common_prefix_index' is same in all
             * the strings
             */
            for (index = 1; index < len; ++index) {

                if (strs[index - 1].charAt(common_prefix_index) !=
                    strs[index].charAt(common_prefix_index)) {
                        break;
                }
            }

            if (index < len) {

                /*
                 * If the character at at index position is not same in all
                 * the strings, then we have found the longest common prefix.
                 * Break from the loop.
                 */
                break;
            } else {

                /*
                 * Otherwise set the common character in the longest common
                 * prefix string
                 */
                common_prefix[common_prefix_index] =
                            strs[0].charAt(common_prefix_index);
            }
        }

        if (common_prefix_index == 0) {

            /*
             * If there were no common prefix characers found in the string
             * then return null
             */
            return(null);
        }

        /*
         * Return the longest common prefix string
         */
        return(new String(common_prefix, 0, common_prefix_index));
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test when the list of strings is empty. The longest
         *         common prefix string should be null.
         */
        String[] list0 = {};
        assert(null == longestCommonPrefix(list0));

        /*
         * Test 1: Test the case when there is only one string in the
         *         list of strings. The longest common prefix string should
         *         be the only string itself.
         */
        String[] list1 = {"abc"};
        assert("abc".equals(longestCommonPrefix(list1)));

        /*
         * Test 2: Test the case when there are multiple string and there
         *         exists a longest common prefix string. The longest common
         *         prefix string returned should be non-null.
         */
        String[] list2 = {"abc", "abcd", "abef", "abdc"};
        assert("ab".equals(longestCommonPrefix(list2)));

        /*
         * Test 3: Test the case when there are multiple string and there
         *         doesn't exist a longest common prefix string. The longest
         *         common prefix string returned should be null.
         */
        String[] list3 = {"bc", "bcd", "abef", "abdc"};
        assert(null == longestCommonPrefix(list3));

        /*
         * Test 4: Test the case when there are multiple string all the strings
         *         are same. The longest common prefix string returned should
         *         be non-null and equal to one of the strings.
         */
        String[] list4 = {"abcd", "abcd", "abcd", "abcd", "abcd", "abcd"};
        assert("abcd".equals(longestCommonPrefix(list4)));

        /*
         * Test 5: Test the case when there are multiple string and there
         *         exist a null string among these list of strings. The
         *         longest common prefix string returned should be null.
         */
        String[] list5 = {"bc", null, "abef", "abdc"};
        assert(null == longestCommonPrefix(list5));

        /*
         * Test 6: Test the case when there are multiple string and there
         *         exist an empty string among these list of strings. The
         *         longest common prefix string returned should be null.
         */
        String[] list6 = {"bc", "", "abef", "abdc"};
        assert(null == longestCommonPrefix(list6));
    }
}
