/*
 * This program checks if the an array of integers contains a pair of
 * integers with a given sum. For more information on the post, please
 * refer to the following link:-
 * http://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-
 * numbers-and-another-number-x-determines-whether-or-not-there-exist-two-
 * elements-in-s-whose-sum-is-exactly-x/
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

/*
 * This function partitions the array around a 'pivot' element and returns the
 * index of the pivot element. This function uses the element at index 'high'
 * as the pivot.
 */
int partition (int* array, int low, int high)
{
    int temp, pindex, i, pivot;

    /*
     * Set 'pivot' as the element at index 'high' in the array
     */
    pivot = array[high];

    pindex = low;
    for (i = low; i < high; ++i) {

        /*
         * If the array elemnt is less than pivot element
         * then move the element to the left of the pivot
         */
        if (array[i] < pivot) {
            temp = array[i];
            array[i] = array[pindex];
            array[pindex] = temp;
            ++pindex;
        }
    }

    /*
     * At this point all elements less than 'pivot' are present to
     * the left of 'pindex'. So swap and move the element at 'high'
     * to index 'pindex'
     */
    temp = array[high];
    array[high] = array[pindex];
    array[pindex] = temp;

    /*
     * Return the partition index to the quick sort routine
     */
    return(pindex);
}

/*
 * This function sorts an integer array from indicies 'low' to 'high' in
 * ascending order using quick sort. The tme complexity of this function
 * is O(n*log(n)) is best case and O(n^2) in worst case. Here 'n' is the
 * number of array elements.
 */
void quicksort (int* array, int low, int high)
{
    int partition_index;

    /*
     * If array is NULL or 'low' or 'high' are less than zero, then
     * there is no need to sory the array. So return.
     */
    if (!array || (low < 0) || (high < 0)) {
        return;
    }

    /*
     * If 'low' is less than 'high', partition the array using and recursively
     * sort the parts around the partition index using quick sort
     */
    if (low < high) {
        partition_index = partition(array, low, high);
        quicksort(array, low, partition_index - 1);
        quicksort(array, partition_index + 1, high);
    }
}

/*
 * This function returns 'true' if there exists a pair which when added
 * together gives the 'sum'. If no such pair exists this function returns
 * 'false'. This function takes the following approach to solve the problem:-
 * 1. First sort the array using some quick sort
 * 2. Walk the sorted array from left and right to check if some pair adds
 *    to 'sum'.
 *   a. If the sum of the left and right elements is less than sum, then
 *      increment left index so that we can get more closer to sum.
 *   b. If the sum of the left and right elements is greater than sum, then
 *      decrement right index so that we can get more closer to sum.
 *   c. If the sum of the left and right elements is equal to sum, then
 *      return 'true'.
 * 3. IF the 'sum' is not found, then return 'false'.
 * The time complexity of this function is O(n * log(n)) in average case and
 * O(n^2) in worst case since we sort the array using quick sort and then
 * walk the array once. Here 'n' is the number of elements in the array.
 * The space complexity of this function is O(1).
 */
bool check_if_an_array_contains_a_pair_with_given_sum_v1 (int *array, int len,
                                                          int sum)
{
    int left, right;

    /*
     * If either array in NULL or its length is illegal, then return 'false' as
     * we cannot find a pair having sum as target.
     */
    if (!array || (len < 0)) {
        return(false);
    }

    /*
     * Sort the array using quick sort
     */
    quicksort(array, 0, len -1);

    /*
     * Set 'left' at index zero and 'right' at index 'len-1'
     */
    left = 0;
    right = len - 1;

    /*
     * Iterate through the array until 'left' is strictly less than 'right'
     */
    while (left < right) {
        if ((array[left] + array[right]) < sum) {

            /*
             * If the sum of the left and right elements is less
             * than sum, then increment left
             */
            ++left;
        } else if ((array[left] + array[right]) > sum) {

            /*
             * If the sum of the left and right elements is greater
             * than sum, then decrement right
             */
            --right;
        } else {

            /*
             * If the sum of the left and right elements is equal to
             * sum, then return 'true'.
             */
            return(true);
        }
    }

    /*
     * Since no such pair having 'sum' was found, so return 'false'
     */
    return(false);
}

/*
 * Number of buckets in the hash table
 */
#define MAX_HASH_SIZE (1 << 16)

/*
 * This hash function returns the lower 16 set bits of the input 'data'.
 */
int hash_func (int data)
{
    return(data & (MAX_HASH_SIZE - 1));
}

/*
 * Data node of the entry stored in the hash table which handles
 * collisions via chaining.
 */
struct data {
    int original_key;  /* Original key */
    int index;         /* Index of the original key in the
                          array */
    struct data* next; /* The next pointer for the linked
                          list */
};

/*
 * Structure defintion of the hash table.
 */
struct hash_table {
    struct data** buckets; /* Array pointers refrencing the linked
                              list chains */
    int size;              /* Total number of buckets */
};

/*
 * This function initializes a hash table with a given size.
 */
void hash_table_init (struct hash_table *ht, int size)
{
    int index;

    /*
     * If the pointer to the hash table is NULL or its size is
     * invalid, then return.
     */
    if (!ht || (size <= 0)) {
        return;
    }

    /*
     * Allocate 'size' buckets in the hash table
     */
    ht->buckets = (struct data**)malloc(sizeof(struct data*) * size);

    /*
     * If the memory allocation of the buckets fails, then set the size
     * in the hash table to zero and return from this function.
     */
    if (!(ht->buckets)) {
        ht->size = 0;
        return;
    }

    ht->size = size;

    /*
     * Set all the buckets in the hash table to NULL
     */
    for (index = 0; index < size; ++index) {
        ht->buckets[index] = NULL;
    }
}

/*
 * This function adds a value and the array index in a node in the hash table.
 * The 'value' and the 'index' are added in the bucket chain, the key for which
 * is obtained from 'value'. The best case time complexity of this function is
 * O(1) but the worst case time complexity of this function is O(n) where 'n'
 * is the number of nodes in a given chain.
 */
void hash_table_insert (struct hash_table* ht, int value, int index)
{
    int key;
    struct data* node;

    /*
     * If the hash table is not valud, then return from this
     * function
     */
    if (!ht) {
        return;
    }

    /*
     * Get the key from the 'value' using the hash function
     */
    key = hash_func(value);

    /*
     * If 'key' is greater than the maximum size of the hash table,
     * then return from this function
     */
    if (key >= ht->size) {
        return;
    }

    /*
     * Allocate the memory for the node that needs to be inserted
     * in the hash table
     */
    node = (struct data*)malloc(sizeof(struct data));

    /*
     * If the memory allocation fails, then return from this
     * function
     */
    if (!node) {
        return;
    }

    /*
     * Copy the value and the index into the data node
     */
    node->original_key = value;
    node->index = index;
    node->next = NULL;

    /*
     * Insert the node in the hash table in the bucket at
     * position 'key'
     */
    if (!(ht->buckets[key])) {

        /*
         * If the bucket is empty, then point the bucket to
         * this node
         */
        ht->buckets[key] = node;
    } else {

        /*
         * If the bucket is not empty, then add the node to
         * the beginning of the chain in this bucket
         */
        node->next = ht->buckets[key];
        ht->buckets[key] = node;
    }
}

/*
 * This function returns the data node based on the input value from the
 * hash table. The best case time complexity of this function is O(1) but
 * the worst case time complexity of this function is O(n) where 'n' is the
 * number of nodes in a given chain.
 */
struct data* hash_table_search (struct hash_table* ht, int data)
{
    int key;
    struct data* node;

    /*
     * If the hash table is not valid, then return NULL
     */
    if (!ht) {
        return(NULL);
    }

    /*
     * Compute the key from the hash function based on the
     * input data value
     */
    key = hash_func(data);

    /*
     * IF the computed key is greater than the hash table size,
     * then return NULL from the function
     */
    if (key >= ht->size) {
        return(NULL);
    }

    /*
     * Get the reference of the 'keyth' bucket from the hash table
     */
    node = ht->buckets[key];

    /*
     * If the bucket is empty, then the return NULL
     */
    if (!node) {
        return(NULL);
    }

    /*
     * Iterate through the chain in the 'keyth' bucket until
     * we find the node containing 'data'
     */
    while (node && (node->original_key != data)) {
        node = node->next;
    }

    /*
     * Return the data node
     */
    return(node);
}

/*
 * This function walks and frees the hash table buckets and its
 * chains.
 */
void hash_table_free (struct hash_table* ht)
{
    struct data* node;
    struct data* temp;
    int index;

    /*
     * If the hash table is not valid and the size of the hash
     * table is not valid, then we do not need to free anything.
     * So return from this function.
     */
    if (!ht || (ht->size <= 0)) {
        return;
    }

    /*
     * Iterate through each bucket and free the chains
     */
    for (index = 0; index < ht->size; ++index) {
        if (ht->buckets[index]) {
            node = ht->buckets[index];

            /*
             * Iterate through the chain and free each node
             */
            while (node) {
                temp = node;
                node = node->next;
                temp->next = NULL;
                free(temp);
            }
        }
    }

    /*
     * Free the array of hash buckets
     */
    free(ht->buckets);
}

/*
 * This function returns 'true' if there exists a pair which when added
 * together gives the 'sum'. If no such pair exists this function returns
 * 'false'. The approach uses hashing to find if some pair exists whose sum
 * matches the 'target'. The time complexity of this function is O(n) as we
 * walk the array once and map the elements in a hash table. Here 'n' is the
 * number of elements in the array. The space complexity of this function
 * is O(m), where 'm' is the size of the hash table.
 */
bool check_if_an_array_contains_a_pair_with_given_sum_v2
                                        (int* nums, int numsSize,
                                         int target)
{
    int index;
    struct hash_table ht;
    struct data* node;

    /*
     * If either array in NULL or its length is illegal, then return 'false' as
     * we cannot find a pair having sum as target.
     */
    if (!nums || (numsSize <= 0)) {
        return(false);
    }

    /*
     * Itnitialize a hash table of a large size
     */
    hash_table_init(&ht, MAX_HASH_SIZE);

    /*
     * If the size of the hash table is zero, then return 'false'
     * from the function.
     */
    if (ht.size == 0) {
        return(false);
    }

    /*
     * Iterate through the entire array
     */
    for (index = 0; index < numsSize; ++index) {

        /*
         * Check if there exists a node in the hash table whose
         * key matches with 'target - nums[index]'
         */
        node = hash_table_search(&ht, target - nums[index]);
        if (node) {
            /*
             * If there exists a node with data 'target - nums[index]',
             * then a pair with sum 'target' is found. So break.
             */
            break;
        } else {

            /*
             * Otherwise insert the 'value' and index in the hash table
             */
            hash_table_insert(&ht, nums[index], index);
        }
    }

    if (node) {

        /*
         * If node is valid, then free the hash table and return
         * 'true'.
         */
        hash_table_free(&ht);
        return(true);
    }

    /*
     * If node is not valid, then free the hash table and return
     * 'false'.
     */
    hash_table_free(&ht);
    return(false);
}

int main ()
{
    /*
     * Test 0: Test with a NULL array. The sum cannot be found in a
     *         NULL array.
     */
    int* array0 = NULL;
    int len0 = 10;
    int sum0 = 10;
    assert(false == check_if_an_array_contains_a_pair_with_given_sum_v2(
                                                        array0, len0, sum0));
    assert(false == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                        array0, len0, sum0));

    /*
     * Test 1: Test with an array length which is illegal. The sum cannot
     *         be found in an array whose length is not valid.
     */
    int array1[] = {10, 90, 5, 15};
    int len1 = -10;
    int sum1 = 10;
    assert(false == check_if_an_array_contains_a_pair_with_given_sum_v2(
                                                        array1, len1, sum1));
    assert(false == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                        array1, len1, sum1));

    /*
     * Test 2: Test with an legal array (positive numbers) only and length
     *         in which the desired sum is found
     */
    int array2[] = {10, 90, 5, 15, 100, 85, 95};
    int len2 = sizeof(array2)/sizeof(int);;
    int sum2 = 185;
    assert(true == check_if_an_array_contains_a_pair_with_given_sum_v2(
                                                        array2, len2, sum2));
    assert(true == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                        array2, len2, sum2));

    /*
     * Test 3: Test with an legal array (positive numbers) only and length
     *         in which the desired sum is not found
     */
    int array3[] = {10, 90, 5, 15, 100, 85, 95};
    int len3 = sizeof(array3)/sizeof(int);;
    int sum3 = 1000;
    assert(false == check_if_an_array_contains_a_pair_with_given_sum_v2(
                                                        array3, len3, sum3));
    assert(false == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                        array3, len3, sum3));

    /*
     * Test 4: Test with an legal array (negative numbers) only and length
     *         in which the desired sum is found
     */
    int array4[] = {-10, -90, -5, -15, -100, -85, -95};
    int len4 = sizeof(array4)/sizeof(int);;
    int sum4 = -105;
    assert(true == check_if_an_array_contains_a_pair_with_given_sum_v2(
                                                        array4, len4, sum4));
    assert(true == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                        array4, len4, sum4));

    /*
     * Test 5: Test with an legal array (negative numbers) only and length
     *         in which the desired sum is not found
     */
    int array5[] = {-10, -90, -5, -15, -100, -85, -95};
    int len5 = sizeof(array5)/sizeof(int);;
    int sum5 = -109;
    assert(false == check_if_an_array_contains_a_pair_with_given_sum_v2(
                                                        array5, len5, sum5));
    assert(false == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                        array5, len5, sum5));

    /*
     * Test 6: Test with an legal array (positive and negative numbers) only
     *         and length in which the desired sum is found
     */
    int array6[] = {10, -90, 5, -15, 100, -85, -95};
    int len6 = sizeof(array6)/sizeof(int);;
    int sum6 = 10;
    assert(true == check_if_an_array_contains_a_pair_with_given_sum_v2(
                                                        array6, len6, sum6));
    assert(true == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                        array6, len6, sum6));

    /*
     * Test 7: Test with an legal array (positive and negative numbers) only
     *         and length in which the desired sum is not found
     */
    int array7[] = {10, -90, 5, -15, 100, -85, -95};
    int len7 = sizeof(array7)/sizeof(int);;
    int sum7 = -1090;
    assert(false == check_if_an_array_contains_a_pair_with_given_sum_v2(
                                                        array7, len7, sum7));
    assert(false == check_if_an_array_contains_a_pair_with_given_sum_v1(
                                                        array7, len7, sum7));

    return(0);
}
