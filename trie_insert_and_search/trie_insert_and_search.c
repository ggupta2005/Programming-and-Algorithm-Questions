/*
 * This program inserts lowercase case alphabets in a trie and searches for
 * the words or prefixes in the trie. For more information on trie and its
 * implementation, please refer to the following link:-
 * http://www.geeksforgeeks.org/trie-insert-and-search/
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>

/*
 * Macro for getting the number of lowercase alphabets
 */
#define MAX_SYMBOL_SIZE(s1, s2) s2 - s1 + 1

/*
 * Structure definition of the trie node
 */
struct trienode {

    /*
     * Flag for checking if the trie node is the
     * end of the word
     */
    bool is_word_end;

    /*
     * Array of pointers storing references to the
     * child nodes in the trie
     */
    struct trienode* links[MAX_SYMBOL_SIZE('a', 'z')];
};

/*
 * This function returns the pointer reference for the newly allocated
 * trie node and set the data members of the trie node to default values.
 * If the memory allocation fails, then this function returns NULL.
 */
struct trienode* make_trienode ()
{
    struct trienode* new_node;
    int index;

    /*
     * Allocate a new trie node
     */
    new_node = (struct trienode*)malloc(sizeof(struct trienode));

    /*
     * If the memory allocation fails, then return NULL
     */
    if (!new_node) {
        return(NULL);
    }

    /*
     * Assign default values to the trie node data members
     */
    new_node->is_word_end = false;

    for (index = 0; index < MAX_SYMBOL_SIZE('a', 'z'); ++index) {
        new_node->links[index] = NULL;
    }

    /*
     * Return the pointer reference for the allocated node
     */
    return(new_node);
}

/*
 * This function intializes the root node of the trie.
 */
void init_trie_root (struct trienode** root)
{
    /*
     * If the reference to the trie root is NULL, then
     * return
     */
    if (!root) {
        return;
    }

    /*
     * Allocate a new node for this root reference
     */
    *root = make_trienode();
}

/*
 * This function inserts a character string in the trie data structure.
 * If the character string is not valid or the characters in the string
 * are not lowercase alphabetical characters, then this function does
 * not add the character string in the trie. The time complexity of this
 * function is O(n), where 'n' is the number of characters in the string.
 * The space complexity of this string is O(1).
 */
void insert_word_in_trie (struct trienode* root, char* ch)
{
    int index, len;
    int index_char;
    struct trienode* current;

    /*
     * If the root of the trie is not valid or the character
     * string is not valid, then return from the function
     */
    if (!root || !ch || !strlen(ch)) {
        return;
    }

    len = strlen(ch);

    /*
     * Check if each character of the string is a lowercase
     * alphabetical character
     */
    for (index = 0; index < len; ++index) {

        /*
         * If the character is not lowercase alphabet, then
         * do not the string in the trie
         */
        if ((ch[index] < 'a') || (ch[index] > 'z')) {
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
        index_char = ch[index] - 'a';

        /*
         * If the child node is NULL, then allocate a new node
         * and add the new node into the trie
         */
        if (!(current->links[index_char])) {
            current->links[index_char] = make_trienode();
        }

        /*
         * Move to the child node according to the character
         */
        current = current->links[index_char];
    }

    /*
     * Set the word end flag to 'true'
     */
    current->is_word_end = true;
}

/*
 * This function returns 'true' if the given word is found in the
 * trie and 'false' otherwise. The time complexity of this function
 * is O(n), where 'n' is the number of characters in the string. The
 * space complexity of this string is O(1).
 */
bool search_word_in_trie (struct trienode* root, char* ch)
{
    int index, len;
    int index_char;
    struct trienode* current;

    /*
     * If the root of trie is NULL or if the word is NULL or
     * empty, then return 'false'
     */
    if (!root || !ch || !strlen(ch)) {
        return(false);
    }

    len = strlen(ch);

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
        if ((ch[index] < 'a') || (ch[index] > 'z')) {
            return(false);
        }

        /*
         * Get the index of the child node
         */
        index_char = ch[index] - 'a';

        /*
         * If the child node is NULL, then the current
         * character does not exist in the trie, so return
         * 'false'
         */
        if (!(current->links[index_char])) {
            return(false);
        }

        /*
         * Move to the child node
         */
        current = current->links[index_char];
    }

    /*
     * Return the status of the trie node if the node
     * is the word
     */
    return(current->is_word_end);
}

/*
 * This function returns 'true' if the given prefix is found in the
 * trie and 'false' otherwise. The time complexity of this function
 * is O(n), where 'n' is the number of characters in the string. The
 * space complexity of this string is O(1).
 */
bool search_prefix_in_trie (struct trienode* root, char* ch)
{
    int index, len;
    int index_char;
    struct trienode* current;

    /*
     * If the root of trie is NULL or if the prefix is NULL or
     * empty, then return 'false'
     */
    if (!root || !ch || !strlen(ch)) {
        return(false);
    }

    len = strlen(ch);

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
        if ((ch[index] < 'a') || (ch[index] > 'z')) {
            return(false);
        }

        /*
         * Get the index of the child node
         */
        index_char = ch[index] - 'a';

        /*
         * If the child node is NULL, then the current
         * character does not exist in the trie, so return
         * 'false'
         */
        if (!(current->links[index_char])) {
            return(false);
        }

        /*
         * Move to the child node
         */
        current = current->links[index_char];
    }

    /*
     * Return 'true' since the prefix is found in the trie
     */
    return(true);
}

int main ()
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
    char* strings0[] =
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
    struct trienode* root0 = NULL;
    int index0;
    init_trie_root(&root0);
    for (index0 = 0; index0 < sizeof(strings0)/sizeof(char*);
         ++index0) {
        insert_word_in_trie(root0, strings0[index0]);
    }
    assert(true == search_word_in_trie(root0, "the"));
    assert(true == search_word_in_trie(root0, "a"));
    assert(true == search_word_in_trie(root0, "pool"));
    assert(false == search_word_in_trie(root0, "poo"));
    assert(false == search_word_in_trie(root0, "pooled"));
    assert(false == search_word_in_trie(root0, "fool"));
    assert(false == search_word_in_trie(root0, "poolings"));
    assert(false == search_word_in_trie(root0, "Cared"));
    assert(false == search_word_in_trie(root0, "987cared"));

    assert(true == search_prefix_in_trie(root0, "the"));
    assert(true == search_prefix_in_trie(root0, "a"));
    assert(true == search_prefix_in_trie(root0, "pool"));
    assert(true == search_prefix_in_trie(root0, "poo"));
    assert(false == search_prefix_in_trie(root0, "pooled"));
    assert(false == search_prefix_in_trie(root0, "fool"));
    assert(false == search_prefix_in_trie(root0, "poolings"));
    assert(false == search_prefix_in_trie(root0, "Cared"));
    assert(false == search_prefix_in_trie(root0, "987cared"));

    return(0);
}
