/*
 * You are playing the following Nim Game with your friend:
 * There is a heap of stones on the table, each time one of
 * you take turns to remove 1 to 3 stones. The one who removes
 * the last stone will be the winner. You will take the first
 * turn to remove the stones.
 *
 * Both of you are very clever and have optimal strategies for
 * the game. Write a function to determine whether you can win
 * the game given the number of stones in the heap.
 *
 * For example, if there are 4 stones in the heap, then you will
 * never win the game: no matter 1, 2, or 3 stones you remove,
 * the last stone will always be removed by your friend.
 */
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

/*
 * This function returns 'true' if the first player can win the
 * win game and 'false' otherwise. The time and space complexity
 * of this function is O(1).
 */
bool if_first_mover_winner(int num)
{
    /*
     * If the 'num' is less than or equal to zero, return 'false'
     */
    if (num <= 0) {
        return(false);
    }

    /*
     * Return'true' if 'num' is not a  multiple of four and 'false'
     + otherwise.
     */
    return((num % 4) != 0);
}

int main ()
{
    assert(true == if_first_mover_winner(1));
    assert(true == if_first_mover_winner(2));
    assert(true == if_first_mover_winner(3));
    assert(false == if_first_mover_winner(4));
    assert(true == if_first_mover_winner(5));

    return(0);
}
