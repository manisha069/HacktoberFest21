//Write a simple CPP implementation to reverse K nodes in a linked list of user defined length
/* Code by : Rudraditya Jalan */

#include <iostream>
using namespace std;
class node
{
//Class to initialize a node
public:
    int data;
    node *next;

    //Constructor
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void print(node *&head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
//Reverse Module to reverse a list
node *revKnode(node *&head, int k)
{
    //3 pointer algorithm to implement Node reversal
    node *preptr = NULL;
    node *currptr = head;
    node *nextptr;
    int count = 0;
    while (count < k && currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = preptr;
        preptr = currptr;
        currptr = nextptr;
        count++;
    }
    //Recursive Call Implementation for reverse or get through other parts of List
    if (nextptr != NULL)
    {
        head->next = revKnode(nextptr, k);
    }
    return preptr;
}

//Insertion Module to insert element at required position
void insert(node *&head, int val, int pos)
{
    node *n = new node(val);
    if (pos == 1)
    {
        head = n;
        n->next = NULL;
    }
    else
    {
        node *temp = head;
        node *ptr;
        while (pos > 1)
        {
            ptr = temp;
            temp = temp->next;
            pos--;
        }
        n->next = ptr->next;
        ptr->next = n;
    }
}
//Driver Main Code
int main()
{
    node *head = NULL;
    int n;
    printf("Enter no. of elements in the list :\n");
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insert(head, val, i + 1);
    }
    printf("List generated is as follows :\n");
    print(head);
    int k;
    printf("Enter number of nodes to reverse up :\n");
    cin >> k;
    node *head2 = revKnode(head, k);
    printf("List generated is as follows :\n");
    print(head2);
    return 0;
}