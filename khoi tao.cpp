#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE;
struct list
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;
void KhoiTao(LIST &l)
{
    l.pHead=NULL;
    l.pTail=NULL;
}
void ThemVaoDau(LIST &l,NODE *p)
{
    if(l.pHead==NULL)
    {
        l.pHead=l.pTail=p;
    }
    else
    {
    p->pNext=l.pHead;
    l.pHead=p;
    }
}
void ThemVaoCuoi(LIST &l,NODE *p)
{
    if(l.pHead==NULL)
    {
        l.pHead=l.pTail=p;
    }
    else
    {
        l.pTail->pNext=p;
        l.pTail=p;
    }
    
}
NODE *KhoiTaoNODE(int x)
{
    NODE *p =new NODE; //cap phat bo nho
    if(p==NULL)
    {
        cout<<"\nKhong du bo nho de cap nhat !";
        return NULL;
    }
    p->data=x;
    p->pNext=NULL;
    return p;
}
void XuatDanhSach(LIST l)
{
    for(NODE *k=l.pHead;k!=NULL;k=k->pNext)
    {
        cout<<k->data<<"\t";
    }
}
int main()
{
    LIST l;
    KhoiTao(l);
    int n;
    cout<<"\nNhap so luong node can them :";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cout<<"\nNhap gia tri so nguyen :";
        cin>>x;
        NODE *p=KhoiTaoNODE(x);
        ThemVaoCuoi(l,p);
    }
    XuatDanhSach(l);
    system("pause");
    return 0;
}