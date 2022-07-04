#include<iostream>
#include<algorithm>
#include<string>
 
using namespace std;
struct node{
    int data;
    node * next;
};
void creatList(struct node * head, int n)
{
    cout<<"enter first data:";
    cin>>head->data;
    node * temp = head;
    while(n--)
    {
        node * newNode = new node;
        cout<<"enter data:";
        cin>>newNode->data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }
    temp->next = head;
}


void printList(struct node * head)
{
    node * temp = head;

    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp!=head);
}

node* insertAtBeginning(struct node * head, int val)
{
    node * newNode = new node;
    newNode->data = val;
    newNode->next = head->next;
    head->next = newNode;
    int temp = newNode->data;
    newNode->data = head->data;
    head->data = temp;
    return head;
}
 
int main()
{
    struct node * head = new node;
    creatList(head, 5);
    head = insertAtBeginning(head, 0);
    printList(head);
    return 0;
}