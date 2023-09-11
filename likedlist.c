#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;
// linked list creation
typedef struct
{
    Node *start;
} LL;
// insertion at end
void appendNode(LL *l, int ele)
{
    Node *p;                          // creation of pointer p of type Node
    p = (Node *)malloc(sizeof(Node)); // memory allocation for p
    p->data = ele;
    p->next = NULL;
    // if there are no nodes in the linked list
    if (l->start == NULL)
    {
        // the start pointer will have the address pointed by p
        l->start = p;
    }
    // to append at the end of linked list
    else
    {
        Node *q = l->start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
}
// add a node in the beginning
// addBegin method
void addBegin(LL *l, int ele)
{
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->data = ele;
    // the next part of p will now store the address stored in start
    p->next = l->start;
    // address of p passing to start
    l->start = p;
}
// adding after nth node
// addMid method
void addMid(LL *l, int n, int ele)
{
    // new block of nodes p and q
    // pointer p will have the element we want to store
    Node *p, *q;
    p = (Node *)malloc(sizeof(Node));
    p->data = ele;
    p->next = NULL;
    // pointer q will have the address that is pointed by start
    q = l->start;
    // the node will be the nth node
    for (int i = 1; i < n; i++)
    {
        q = q->next;
    }
    // next node in linked list will have its address stored into new node
    p->next = q->next;
    // address of new node into the previous node
    q->next = p;
}
// countnodes method
int countNodes(LL l)
{
    Node *q;
    int count = 0;
    q = l.start;
    // while a node exists
    while (q != NULL)
    {
        count++;     // increment count after each node
        q = q->next; // increment each node
    }
    return count;
}
// deletion of node
void deleteNode(LL *l, int ele)
{
    Node *q, *prev;
    q = l->start;
    while (q != NULL)
    {
        // if the data part of q node is equal to element passed
        if (q->data == ele)
        {
            break; // breaks while loop
        }
        prev = q;    // store q into prev pointer
        q = q->next; // increments q
    }
    // after the while loop ends and no data is found which matches the passed element
    if (q == NULL)
    {
        printf("No node with %d exists in the linked list\n", ele);
    }
    else
    { // if the data is in the first node
        if (prev == NULL)
        {
            l->start = q->next;
        }
        // if data is somewhere in between
        else
        {

                prev->next = q->next;
        }
        // freeing the node which has the required data part
        free(q);
    }
}
// concatenate two linked lists
void concat(LL *l1, LL l2)
{
    Node *q;
    if (l2.start == NULL) // l2 has no nodes
        return;
    if (l1->start == NULL) // l1 is empty and l2 is Not Empty
    {
        l1->start = l2.start;
    }
    else
    {
        q = l1->start; // locate last node of LL 1
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = l2.start; // link last node of l1 with first node of l2
    }
}
// reversing a linked list
void reverse(LL *l)
{
    Node *q, *r, *p;
    p = NULL;     // previous node
    q = l->start; // current node
    while (q != NULL)
    {
        r = q->next; // next node into r pointer
        q->next = p; // current node points to previous node
        p = q;       // current node becomes previous node
        q = r;       // next node becomes current node
    }
    l->start = p; // end of the previous ll becomes start of this ll
}
// display method
void display(LL l)
{
    Node *q;
    q = l.start;
    printf("Elements are:\n");
    while (q != NULL) // while node exists
    {
        printf("%d\n", q->data);
        q = q->next; 
 }
}
// main method
int main()
{
    LL l1, l2, l3;
    l1.start = l2.start=l3.start=NULL;
    int option, ele;
    // menu driven code
    do
    {
printf("1.Insert at beginning 2.Insert at end 3.Display 4.Delete Data 5.Count Nodes\nB.For linked list 2-6.Concat 2LL \nC.For linked list 3-7.Reverse 8.Exit\n");
scanf("%d",&option);
switch(option)
{
        case 1:
            printf("Enter the element:\n");
            scanf("%d", &ele);
            addBegin(&l1, ele);
            break;
        case 2:
            printf("Enter the element:\n");
            scanf("%d", &ele);
            appendNode(&l1, ele);
            break;
        case 3:
            display(l1);
            break;
        case 4:
            printf("Enter the data to be deleted:\n");
            scanf("%d", &ele);
            deleteNode(&l1, ele);
            break;
        case 5:
            printf("The total nodes in the linked list are :%d\n", countNodes(l1));
            break;
        case 6:
            appendNode(&l2, 60);
            appendNode(&l2, 50);
            addBegin(&l2, 40);
            concat(&l1, l2);
            printf("The concatenated linked list is :\n");
            display(l1);
            break;
        case 7:
            appendNode(&l3, 80);
            appendNode(&l3, 90);
            addBegin(&l3, 100);
            reverse(&l3);
            display(l3);
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Enter valid option\n");
}
    }while (1); // infinite loop
    return 0;
}
