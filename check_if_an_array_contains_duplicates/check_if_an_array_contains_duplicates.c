/*
 * This program checks if an array contains duplicate elements.
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<limits.h>
#include<stdbool.h>

/*
 * This function partitions the array around a 'pivot' element and returns the
 * index of the pivot element. This function uses the element at index 'high'
 * as the pivot.
 */
int partition (int*array, int low, int high)
{
    int index, pindex, pivot, temp;

    /*
     * Set 'pivot' as the element at index 'high' in the array
     */
    pivot = array[high];

    pindex = low;
    for (index = low; index < high; ++index) {

        /*
         * If the array element is less than pivot element
         * then move the element to the left of the pivot
         */
        if (array[index] < pivot) {
            temp = array[pindex];
            array[pindex] = array[index];
            array[index] = temp;
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
     * there is no need to sort the array. So return.
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
 * This function returns 'true' if the input array contains duplicate
 * elements and 'false' otherwise. The time complexity of this function
 * is O(n * log(n)) in average case and O(n^2) in worst case since we
 * sort the array using quick sort and then walk the array once. Here
 * 'n' is the number of elements in the array. The space complexity of
 * this function is O(1).
 */
bool check_if_array_contains_duplicates_v1(int* nums, int numsSize)
{
    int index;

    /*
     * If the input array is not valid or the array doesn't have
     * any elements, then return 'false'
     */
    if (!nums || (numsSize <= 0)) {
        return(false);
    }

    /*
     * Sort the array using quick sort
     */
    quicksort(nums, 0, numsSize - 1);

    /*
     * Iterate through the array and check if the there are duplicate
     * elements in the array
     */
    for (index = 1; index < numsSize; ++index) {

        /*
         * If the adjacent elements in the sorted array are same, then
         * return 'true'
         */
        if (nums[index] == nums[index - 1]) {
            return(true);
        }
    }

    /*
     * Since no duplicates were detected, so return 'false'
     */
    return(false);
}

/*
 * Number of buckets in the hash table
 */
#define NUM_BUCKETS (1 << 16)

/*
 * This hash function returns the lower 16 set bits of the input 'data'.
 */
int hash_function (int data)
{
    return(data & (NUM_BUCKETS - 1));
}

/*
 * Data node of the entry stored in the hash table which handles
 * collisions via chaining.
 */
struct hash_node {
    int data;                /* Data value */
    struct hash_node* next;  /* The next pointer for the linked
                                list */
};

/*
 * This function allocates and new data node and sets the 'data' field
 * in the node to be equal to 'value'.
 */
struct hash_node* make_hash_node (int value)
{
    struct hash_node* new_node;

    new_node = (struct hash_node*)malloc(sizeof(struct hash_node));

    /*
     * If the node allocated was NULL, then return null.
     */
    if (!new_node) {
        return(NULL);
    }

    new_node->data = value;
    new_node->next = NULL;

    return(new_node);
}

/*
 * Structure defintion of the hash table.
 */
struct hash {
    struct hash_node** buckets; /* Array pointers refrencing the linked
                                   list chains */
    int size;                   /* Total number of buckets */
};

/*
 * This function initializes a hash table with a given size.
 */
void init_hash (struct hash* h, int size)
{
    int index;

    /*
     * If the pointer to the hash table is NULL, the return
     */
    if (!h) {
        return;
    }

    /*
     * If the size is invalid, then return.
     */
    if (size <= 0) {
        h->size = 0;
        return;
    }

    /*
     * Allocate 'size' buckets in the hash table
     */
    h->buckets = (struct hash_node**)malloc(sizeof(struct hash_node*) * size);

    /*
     * If the memory allocation of the buckets fails, then set the size
     * in the hash table to zero and return from this function.
     */
    if (!(h->buckets)) {
        h->size = 0;
        return;
    }

    h->size = size;

    /*
     * Set all the buckets in the hash table to NULL
     */
    for (index = 0; index < size; ++index) {
        h->buckets[index] = NULL;
    }
}

/*
 * This function adds a data value in a node in the hash table. The 'data'
 * are added in the bucket chain, the key for which is obtained from 'data'.
 * The best case time complexity of this function is O(1) but the worst
 * case time complexity of this function is O(n) where 'n' is the number of
 * nodes in a given chain.
 */
void add_into_hash (struct hash* h, int data)
{
    int key;
    struct hash_node* new_node;

    /*
     * If the hash table is not valud, then return from this
     * function
     */
    if (!h || (h->size <= 0)) {
        return;
    }

    /*
     * Get the key from the 'value' using the hash function
     */
    key = hash_function(data);

    /*
     * If 'key' is greater than the maximum size of the hash table,
     * then return from this function
     */
    if ((key < 0) || (key >= h->size)) {
        return;
    }

    /*
     * Allocate the memory for the node that needs to be inserted
     * in the hash table
     */
    new_node = make_hash_node(data);

    /*
     * If the memory allocation fails, then return from this
     * function
     */
    if (!new_node) {
        return;
    }

    /*
     * Insert the node in the hash table in the bucket at
     * position 'key'
     */
    if (!(h->buckets[key])) {

        /*
         * If the bucket is empty, then point the bucket to
         * this node
         */
        h->buckets[key] = new_node;
    } else {

        /*
         * If the bucket is not empty, then add the node to
         * the beginning of the chain in this bucket
         */
        new_node->next = h->buckets[key];
        h->buckets[key] = new_node;
    }
}

/*
 * This function returns the data node based on the input value from the
 * hash table. The best case time complexity of this function is O(1) but
 * the worst case time complexity of this function is O(n) where 'n' is the
 * number of nodes in a given chain.
 */
struct hash_node* search_into_hash (struct hash* h, int data)
{
    int key;
    struct hash_node* current;

    /*
     * If the hash table is not valid, then return NULL
     */
    if (!h || (h->size <= 0)) {
        return(NULL);
    }

    /*
     * Compute the key from the hash function based on the
     * input data value
     */
    key = hash_function(data);

    /*
     * IF the computed key is greater than the hash table size,
     * then return NULL from the function
     */
    if ((key < 0) || (key >= h->size)) {
        return(NULL);
    }

    /*
     * If the bucket is empty, then the return NULL
     */
    if (!(h->buckets[key])) {
        return(NULL);
    }

    /*
     * Iterate through the chain in the 'keyth' bucket until
     * we find the node containing 'data'
     */
    current = h->buckets[key];
    while (current) {
        if (current->data == data) {

            /*
             * If the input data value is located within the
             * chain in tis bucket, then return the node
             */
            return(current);
        }

        current = current->next;
    }

    /*
     * Since the input data value is not found in the hash
     * table, return NULL.
     */
    return(NULL);
}

/*
 * This function walks and frees the hash table buckets and its
 * chains.
 */
void free_hash (struct hash* h)
{
    int index;
    struct hash_node* current;
    struct hash_node* temp;

    /*
     * If the hash table is not valid and the size of the hash
     * table is not valid, then we do not need to free anything.
     * So return from this function.
     */
    if (!h || (h->size <= 0)) {
        return;
    }

    /*
     * Iterate through each bucket and free the chains
     */
    for (index = 0; index < h->size; ++index) {

        /*
         * Iterate through the chain and free each node
         */
        current = h->buckets[index];
        while (current) {
            temp = current;
            current = current->next;
            temp->next = NULL;
            free(temp);
        }

        h->buckets[index] = NULL;
    }

    /*
     * Free the array of hash buckets
     */
    free(h->buckets);
}

/*
 * This function returns 'true' if the input array contains duplicate
 * elements and 'false' otherwise. The time complexity of this function
 * is O(n), where 'n' is the number of array elements in the input array.
 * The space complexity of the this function is O(n), since we use a hash
 * table to detect the duplicates.
 */
bool check_if_array_contains_duplicates_v2 (int* array, int len)
{
    int index;
    struct hash h;
    bool if_duplicate_found;

    /*
     * If the input array is not valid or the array doesn't have
     * any elements, then return 'false'
     */
    if (!array || (len <= 0)) {
        return(false);
    }

    /*
     * Initialize the hash table with a large number of buckets
     */
    init_hash(&h, NUM_BUCKETS);

    /*
     * Assume that the input array does not contain any duplicates
     */
    if_duplicate_found = false;

    /*
     * Iterate over the elements in the array
     */
    for (index = 0; index < len; ++index) {

        /*
         * Check if the array element exists in he input array.
         */
        if (search_into_hash(&h, array[index])) {

            /*
             * If the array element is found in the array, means that
             * duplicate exists in the input array
             */
            if_duplicate_found = true;
            break;
        } else {

            /*
             * If the array element is not found in the array then add the
             * array element into the hash table for future reference
             */
            add_into_hash(&h, array[index]);
        }
    }

    /*
     * Walk and free the hash
     */
    free_hash(&h);

    /*
     * Return if the array contains duplicates
     */
    return(if_duplicate_found);
}

int main ()
{
    /*
     * Test 0: Test with an array of positive numbers having no duplicate
     *         elements. The function detecting the duplicates should
     *         return 'false'.
     */
    int array0[] = {1,2,3};
    int len0 = sizeof(array0)/sizeof(int);
    assert(false == check_if_array_contains_duplicates_v1(array0, len0));
    assert(false == check_if_array_contains_duplicates_v2(array0, len0));

    /*
     * Test 1: Test with an array of negative numbers having no duplicate
     *         elements. The function detecting the duplicates should
     *         return 'false'.
     */
    int array1[] = {-1,-2,-3};
    int len1 = sizeof(array1)/sizeof(int);
    assert(false == check_if_array_contains_duplicates_v1(array1, len1));
    assert(false == check_if_array_contains_duplicates_v2(array1, len1));

    /*
     * Test 2: Test with an array of positive numbers having duplicate
     *         elements. The function detecting the duplicates should
     *         return 'true'.
     */
    int array2[] = {2,2,3,3,4,5,6};
    int len2 = sizeof(array2)/sizeof(int);
    assert(true == check_if_array_contains_duplicates_v1(array2, len2));
    assert(true == check_if_array_contains_duplicates_v2(array2, len2));

    /*
     * Test 3: Test with an array of negative numbers having duplicate
     *         elements. The function detecting the duplicates should
     *         return 'true'.
     */
    int array3[] = {-3,-3,-3,-3,-4,-5,-6};
    int len3 = sizeof(array3)/sizeof(int);
    assert(true == check_if_array_contains_duplicates_v1(array3, len3));
    assert(true == check_if_array_contains_duplicates_v2(array3, len3));

    /*
     * Test 4: Test with an array of positive numbers having one duplicate
     *         element. The function detecting the duplicates should
     *         return 'true'.
     */
    int array4[] = {2,1,3,3,4,5,6};
    int len4 = sizeof(array4)/sizeof(int);
    assert(true == check_if_array_contains_duplicates_v1(array4, len4));
    assert(true == check_if_array_contains_duplicates_v2(array4, len4));

    /*
     * Test 5: Test with an array of negative numbers having one duplicate
     *         element. The function detecting the duplicates should
     *         return 'true'.
     */
    int array5[] = {-2,-1,-3,-3,-4,-5,-6};
    int len5 = sizeof(array5)/sizeof(int);
    assert(true == check_if_array_contains_duplicates_v1(array5, len5));
    assert(true == check_if_array_contains_duplicates_v2(array5, len5));

    return(0);
}
