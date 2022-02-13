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
void KhoiTaoDSLK(LIST &l)
{
    l.pHead=NULL;
    l.pTail=NULL;
}
NODE *KhoiTaoNODE(int x)
{
    NODE *p=new NODE;
    if(p==NULL)
    {
        cout<<"\nKhong du bo nho de cap phat !";
        return NULL;
    }
    p->data=x;
    p->pNext=NULL;
    return p;
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
void XuatDSLK(LIST l)
{
    for(NODE *k=l.pHead;k!=NULL;k->pNext)
    {
        cout<<k->data<<"\t";
    }
}
void Menu(LIST &l)
{
    int luachon;
    while(true)
    {
        system("cls");
        cout<<"\n\n\t\t=======MENU=======";
        cout<<"\n\t1.Them node vao danh sach";
        cout<<"\n\t2.Xuat danh sach lien ket don";
        cout<<"\n\t0.Thoat";
        cout<<"\n\n\t\t=======End======";
        cout<<"\nNhap lua chon";
        cin>>luachon;
        if(luachon<0||luachon>2)
        {
            cout<<"\nLua chon khong hop le!!!";
        }
        if(luachon==1)
        {
            int x;
            cout<<"\nNhap gia tri so nguyen :";
            cin>>x;
            NODE *p=KhoiTaoNODE(x);
            ThemVaoCuoi(l,p);
        }
        else if(luachon==2)
        {
            XuatDSLK(l);
        }
        else
        {
            break;
        }
    }
}
int main()
{
    LIST l;
    KhoiTaoDSLK(l);
    Menu(l);
    system("pause");
    return 0;
}
