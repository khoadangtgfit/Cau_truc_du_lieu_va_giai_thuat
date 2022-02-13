#include<iostream>
using namespace std;
struct PhanSo
{
    float tu;
    float mau;
};
struct Node
{
    PhanSo data;
    Node *pNext;
};
struct SingleList
{
    Node *pHead;
    Node *pTail;
};
void Init(SingleList *&list)
{
    list->pHead=NULL;
    list->pTail=NULL;
}
void NhapPS(PhanSo &ps)
{
    cout<<"Nhap tu so:";
    cin>>ps.tu;
    cout<<"\nNhap mau so:";
    cin>>ps.mau;
}
Node *CreateNode(PhanSo ps)
{
    Node *p=new Node;
    if(p!=NULL)
    {
        p->data=ps;
        p->pNext=NULL;
    }
    return p;
}
void InsertLast(SingleList *&list,PhanSo ps)
{
    NhapPS(ps);
    Node *p=CreateNode(ps);
    if(list->pHead==NULL)
    {
        list->pTail=list->pHead=p;
    }
    else
    {
        list->pTail->pNext=p;
        list->pTail=p;
    }
}
Node* TimMax(SingleList *list)
{
    Node *Max=list->pHead;
    if(list->pHead==NULL)
        return NULL;
    else
    {
        for(Node *p=list->pHead;p!=NULL;p=p->pNext)
        {
            if((p->data.tu)/(p->data.mau)>(Max->data.tu/Max->data.mau))
                    Max=p;
        }
    }
    return Max;
}
PhanSo RutGon(PhanSo &ps)
{
    int a=ps.tu;
    int b=ps.mau;
    while (a!=b)
    {
        if(a>b)
            a-=b;
        else
        {
            b-=a;
        }
    }
    ps.tu/=a;
    ps.mau/=a;
    return ps;
}
void XuatPS(Node *p)
{
    cout<<p->data.tu<<"/"<<p->data.mau;
}
int main()
{
    SingleList *list;
    PhanSo ps;
    Init(list);
    cout<<"dsaa"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        NhapPS(ps);
        InsertLast(list,ps);
    }
    Node *p=TimMax(list);
    RutGon(p->data);
    XuatPS(p);
    
}