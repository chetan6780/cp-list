#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Print Linked List elements ------------------------------------------------------------------
void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Reverse a linked list(3 pointer) --------------------------------------------------------------
struct Node *reverseList(struct Node *head)
{
    Node *curr = head;
    Node *prev = NULL, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// Reverse a linked list(Recursive)
struct Node *reverse(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *rest = reverse(head->next);
    head->next->next = head;

    head->next = NULL;

    return rest;
}

// Occurence of an integer in a Linked List (Non-recursive) -------------------------------------------
int count(struct Node *head, int search_for)
{
    struct Node *temp = head;
    int cnt = 0;

    while (temp != NULL)
    {
        if (temp->data == search_for)
            cnt++;
        temp = temp->next;
    }
    return cnt;
}

// Occurence of an integer in a Linked List (Recursive)
int countRec(struct Node *head, int search_for)
{
    if (head == NULL)
        return 0;
    if (head->data == search_for)
        return 1 + countRec(head->next, search_for);
    return countRec(head->next, search_for);
}

// Pairwise swap elements of a linked list by changing links (non-recursive) ----------------------------
Node *pairWiseSwap(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *prev = head;
    Node *curr = head->next;

    head = curr;

    while (true)
    {
        Node *next = curr->next;
        curr->next = prev;

        if (next == NULL || next->next == NULL)
        {
            prev->next = next;
            break;
        }

        prev->next = next->next;

        prev = next;
        curr = prev->next;
    }
    return head;
}

// Add two numbers represented by linked lists ---------------------------------------------------------
Node *reverse(Node *head)
{
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void addBack(Node *&head, Node *&last, int data)
{

    Node *newNode = new Node(data);

    if (last == NULL)
        head = newNode;
    else
        last->next = newNode;

    last = newNode;
}
Node *addTwoLists(Node *first, Node *second)
{

    Node *head1 = reverse(first);
    Node *head2 = reverse(second);
    Node *res = NULL;

    Node *last = NULL; // Last node of new list
    int total, carry = 0;

    while (head1 || head2)
    {

        int a = (head1) ? (head1->data) : (0);
        int b = (head2) ? (head2->data) : (0);

        total = (a + b + carry);
        carry = (total / 10);
        total = total % 10;

        addBack(res, last, total);

        if (head1)
            head1 = head1->next;

        if (head2)
            head2 = head2->next;
    }
    if (carry != 0)
        addBack(res, last, carry);

    res = reverse(res);
    return res;
}

// Sorted insert for circular linked list -------------------------------------------------------------

// 1 2 4 --> 1 2 2 4

struct Node *sortedInsert(struct Node *head, int data)
{
    //code here
    Node *current = head;
    Node *newNode = new Node(data);

    if (current == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    // New node is inserted before head (first node)
    else if (current->data >= newNode->data)
    {
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
        return newNode;
    }
    // New node is inserted after head
    else
    {
        while (current->next->data < newNode->data)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        return head;
    }
}

// Split a Circular Linked List into two halves -----------------------------------------------------------
// to avoid some confusion *head1_ref = temp1 ,  head2_ref = temp2
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;

    if (head == NULL)
        return;

    while (fast_ptr->next != head && fast_ptr->next->next != head)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    // for even number of elements
    if (fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;

    *head1_ref = head;

    if (head->next != head)
        *head2_ref = slow_ptr->next;

    fast_ptr->next = slow_ptr->next;

    slow_ptr->next = head;
}

// Detect loop in a linked list(Floyd’s Cycle-Finding Algorithm) FASTEST method (O(n),O(1)) ---------------------------------
bool detectLoop(Node *head)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;

    while (slow_ptr && fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if (slow_ptr == fast_ptr)
            return true;
    }
    return false;
}

// using hashing (O(n),O(n))
bool detectLoop(Node *head)
{
    unordered_set<Node *> s;

    while (head != NULL)
    {
        if (s.find(head) != s.end())
            return true;
        s.insert(head);

        head = head->next;
    }
    return false;
}

// simple approach (O(n),O(1))
// This is the simplest approach of the given problem, the only thing we have to do is to assign a new value to each data of node in the linked list which is not in the given constrins of data.
bool detectLoop(Node *head)
{
    if (!head)
        return false;

    while (head != NULL)
    {
        if (head->data == -1)
            return true;
        else
        {
            head->data = -1;
            head = head->next;
        }
    }
    return false;
}

// Delete Middle of Linked List ---------------------------------------------------------------------------------------------
Node *deleteMid(struct Node *head)
{
    // Base cases
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *slow_ptr = head;
    Node *fast_ptr = head;

    Node *prev;
    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        prev = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    // Delete the middle node
    prev->next = slow_ptr->next;
    delete slow_ptr;

    return head;
}

// Deletion at different positions in a Circular Linked List ---------------------------------------------------------------
Node *deleteAtPosition(Node *head, int pos)
{
    Node *prev = head;
    if (pos == 1)
    {
        while (prev->next != head)
            prev = prev->next;
        Node *temp = head;
        prev->next = temp->next;
        head = prev->next;
        free(temp);
        return head;
    }

    for (int i = 1; i < pos - 1; i++)
        prev = prev->next;
    Node *temp = prev->next;
    prev->next = temp->next;
    free(temp);
    return head;
}

// Function to delete a node without any reference to head pointer -------------------------------------------------------
void deleteNode(Node *pos)
{
    Node *temp = pos->next;

    pos->data = pos->next->data;

    pos->next = pos->next->next;

    free(temp);
}