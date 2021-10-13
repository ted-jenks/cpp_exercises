#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_WORD_LENGTH = 80;
const int MAX_WORDS = 80;

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

void print_list_forwrad(Node_ptr a_node);

void print_list_backward(Node_ptr a_node);

void print_list_backward_loop(Node_ptr a_node);

/* MAIN PROGRAM */
int main()
{
    Node_ptr my_list = NULL;

    assign_list(my_list);

    cout << "\nTHE LIST FORWARD:\n";
    print_list_forwrad(my_list);

    cout << "\nTHE LIST BACKWARD:\n";
    print_list_backward_loop(my_list);

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
}
/* END OF FUNCTION DEFINITION */

void print_list_forwrad(Node_ptr a_node)
{
    char word[MAX_WORD_LENGTH];
    if (a_node == NULL)
    {
        return;
    }
    else
    {

        strcpy(word, a_node->word);
        cout << word << " ";
        print_list_forwrad(a_node->ptr_to_next_node);
    }
}

void print_list_backward(Node_ptr a_node)
{
    char word[MAX_WORD_LENGTH];
    if (a_node == NULL)
    {
        return;
    }
    else
    {

        strcpy(word, a_node->word);
        print_list_forwrad(a_node->ptr_to_next_node);
        cout << word << " ";
    }
}

void print_list_backward_loop(Node_ptr a_node)
{
    char chars[MAX_WORD_LENGTH][MAX_WORDS];
    int no_of_words_input = 0;

    while (a_node != NULL && no_of_words_input < MAX_WORDS)
    {
        strcpy(chars[no_of_words_input], a_node->word);
        no_of_words_input++;
        a_node = a_node->ptr_to_next_node;
    }

    for (int count = no_of_words_input - 1; count >= 0; count--)
        cout << chars[count] << " ";

    cout << endl;
}
