#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_WORD_LENGTH = 80;

/* definition of a node */
struct Node;
typedef Node *Node_ptr;

struct Node
{
    char word[MAX_WORD_LENGTH];
    Node_ptr ptr_to_next_node;
};

/* Function to assign a linked list to "a_node" */
void assign_list(Node_ptr &a_list);

/* Function to assign a new dynamic node variable to "a_node" */
void assign_new_node(Node_ptr &a_node);

/* Function to print the strings in the list "a_node" */
void print_list(Node_ptr a_node);

void delete_node(Node_ptr &a_list, char a_word[]);

void add_after(Node_ptr &list, char a_word[], char word_after[]);

void list_selection_sort(Node_ptr &a_list);

bool alphabetically_smaller(char string1[], char string2[]);

void swap(Node_ptr &one, Node_ptr &two);

bool alphabetically_smaller(char string1[], char string2[]);

void swap(char first[], char second[]);

Node_ptr minimun_from(Node_ptr &list, Node_ptr position);

void list_selection_sort(Node_ptr &a_list);

/* MAIN PROGRAM */
int main()
{
    Node_ptr my_list = NULL;
    char a_word[MAX_WORD_LENGTH], word_after[MAX_WORD_LENGTH];

    assign_list(my_list);

    cout << "\nTHE LIST IS NOW:\n";
    print_list(my_list);

    cout << "\nAFTER WHICH WORD WOULD YOU LIKE TO ADD AN EXTRA WORD?\n";
    //cin.getline(a_word, MAX_WORD_LENGTH);
    cin >> a_word;

    cout << "\nWHICH WORD WOULD YOU LIKE TO ADD?\n";
    //cin.getline(word_after, MAX_WORD_LENGTH);
    cin >> word_after;

    add_after(my_list, a_word, word_after);

    cout << "\nTHE LIST IS NOW:\n";
    print_list(my_list);

    cout << "\nWHICH WORD WOULD YOU LIKE TO DELETE?\n";
    cin >> a_word;

    delete_node(my_list, a_word);

    cout << "\nTHE LIST IS NOW:\n";
    print_list(my_list);

    list_selection_sort(my_list);
    cout << "\n\nAFTER SORTING, THE LIST IS:\n";
    print_list(my_list);
    cout << "\n";

    return 0;
}
/* END OF MAIN PROGRAM */

/* DEFINITION OF FUNCTION "assign_list" */
void assign_list(Node_ptr &a_list)
{
    Node_ptr current_node, last_node;

    assign_new_node(a_list);
    cout << "Enter first word (or '.' to end list): ";
    cin >> a_list->word;
    if (!strcmp(".", a_list->word))
    {
        delete a_list;
        a_list = NULL;
    }
    current_node = a_list;

    while (current_node != NULL)
    {
        assign_new_node(last_node);
        cout << "Enter next word (or '.' to end list): ";
        cin >> last_node->word;
        if (!strcmp(".", last_node->word))
        {
            delete last_node;
            last_node = NULL;
        }
        current_node->ptr_to_next_node = last_node;
        current_node = last_node;
    }
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "assign_new_node" */
void assign_new_node(Node_ptr &a_node)
{
    a_node = new (nothrow) Node;
    if (a_node == NULL)
    {
        cout << "sorry - no more memory\n";
        exit(1);
    }
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "print_list" */
void print_list(Node_ptr a_node)
{
    while (a_node != NULL)
    {
        cout << a_node->word << " ";
        a_node = a_node->ptr_to_next_node;
    }
    cout << endl;
}
/* END OF FUNCTION DEFINITION */

void delete_node(Node_ptr &a_list, char a_word[])
{
    Node_ptr a_node = a_list, last_node;

    if (!strcmp(a_node->word, a_word))
    {
        a_list = a_node->ptr_to_next_node;
        delete a_node;
        return;
    }
    else
    {

        a_node = a_node->ptr_to_next_node;
        last_node = a_list;

        while (a_node != NULL)
        {
            if (!strcmp(a_node->word, a_word))
            {
                last_node->ptr_to_next_node = a_node->ptr_to_next_node;
                delete a_node;
                return;
            }
            last_node = a_node;
            a_node = a_node->ptr_to_next_node;
        }
    }
    return;
}

void add_after(Node_ptr &list, char a_word[], char word_after[])
{

    Node_ptr a_node = list, temp_next, new_node;

    while (a_node != NULL)
    {
        if (!strcmp(a_node->word, a_word))
        {
            temp_next = a_node->ptr_to_next_node;
            new_node = new Node;
            strcpy(new_node->word, word_after);
            a_node->ptr_to_next_node = new_node;
            new_node->ptr_to_next_node = temp_next;
            return;
        }
        a_node = a_node->ptr_to_next_node;
    }
}

bool alphabetically_smaller(char string1[], char string2[])
{
    int count = 0;
    while (*(string1 + count) != '\0' && *(string2 + count) != '\0')
    {
        if (*(string1 + count) < *(string2 + count))
        {

            return true;
        }
        else if (*(string1 + count) > *(string2 + count))
        {

            return false;
        }
        count++;
    }
    if (*(string1 + count) == '\0' && *(string2 + count) != '\0')
    {

        return true;
    }
    else
    {

        return false;
    }
}

void swap(char first[], char second[])
{
    char temp[MAX_WORD_LENGTH];
    strcpy(temp, first);
    strcpy(first, second);
    strcpy(second, temp);
}

Node_ptr minimun_from(Node_ptr &list, Node_ptr position)
{

    if (position->ptr_to_next_node != NULL)
    {
        Node_ptr a_node = position->ptr_to_next_node, min;
        min = a_node;

        while (a_node != NULL)
        {
            if (alphabetically_smaller(a_node->word, min->word))
            {
                min = a_node;
            }
            a_node = a_node->ptr_to_next_node;
        }
        return min;
    }
    else
    {
        return position;
    }
}

void list_selection_sort(Node_ptr &a_list)
{
    Node_ptr a_node = a_list;

    while (a_node != NULL)
    {

        if (alphabetically_smaller(minimun_from(a_list, a_node)->word, a_node->word))
        {

            swap(minimun_from(a_list, a_node)->word, a_node->word);
        }
        a_node = a_node->ptr_to_next_node;
    }
}