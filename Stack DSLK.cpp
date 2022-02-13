#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* pNext;
};
typedef struct Node *Stack;
int isEmpty(Stack s)
{
    return (s==NULL);
}
Node*CreateNode(int d)
{
    Node *p=new Node();
    if(p==NULL)
        return NULL;
    else
    {
        p->data=d;
        p->pNext=NULL;
    }
    return p;
}
void push(Stack &s,int d)
{
    Node*k=CreateNode(d);
    if(isEmpty(s))
    {
        s=k;
    }
    k->pNext=s;
    s=k;
}
int pop(Stack &s)
{
    if(!isEmpty(s))
    {
        int d=s->data;
        Node*x=s;
        s=s->pNext;
        delete(x);
        return d;
    }
    else
    {
        cout<<"empty";
    }
}
int main()
{
    Stack s;
    push(s,1);
    push(s,2);
    push(s,3);
    while (!isEmpty(s))
    {
        int data=pop(s);
        cout<<"\t"<<data;
    }
    
}