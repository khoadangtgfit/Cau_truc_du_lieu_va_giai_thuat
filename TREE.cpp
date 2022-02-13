#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *pRight;
    Node *pLeft;
};
typedef struct Node NODE;
typedef NODE* TREE;
void Init(TREE &t)
{
    t=NULL;
}
void ThemVaoCay(TREE &t,int x)
{
    NODE* p=new NODE;
    if(t==NULL)
    {
        p->data=x;
        p->pLeft=NULL;
        p->pRight=NULL;
        t=p;
    }
    else
    {
        if(t->data>x)
        {
            ThemVaoCay(t->pLeft,x);
        }
        else if(t->data<x)
        {
            ThemVaoCay(t->pRight,x);
        }
    }
}
void NLR(TREE t)
{
    NLR(t->pRight);
    cout<<"\t"<<t->data;
    NLR(t->pLeft);
}
int main()
{
    TREE t;
    int d;
    Init(t);
    ThemVaoCay(t,3);
    ThemVaoCay(t,2);
    ThemVaoCay(t,34);
    ThemVaoCay(t,35);
    ThemVaoCay(t,32);
    ThemVaoCay(t,1);
    ThemVaoCay(t,7);
    NLR(t);
}