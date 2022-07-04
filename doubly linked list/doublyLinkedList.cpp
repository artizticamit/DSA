#include<iostream>
#include<algorithm>
#include<string>
 
using namespace std;

struct node{
    int data;
    node * next, *prev;
};

void createList(struct node* head,struct node **rear, int n)
{
    if(head==NULL)
    {
        head = new node;
    }
    cout<<"Enter the head data:";
    cin>>head->data;
    head->prev= NULL;
    head->next = NULL;
    node * temp = head;


    while(--n)
    {
        node * newNode = new node;
        cout<<"Enter data: ";
        cin>>newNode->data;
        newNode->next = NULL;
        newNode->prev = temp;
        temp->next = newNode;
        temp  = newNode;
    }
    *rear = temp;
}

void printList(struct node * head)
{
    node * temp = head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void printReverse(struct node * tail)
{
    node * temp = tail;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;

}

node * insertAtBeginning(struct node * head, int val)
{
    node * newNode = new node;
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

int main()
{
    struct node * head = new node;
    struct node * rear;
    createList(head, &rear, 5);
    printList(head);
    head = insertAtBeginning(head, 0);
    printList(head);

    printReverse(rear);
    return 0;
}