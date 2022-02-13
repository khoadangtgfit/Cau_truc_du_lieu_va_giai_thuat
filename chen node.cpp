#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *pNext;
};
struct SingleList
{
    Node* pHead;
};
void Init(SingleList &list)
{
    list.pHead=NULL;
}
Node *CreateNode(int x)
{
    Node*p=new Node;
    if(p!=NULL)
    {
        return NULL;
    }
    else
    {
        p->data=x;
        p->pNext=NULL;
    }
    return NULL;
}
void InsertFirst(SingleList &list,int x)
{
    Node* p=CreateNode(x);
    if(list.pHead==NULL)
    {
        list.pHead=p;
    }
    else
    {
        p->pNext=list.pHead;
        list.pHead=p;
    }
}



