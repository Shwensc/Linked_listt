//Stack using linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct Node *next; //self referential pointer
    int data;
}Node;

typedef struct Stack{
    Node *tos; //pointer of type node to point to start of Stack(Linked list)
}StackLL;

void push(StackLL *s,int element)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=element;
    if(s->tos==NULL)
    {
        s->tos=p; //tos will get p address
        p->next=NULL; //since single node, next part of p is null
        return;
    }
    p->next=s->tos; //next part of p now has tos ka address eg: (p=200)tos=100,p(data)=10,p(next) ==(p=200) tos=100,p(data)=10,p(next)=100;
    s->tos=p; //tos now has p ka adress(p=200) tos=200(point at p) p(data)=10,p(next)=100

}

void display(StackLL s)
{
    Node *q=(Node*)malloc(sizeof(Node));
    q=s.tos; //coz we need to traverse starting from queue ,but cant use tos as we'll lose track of it hence we use q
    while(q!=NULL) //Very important concept coz q->next will not print last node
    {
        printf("%d\n",q->data);
        q=q->next;
    }
}
void pop(StackLL *s)
{
    if(s->tos == NULL)
    {
        printf("Stack underflow");
        return;
    }

    int element = s->tos->data; // Get the data from the top node
    Node *temp = s->tos; /*By using the temp variable, you ensure that the top node's data is safely retrieved, the s->tos pointer is correctly updated, 
    and the memory of the popped node is freed without losing any references to it.*/
    s->tos = s->tos->next; // Move the top pointer to the next node
    free(temp); // Free the memory of the popped node

    printf("Popped element = %d\n", element);
}


/*void pop(StackLL *s)
{
    if(s->tos==NULL)
    {
        printf("Stack underflow");
        return;
    }
    int element;
    Node *q=(Node*)malloc(sizeof(Node));
    q=s->tos; //q gets memeory adress of tos to traverse
    element=q->data; //element to be popped, as tos element is to be popped
    printf("Popped element=%d",element); //print element otherwise printing q->data will give adress value
    s->tos=q->next;//decrement tos after assigning value;
    free(q); //free the previous tos node
    
}*/

int main()
{
    StackLL s1;
    s1.tos=NULL;
    push(&s1,10);
    push(&s1,20);
    push(&s1,30);
    push(&s1,40);
    display(s1);
    pop(&s1);
    display(s1);


    return 0;
} 