/*
 * This program finds the maximum product of all sub-parts that can
 * be obtained by cutting a rod into sub-parts. At least one cut is
 * needed to cut the rod into sub-parts. For example, a rod of length
 * 5 can be cut into sub-parts of (2,3), (1,4), (1,1,1,1,1) etc.. but
 * the maximum product that can be obtained from the sub-parts is 6 (2,3).
 * For more information on this problem, please refer to the following
 * link:-
 * http://www.geeksforgeeks.org/dynamic-programming-set-36-cut-a-rope-to-maximize-product/
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

int get_max_product_cuttng_a_rod_v1 (int length)
{
    int sub_len, max_product, temp_product;

    if (length <= 0) {
        return(0);
    }

    if (length == 1) {
        return(1);
    }

    max_product = 0;
    for (sub_len = 1; sub_len < length; ++sub_len) {
        temp_product =
            get_max_product_cuttng_a_rod_v1(sub_len) *
            get_max_product_cuttng_a_rod_v1(length - sub_len);

        if (temp_product > max_product) {
            max_product = temp_product;
        }
    }

    return(max_product);
}

int main ()
{
    assert(0 == get_max_product_cuttng_a_rod_v1(0));
    assert(1 == get_max_product_cuttng_a_rod_v1(1));
    assert(1 == get_max_product_cuttng_a_rod_v1(2));
    assert(2 == get_max_product_cuttng_a_rod_v1(3));
    assert(2 == get_max_product_cuttng_a_rod_v1(3));

    return(0);
}
