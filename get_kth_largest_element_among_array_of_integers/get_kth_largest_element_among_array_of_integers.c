/*
 * This program finds the kth largest element in an array of integers. For more
 * information on the problem, please refer to the following link:-
 * http://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>

struct heap {
    int* array;
    int max_size;
    int current_size;
};

int partition (int* array, int low, int high)
{
    int pivot, temp, i, pindex;

    pivot = array[high];
    pindex = low;
    for (i = low; i < high; ++i) {
        if (array[i] > pivot) {
            temp = array[i];
            array[i] = array[pindex];
            array[pindex] = temp;
            ++pindex;
        }
    }

    temp = array[high];
    array[high] = array[pindex];
    array[pindex] = temp;

    return(pindex);
}

void quicksort (int* array, int low, int high)
{
    int partition_index;

    if (!array || (low >= high)) {
        return;
    }

    partition_index = partition(array, low, high);
    quicksort(array, low, partition_index - 1);
    quicksort(array, partition_index + 1, high);
}

int get_kth_largest_element_among_array_of_integers_v1 (int* array,
                                                        int len, int k)
{
    int i;

    if (!array || (len <= 0) || (k <= 0) || (k > len)) {
        return(INT_MIN);
    }

    quicksort(array, 0, len - 1);

    return(array[k - 1]);
}

void init_heap (struct heap* h, int size)
{
    if (h && (size > 0)) {
        h->array = (int*)malloc(sizeof(int) * size);

        if (!(h->array)) {
            h->current_size = 0;
            h->max_size = 0;
            return;
        }

        h->current_size = 0;
        h->max_size = size;
    }
}

bool insert_into_min_heap (struct heap* h, int num)
{
    int temp, parent, child;

    if (!h || (h->current_size >= h->max_size)) {
        return(false);
    }

    h->array[h->current_size] = num;
    h->current_size += 1;

    child = h->current_size - 1;
    parent = (child - 1)/2;

    while (child > 0 && (h->array[parent] > h->array[child])) {
        temp = h->array[parent];
        h->array[parent] = h->array[child];
        h->array[child] = temp;

        child = parent;
        parent = (parent - 1) / 2;
    }

    return(true);
}

int extract_from_min_heap (struct heap* h)
{
    int min, parent, temp, left_child, right_child, child;

    if (!h || (h->current_size == 0)) {
        return(INT_MIN);
    }

    min = h->array[0];
    h->array[0] = h->array[h->current_size - 1];
    h->current_size -= 1;

    parent = 0;
    while (parent <= (h->current_size - 1)) {

        left_child = 2 * parent + 1;
        right_child = 2 * parent + 2;
        child = -1;

        if ((left_child <= (h->current_size - 1))
            && (h->array[parent] > h->array[left_child])) {
            child = left_child;
        } else if ((right_child <= (h->current_size - 1))
                   && (h->array[parent] > h->array[right_child])) {
            child = right_child;
        }

        if (child != -1) {
            temp = h->array[parent];
            h->array[parent] = h->array[child];
            h->array[child] = temp;

            parent = child;
        } else {
            break;
        }
    }

    return(min);
}

void free_heap (struct heap* h)
{
    if (!h) {
        return;
    }

    free(h->array);
}

int get_kth_largest_element_among_array_of_integers_v2 (int* array,
                                                        int len, int k)
{
    int i, min, kth_largest;
    struct heap h;

    if (!array || (len <= 0) || (k <= 0) || (k > len)) {
        return(INT_MIN);
    }

    init_heap(&h, k);

    for (i = 0; i < len; ++i) {
        if (!insert_into_min_heap(&h, array[i])) {

            min = extract_from_min_heap(&h);

            if (min != INT_MIN) {
                if (min < array[i]) {
                    insert_into_min_heap(&h, array[i]);
                } else {
                    insert_into_min_heap(&h, min);
                }
            }
        }
    }

    kth_largest = h.array[0];
    free_heap(&h);
    return(kth_largest);
}

int main ()
{
    int array4[] = {6,5,3,1,4,2,9,7,8};
    int len4 = sizeof(array4)/sizeof(int);
    int k4 = 1;
    int exp_kth_largest4 = 9;
    assert(exp_kth_largest4 =
            get_kth_largest_element_among_array_of_integers_v1(
                                                    array4, len4, k4));
    assert(exp_kth_largest4 =
            get_kth_largest_element_among_array_of_integers_v2(
                                                    array4, len4, k4));

    return(0);
}
