/*
 * This program finds the maximum xor of two numbers in an array of
 * integers.
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>

int find_max_xor_two_numbers_in_array_v1 (int* array, int len)
{
    int index, inner_index;
    int max_xor;

    if (!array || (len <= 1)) {
        return(0);
    }

    max_xor = 0;
    for (index = 0; index < (len - 1); ++index) {

        for (inner_index = index + 1; inner_index < len; ++inner_index) {

            if ((array[index] ^ array[inner_index]) > max_xor) {
                max_xor = array[index] ^ array[inner_index];
            }
        }
    }

    return(max_xor);
}

#define MAX_TRIE_LINKS 2

struct trienode {
    struct trienode* links[MAX_TRIE_LINKS];
};

struct trienode* make_trienode ()
{
    struct trienode* new_node;
    int index;

    new_node = (struct trienode*)malloc(sizeof(struct trienode));

    if (!new_node) {
        return(NULL);
    }

    for (index = 0; index < MAX_TRIE_LINKS; ++index) {
        new_node->links[index] = NULL;
    }

    return(new_node);
}

void init_trie (struct trienode** root)
{
    if (!root) {
        return;
    }

    *root = make_trienode();
}

void insert_into_trie (struct trienode* root, int num)
{
    int index, link;
    struct trienode* current;

    if (!root || (num < 0)) {
        return;
    }

    current = root;
    for (index = sizeof(int) * CHAR_BIT - 1; index >= 0; --index) {
        if (num & (1 << index)) {
            link = 1;
        } else {
            link = 0;
        }

        if (!current->links[link]) {
            current->links[link] = make_trienode();
        }

        current = current->links[link];
    }
}

void free_trie (struct trienode* root)
{
#if 0
    struct trienode* zero;
    struct trienode* one;
    int index;

    if (!root || *root) {
        return;
    }

    //for (index = 0; index <
    free_trie(*root->link[0]);
#endif
}

int find_max_xor_two_numbers_in_array_v2 (int* array, int len)
{
    int index, bit_index, max_xor, num_max_xor, link;
    struct trienode* root = NULL;
    struct trienode* current;

    if (!array || (len <= 1)) {
        return(0);
    }

    init_trie(&root);

    if (!root) {
        return(0);
    }

    for (index = 0; index < len; ++index) {
        insert_into_trie(root, array[index]);
    }

    max_xor = 0;
    for (index = 0; index < len; ++index) {

        current = root;
        num_max_xor = array[index];

        for (bit_index = sizeof(int) * CHAR_BIT - 1;
             bit_index >= 0; --bit_index) {

            if (array[index] & (1 << bit_index)) {
                link = 1;
            } else {
                link = 0;
            }

            if (link == 0) {
                if (!current->links[1]) {
                    num_max_xor &= ~(1 << bit_index);
                    current = current->links[0];
                } else {
                    num_max_xor |= (1 << bit_index);
                    current = current->links[1];
                }
            } else {
                if (!current->links[0]) {
                    num_max_xor &= ~(1 << bit_index);
                    current = current->links[1];
                } else {
                    num_max_xor |= (1 << bit_index);
                    current = current->links[0];
                }
            }
        }

        if (num_max_xor > max_xor) {
            max_xor = num_max_xor;
        }
    }

    free_trie(root);

    return(max_xor);
}

int main ()
{
    int* array0 = NULL;
    int len0 = 10;
    assert(0 == find_max_xor_two_numbers_in_array_v1(array0, len0));
    assert(0 == find_max_xor_two_numbers_in_array_v2(array0, len0));

    int array1[] = {1,2,3};
    int len1 = 1;
    assert(0 == find_max_xor_two_numbers_in_array_v1(array1, len1));
    assert(0 == find_max_xor_two_numbers_in_array_v2(array1, len1));

    int array2[] = {2,7};
    int len2 = sizeof(array2)/sizeof(int);
    assert(5 == find_max_xor_two_numbers_in_array_v1(array2, len2));
    assert(5 == find_max_xor_two_numbers_in_array_v2(array2, len2));

    int array3[] = {2,2,2};
    int len3 = sizeof(array3)/sizeof(int);
    assert(0 == find_max_xor_two_numbers_in_array_v1(array3, len3));
    assert(0 == find_max_xor_two_numbers_in_array_v2(array3, len3));

    int array4[] = {1,2,3};
    int len4 = sizeof(array4)/sizeof(int);
    assert(3 == find_max_xor_two_numbers_in_array_v1(array4, len4));
    assert(3 == find_max_xor_two_numbers_in_array_v2(array4, len4));

    return(0);
}
