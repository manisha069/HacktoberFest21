/**
 Program to create a link list and insert element by any position
 Delete any element by value, delete all the occurrence of a value,
 delete all duplicates to create unique list
 count the number of nodes,
 count occurrence of an element, count total number of duplicates
 search an element
 sort all the elements
 average of the elements
 printing only the odd position nodes value
 display the linked list

 */

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insertByPos(Node* &head, int x, int pos)
{

    Node* current = new Node;
    current->data = x;
    current->next = NULL;

    if(pos == 1 || head == NULL)
    {
        current->next = head;
        head = current;
    }
    else
    {
        int i = 1;

        Node* thisNode = head;
        Node* prevNode = NULL;

        while(i < pos && thisNode != NULL)
        {
            prevNode = thisNode;
            thisNode = thisNode->next;
            i++;
        }

        if(thisNode == NULL)
        {
            prevNode->next = current;
        }
        else
        {
            current->next = thisNode;
            prevNode->next = current;
        }
    }
}

void appendNode(Node*& head, int value)
{

    Node* current = new Node;
    current->data = value;
    current->next = NULL;
    if (head == NULL)
    {
        head = current;
    }
    else
    {
        Node* thisNode = head;
        Node* prevNode = NULL;
        while(thisNode != NULL)
        {
            prevNode = thisNode;
            thisNode = thisNode->next;
        }
        prevNode->next = current;
    }

}

bool deleteByVal(Node *&head, int x)
{
    if(head == NULL)
    {
        return false;
    }
    else
    {
        Node* thisNode = head;
        Node* prevNode = NULL;

        while(thisNode != NULL)
        {
            if(thisNode->data == x)
                break;
            prevNode = thisNode;
            thisNode = thisNode->next;
        }
        if(thisNode == NULL)
        {
            return false;
        }
        if(thisNode == head)
        {
            head = thisNode->next;
        }
        else
        {
            prevNode->next = thisNode->next;
        }
        delete thisNode;
        return true;
    }
}

void deleteAllOccurances(Node* &head, int x)
{
    while(deleteByVal(head, x))
    {}
}

void removeDuplicates( Node *start)
{
    Node *ptr1, *ptr2, *dup;
    ptr1 = start;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        while (ptr2->next != NULL)
        {

            if (ptr1->data == ptr2->next->data)
            {

                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void display(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl;
}

int countNumOfNodes(Node* head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int countOccurrence(Node* head, int search_for)
{
    int count = 0;
    while (head != NULL)
    {
        if (head->data == search_for)
            count++;
        head = head->next;
    }
    return count;
}

int countTotalDup(Node* head)
{
    int count = 0;
    while (head->next != NULL)
    {
        Node *ptr = head->next;
        while (ptr != NULL)
        {
            if (head->data == ptr->data)
            {
                count++;
            }
            ptr = ptr->next;
        }
        head = head->next;
    }
    return count;
}

bool searchNode(Node* n, int x)
{
    while(n != NULL)
    {
        if(n->data == x)
            return true;
        n = n->next;
    }
    return false;
}

void bubble_sort(Node* head)
{
    Node*previous=NULL,*current=head;
    int temp_data;
    while(head != NULL)
    {
        previous=current;
        while(previous != NULL)
        {
            if(previous->next && previous->data > previous->next->data)
            {

                temp_data=previous->data;
                previous->data=previous->next->data;
                previous->next->data=temp_data;
            }

            previous=previous->next;
        }

        head=head->next;
    }

}

float average(Node* lst)
{
    int count = 0;
    float sum = 0;
    while(lst != NULL)
    {
        count++;
        sum = sum + lst->data;
        lst = lst->next;
    }

    return sum/count;
}


void PrintOddPositions(Node* lst)
{
    int pos =0;
    while(lst != NULL)
    {
        pos++;
        if(pos % 2 != 0)
            cout << lst->data << " ";
        lst = lst->next;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;
    int x, pos;
    while(1)
    {
        cout <<"Enter the data:";
        cin >> x;
        if(x ==0 )
            break;
        cout << "Enter the position:";
        cin >>pos;

        insertByPos(head, x, pos);
        display(head);
    }
    appendNode(head,100);
    display(head);
    int totalNodes = countNumOfNodes(head);
    cout << "Number of nodes = " << totalNodes << endl;

    cout << "Sorting Elements - " << endl;
    bubble_sort(head);
    display(head);

    cout << "Total number of duplicates is - " << countTotalDup(head) << endl;

    int sele;
    cout << "Enter a value to search - ";
    cin >>sele;
    if(searchNode(head,sele))
        cout << "Value is found" << endl;
    else
        cout << "Value is NOT found" << endl;


    int cdup;
    cout << "Enter a value to count its occurrence - ";
    cin >> cdup;
    cout << "Total number of " << cdup <<" occurred here - " << countOccurrence(head,cdup) << endl;;

    int remv;
    cout << "Enter the value to delete:";
    cin >> remv;
    if(deleteByVal(head, remv))
    {
        cout << remv << " is removed from list" << endl;
        display(head);
    }
    else
        cout << remv << " is NOT found in the list" << endl;


    cout << "Enter the value to delete all its occurrence:";
    cin >> x;
    deleteAllOccurances(head, x);

    display(head);

    cout << "Removing duplicates " << endl;
    removeDuplicates(head);
    display(head);

    totalNodes = countNumOfNodes(head);
    cout << "Number of nodes = " << totalNodes << endl;

    float avg = average(head);
    cout << "Average = " << avg << endl;

    cout << "Printing Odd position element - "<< endl;
    PrintOddPositions(head);
}
