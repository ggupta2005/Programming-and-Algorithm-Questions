/*
 * This program inserts lowercase case alphabets in a trie and searches for
 * the words or prefixes in the trie.
 */
import java.io.*;
import java.util.*;

class trienode
{
    /*
     * Constant for the number of lowercase characters
     */
    public static final int NUMBER_LOWERCASE = 26;

    /*
     * Flag for checking if the trie node is the
     * end of the word
     */
    boolean is_word_end;

    /*
     * Array of references storing references to the
     * child nodes in the trie
     */
    trienode[] links;

    /*
     * Constructor for trie node class
     */
    trienode ()
    {
        is_word_end = false;

        /*
         * Allocate the number of links in the trie for all the
         * lowercase characters
         */
        links = new trienode[NUMBER_LOWERCASE];

        for (int index = 0; index < NUMBER_LOWERCASE; ++index) {
            links[index] = null;
        }
    }
}

public class trie_insert_and_search
{
    /*
     * Root of the trie
     */
    trienode root;

    trie_insert_and_search ()
    {
        root = new trienode();
    }

    /*
     * This function inserts a character string in the trie data structure.
     * If the character string is not valid or the characters in the string
     * are not lowercase alphabetical characters, then this function does
     * not add the character string in the trie. The time complexity of this
     * function is O(n), where 'n' is the number of characters in the string.
     * The space complexity of this string is O(1).
     */
    void insert_word_in_trie (String ch)
    {
        int index, len;
        int index_char;
        trienode current;

        /*
         * If the root of the trie is not valid or the character
         * string is not valid, then return from the function
         */
        if ((root == null) || (ch == null) || (ch.length() == 0)) {
            return;
        }

        len = ch.length();

        /*
         * Check if each character of the string is a lowercase
         * alphabetical character
         */
        for (index = 0; index < len; ++index) {

            /*
             * If the character is not lowercase alphabet, then
             * do not the string in the trie
             */
            if (((int)ch.charAt(index) < (int)'a') ||
                 ((int)ch.charAt(index) > (int)'z')) {
                return;
            }
        }

        /*
         * Start at the root of the digital trie and add the
         * character string in the trie
         */
        current = root;
        for (index = 0; index < len; ++index) {

            /*
             * Get the index of the child node of the
             * character
             */
            index_char = (int)ch.charAt(index) - (int)'a';

            /*
             * If the child node is NULL, then allocate a new node
             * and add the new node into the trie
             */
            if (current.links[index_char] == null) {
                current.links[index_char] = new trienode();
            }

            /*
             * Move to the child node according to the character
             */
            current = current.links[index_char];
        }

        /*
         * Set the word end flag to 'true'
         */
        current.is_word_end = true;
    }

    /*
     * This function returns 'true' if the given word is found in the
     * trie and 'false' otherwise. The time complexity of this function
     * is O(n), where 'n' is the number of characters in the string. The
     * space complexity of this string is O(1).
     */
    boolean search_word_in_trie (String ch)
    {
        int index, len;
        int index_char;
        trienode current;

        /*
         * If the root of trie is NULL or if the word is NULL or
         * empty, then return 'false'
         */
        if ((root == null) || (ch == null) || (ch.length() == 0)) {
            return(false);
        }

        len = ch.length();

        /*
         * Start at the root of the tree and search down in the trie
         * for the word
         */
        current = root;
        for (index = 0; index < len; ++index) {

            /*
             * If current character is not lowercase alphabet, then
             * return 'false'
             */
            if (((int)ch.charAt(index) < (int)'a') ||
                 ((int)ch.charAt(index) > (int)'z')) {
                return(false);
            }

            /*
             * Get the index of the child node
             */
            index_char = (int)ch.charAt(index) - (int)'a';

            /*
             * If the child node is NULL, then the current
             * character does not exist in the trie, so return
             * 'false'
             */
            if (current.links[index_char] == null) {
                return(false);
            }

            /*
             * Move to the ch.charAt(index)ld node
             */
            current = current.links[index_char];
        }

        /*
         * Return the status of the trie node if the node
         * is the word
         */
        return(current.is_word_end);
    }

    /*
     * This function returns 'true' if the given prefix is found in the
     * trie and 'false' otherwise. The time complexity of this function
     * is O(n), where 'n' is the number of characters in the string. The
     * space complexity of this string is O(1).
     */
    boolean search_prefix_in_trie (String ch)
    {
        int index, len;
        int index_char;
        trienode current;

        /*
         * If the root of trie is NULL or if the prefix is NULL or
         * empty, then return 'false'
         */
        if ((root == null) || (ch == null) || (ch.length() == 0)) {
            return(false);
        }

        len = ch.length();

        /*
         * Start at the root of the tree and search down in the trie
         * for the prefix
         */
        current = root;
        for (index = 0; index < len; ++index) {

            /*
             * If current character is not lowercase alphabet, then
             * return 'false'
             */
            if (((int)ch.charAt(index) < (int)'a') ||
                 ((int)ch.charAt(index) > (int)'z')) {
                return(false);
            }

            /*
             * Get the index of the child node
             */
            index_char = (int)ch.charAt(index) - (int)'a';

            /*
             * If the child node is NULL, then the current
             * character does not exist in the trie, so return
             * 'false'
             */
            if (current.links[index_char] == null) {
                return(false);
            }

            /*
             * Move to the child node
             */
            current = current.links[index_char];
        }

        /*
         * Return 'true' since the prefix is found in the trie
         */
        return(true);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test adding some strings into the trie and test the
         *         following cases:-
         *         1. Test insertion
         *           - Add lowercase strings into the trie. They should
         *             get added.
         *           - Add strings having a mix of uppercase and lowercase
         *             into the trie. They should not get added.
         *           - Add strings having a mix of digits and lowercase
         *             into the trie. They should not get added.
         *         2. Test word search
         *           - Test the search of some of the strings that we added
         *             in insertion. The strings having only lowercase
         *             characters should be found in the trie.
         *           - Test the search of some of the strings that we did not
         *             add in insertion. These strings should not be found
         *             in the trie.
         *           - Test the search of some prefix of some string that we
         *             added in insertion. These prefixes should not be found
         *             as a word in the trie.
         *         3. Test prefix search
         *           - Test the search of some prefix of the strings that we
         *             added in insertion. The prefixes having only lowercase
         *             characters should be found in the trie.
         *           - Test the search of some prefix of the strings that we
         *             did not add in insertion. These prefixes should not be
         *             found in the trie.
         */
        String[] strings0 =
                    {
                        "the",
                        "their",
                        "these",
                        "algo",
                        "a",
                        "an",
                        "another",
                        "pool",
                        "pooling",
                        "car",
                        "cared",
                        "Cared",
                        "987cared"
                    };
        trie_insert_and_search trie0 = new trie_insert_and_search();
        for (int index0 = 0; index0 < strings0.length;
             ++index0) {
            trie0.insert_word_in_trie(strings0[index0]);
        }
        assert(true == trie0.search_word_in_trie("the"));
        assert(true == trie0.search_word_in_trie("a"));
        assert(true == trie0.search_word_in_trie("pool"));
        assert(false == trie0.search_word_in_trie("poo"));
        assert(false == trie0.search_word_in_trie("pooled"));
        assert(false == trie0.search_word_in_trie("fool"));
        assert(false == trie0.search_word_in_trie("poolings"));
        assert(false == trie0.search_word_in_trie("Cared"));
        assert(false == trie0.search_word_in_trie("987cared"));

        assert(true == trie0.search_prefix_in_trie("the"));
        assert(true == trie0.search_prefix_in_trie("a"));
        assert(true == trie0.search_prefix_in_trie("pool"));
        assert(true == trie0.search_prefix_in_trie("poo"));
        assert(false == trie0.search_prefix_in_trie("pooled"));
        assert(false == trie0.search_prefix_in_trie("fool"));
        assert(false == trie0.search_prefix_in_trie("poolings"));
        assert(false == trie0.search_prefix_in_trie("Cared"));
        assert(false == trie0.search_prefix_in_trie("987cared"));
    }
}
