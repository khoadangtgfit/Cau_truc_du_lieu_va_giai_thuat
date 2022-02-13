#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *pNext;
};

struct STACK
{
    Node *pHead;
};
void Init(STACK &s)
{
    s.pHead=NULL;
}
bool IsEmpty(STACK s)
{
    if(s.pHead==NULL)
    {
        return true;
    }
    return false;
}
Node *CreateNode(int x)
{
    Node *p=new Node;
    if(p==NULL)
    {
        cout<<"Cap phat bo nho that bai!";
    }
    else
    {
        p->data=x;
        p->pNext=NULL;
    }
}
void Push(STACK &s,int d)
{
    Node *p=CreateNode(d);
    if(IsEmpty(s)==true)
    {
       s.pHead=p;
    }
    else
    {
        p->pNext=s.pHead;
        s.pHead=p;   
    }
}
void Pop(STACK &s)
{
    if(IsEmpty(s)==NULL)
}