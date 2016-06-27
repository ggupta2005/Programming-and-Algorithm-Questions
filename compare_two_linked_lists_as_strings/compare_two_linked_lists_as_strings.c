/*
 * The following code is for the following post from geeksforgeeks:-
 * http://www.geeksforgeeks.org/compare-two-strings-represented-as-linked-lists/
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char data;
    struct node* next;
};

struct node* makeNode (char ch)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    if (!new_node) {
        return(NULL);
    }

    new_node->data = ch;
    new_node->next = NULL;

    return(new_node);
}

void push (struct node** head, char ch)
{
    if (!head) {
        return;
    }

    struct node* new_node = makeNode(ch);

    if (!new_node) {
        return;
    }

    if (!(*head)) {
        *head = new_node;
    } else {
        new_node->next = *head;
        *head = new_node;
    }
}


/*
 * This functions returnsthe following
 * -1: if the list s1 lexicographically ahead of list s2
 *  0: if the list s1 is same as list s2
 *  1: if the list s2 lexicographically ahead of list s1
 */
int compare_strings (struct node* s1, struct node* s2)
{
    if (!s1 && !s2) {
        return(0);
    }

    if (s1 && s2) {
        if (s1->data > s2->data) {
            return(1);
        } else if (s1->data < s2->data) {
            return(-1);
        } else {
            return(compare_strings(s1->next, s2->next));
        }
    }

    if (s1 && !s2) {
        return(1);
    }

    if (!s1 && s2) {
        return(-1);
    }
}

int get_length (struct node* string)
{
    int length = 0;

    while (string) {
        ++length;
        string = string->next;
    }

    return(length);
}

char* get_string (struct node* string)
{
    int length = get_length(string);
    int i;
    char* ch = (char*)malloc(sizeof(char) * (length+1));

    if (!ch) {
        return(NULL);
    }

    if (!string) {
        return("NULL");
    }

    memset(ch, 0, length+1);

    i = 0;
    while (string) {
        ch[i] = string->data;
        ++i;
        string = string->next;
    }

    return(ch);
}

int main()
{
    struct node* string1 = NULL;
    struct node* string2 = NULL;
    int result;

    push(&string1, 's');
    push(&string1, 'k');
    push(&string1, 'e');
    push(&string1, 'e');
    push(&string1, 'g');

    push(&string2, 's');
    push(&string2, 'k');
    push(&string2, 'e');
    push(&string2, 'e');
    push(&string2, 'g');

    result = compare_strings(string1, string2);

    if (result > 0) {
        printf("The string %s comes before string %s\n", get_string(string2),
               get_string(string1));
    } else if (result < 0) {
        printf("The string %s comes before string %s\n", get_string(string1),
               get_string(string2));
    } else {
        printf("The string %s is same as string %s\n", get_string(string2),
               get_string(string1));
    }

    return(0);
}

/*
 * Output:-
 * gaurav@gaurav:~/Desktop/PRIVATE/Test/Test$ ./a.out
 * The string geeks is same as string geeks
 */
