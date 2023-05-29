#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *prev;

    Node() {}

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert(Node *&head, int data, int pos)
{
    Node *newnode = new Node(data);
    // when head itself is null.
    if (head == NULL)
    {
        head = newnode;
        return;
    }

    // when position is 1, insert at head.
    if (pos == 1)
    {

        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        cout << head->data << endl;
        return;
    }

    // insertion at positions other than head.
    Node *temp = head;
    int i = 1;
    while ((i < pos - 1) && temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }
    // check if you exited the linked list.
    if (temp->next == NULL)
    {
        temp->next = newnode;
        newnode->prev = temp;
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    (newnode->next)->prev = newnode;
    newnode->prev = temp;

    return;
}

void print(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void deletion(Node *&head, int pos)
{

    if (head == NULL)
        return;
    Node *curr = head;

    if (pos == 1)
    {
        head = head->next;
        head->prev = NULL;
        curr->next = NULL;
        delete curr;
        return;
    }
    Node *previous = NULL;
    int i = 1;
    while (i < pos)
    {
        previous = curr;
        curr = curr->next;
        i++;
    }
    if (curr->next == NULL)
    {
        previous->next = NULL;
        curr->prev = NULL;
        delete curr;
        return;
    }

    previous->next = curr->next;
    curr->next = NULL;
    previous->next->prev = previous;
    curr->prev = NULL;
    delete curr;
}

int main()
{
    Node *head = NULL;
    insert(head, 45, 1);
    insert(head, 65, 2);
    insert(head, 180, 2);
    insert(head, 78, 3);
    insert(head, 91, 2);
    
    print(head);

    deletion(head, 6);

    print(head);

    return 0;
}