/*
 * TODO:CODE
 * TODO:DOC
 * TODO:TESTS
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<string.h>

char** generatePossibleNextMoves(char* s, int* returnSize) 
{
    char** result;
    int index, total_comb, temp, inner_index, len;
    bool if_within_plus;
    
    if (!returnSize) {
        return(NULL);
    }
    
    if (!s || !strlen(s)) {
        *returnSize = 0;
        return(NULL);
    }
    
    len = strlen(s);
    
    total_comb = 0;
    if_within_plus = false;
    temp = 0;
    for (index = 0; index < len; ++index) {
        if (s[index] == '+') {
            ++temp;
            if (!if_within_plus) {
                if_within_plus = true;
            }
        } else {
            if (if_within_plus) {
                if_within_plus = false;
                
                if (temp > 1) {
                    total_comb +=  (temp - 1);
                }
                
                temp = 0;
            }
        }
    }
    
    if (if_within_plus) {

        if (temp > 1) {
            total_comb +=  (temp - 1);
        }
    }
    
    if (!total_comb) {
        *returnSize = 0;
        return(NULL);
    }
    
    result = (char**)malloc(sizeof(char*) * total_comb);
    
    if (!result) {
        *returnSize = 0;
        return(NULL);        
    }
    
    for (index = 0; index < total_comb; ++index) {
         result[index] = (char*)malloc(sizeof(char) * (len + 1));
         
         if (!result[index]) {
             
             for (inner_index = 0; inner_index < index; ++inner_index) {
                 free(result[inner_index]);
             }
             
             free(result);
             *returnSize = 0;
             return(NULL);
         }
         
         memset(result[index], 0, sizeof(char) * (len + 1));
    }
    
    temp = 0;
    for (index = 1; index < len; ++index) {
        if ((s[index - 1] == '+') && (s[index] == '+')) {
            strncpy(result[temp], s, len);
            result[temp][index - 1] = '-';
            result[temp][index] = '-';
            ++temp;
        }
    }
    
    *returnSize = total_comb;
    return(result);
}

int main ()
{
    int num_moves;
    generatePossibleNextMoves("++++", &num_moves);     

    return(0);
}
