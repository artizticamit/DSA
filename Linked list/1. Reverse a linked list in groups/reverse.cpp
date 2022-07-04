#include<bits/stdc++.h>
 
using namespace std;

struct Node{
    int data;
    struct Node *next;

    Node(int key)
    {
        data = key;
        next = NULL;
    }
};


Node * reverseK(Node *head, int k)
{
    Node *curr = head, *nxt = NULL, *prev = NULL;
    int count = 0;
    while(curr != NULL && count<k)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }

    if(nxt!=NULL)
    {
        Node *rest_head = reverseK(nxt, k);
        head->next = rest_head;
    }

    return prev;
}

void printList(Node * head)
{
    Node * curr = head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}
 
int main()
{
    Node * head = new Node(10);
    Node * h2 = new Node(20);
    head->next = h2;

    Node * h3 = new Node(30);
    h2->next = h3;

    Node * h4 = new Node(40);
    h3->next = h4;

    Node * h5 = new Node(50);
    h4->next = h5;

    printList(head);

    cout<<endl;
    head = reverseK(head, 3);

    printList(head);

    return 0;
}