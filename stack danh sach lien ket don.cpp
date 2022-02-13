#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *pNext;
};
typedef struct Node* STACK;
bool IsEmpty(STACK s)
{
    if(s=NULL)
        return true;
    return false;
}
Node *CreateNode(int x)
{
    Node *p=new Node;
    if(p==NULL)
    {
        return NULL;
    }
    else
    {
        p->data=x;
        p->pNext=NULL;
    }
    return p;
}
void Push(STACK &s,int x)
{
    Node *p=CreateNode(x);
    if(IsEmpty(s)==true)
    {
        s=p;
    }
    else
    {
        p->pNext=s;
        s=p;
    }
}
int Pop(STACK &s)
{
    if(IsEmpty(s)==true)
    {
       cout<<"Rong"<<endl;
    }
    else
    {
        int d=s->data;
        Node *X=s;
        s=s->pNext;
        delete(X);
        return d;
    }
}
void ChuyenCoSo(STACK &s,int d,int t)
{
    while (d!=0)
    {
        int x=d%t;
        Push(s,x);
        d/=t;
    }
}
int main()
{
    STACK s;
    // Push(s,1);
    // Push(s,2);
    // Push(s,3);
    // Push(s,4);
    // Push(s,5);
    ChuyenCoSo(s,100,2);
    while (IsEmpty(s)!=true)
    {
        int data=Pop(s);
        cout<<"\t"<<data;
    }
}