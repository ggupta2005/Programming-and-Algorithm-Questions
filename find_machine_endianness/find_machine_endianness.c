/*
 * Endianness refers to the order in which a computer stores the bytes
 * of a multibyte value "MSB""LSB".
 * In a big-endian machine, the MSB has the lowest address.
 * In a little-endian machine, the LSB has the lowest address.
 * More information on machine endianess can be found at the following
 * link:- https://www.cs.umd.edu/class/sum2003/cmsc311/Notes/Data/endian.html
 */
#include<stdio.h>
#include<assert.h>

#define LITTLE_ENDIAN 1 /* Constant for little endian */
#define BIG_ENDIAN    2 /* Constant for big endian */

/*
 * This function returns whether the endianess of the machine is big endian
 * or little endian.
 */
int find_machine_endiness ()
{
    /*
     * Set some integer variable value to one
     */
    int val = 1;

    /*
     * Point a character pointer to the address of the
     * integer
     */
    char* ch = (char*)&val;

    /*
     * If the zeroth byte of the character array is one,
     * then the machine is little endian, so return little
     * endian.
     */
    if ((int)ch[0] == 1) {
        return(LITTLE_ENDIAN);
    }

    /*
     * If the machine is not little endian, then return
     * big endian
     */
    return(BIG_ENDIAN);
}

int main()
{
    /*
     * The endianess of the machine can be obtained by unix command
     * "lscpu". The truncated output of lscpu is below:-
     *   terminal~$ lscpu
     *       Architecture:          x86_64
     *       CPU op-mode(s):        32-bit, 64-bit
     *       Byte Order:            Little Endian
     *       CPU(s):                1
     *       .
     *       .
     */
    assert(LITTLE_ENDIAN == find_machine_endiness());

    return(0);
}
