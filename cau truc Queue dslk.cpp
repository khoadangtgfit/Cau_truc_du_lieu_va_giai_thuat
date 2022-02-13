#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct Node
{
    int data;
    Node *pNext;
};
typedef struct Node NODE;
struct queue
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct queue QUEUE;
void KhoiTaoQueue(QUEUE &q)
{
    q.pHead=NULL;
    q.pTail=NULL;
}
NODE *KhoiTaoNode(int x)
{
    NODE *p=new NODE();
    if(p==NULL)
    {
        cout<<"\nKhong du bo de cap phat!!!";
        return NULL;
    }
    p->data=x;
    p->pNext=NULL;
    return p;
}
bool IsEmpty(QUEUE q)
{
    if(q.pHead==NULL)
    {
        return true;
    }
    return false;
}
bool Push(QUEUE &q,Node *p)
{
    if(p==NULL)
    {
        return false;
    }
    if(IsEmpty(q)==true)
    {
        q.pHead=q.pTail=p;
    }
    else
    {
        q.pTail->pNext=p;
        q.pTail=p;
    }
    return true;
}
void Pop(QUEUE &q,int &x)
{
    if(IsEmpty(q)==true)
    {
        cout<<"Khong co phan tu!";
    }
    else
    {
        NODE* p=q.pHead;
        x=p->data;
        q.pHead=q.pHead->pNext;
        delete p;
    }
}
void Top(QUEUE &q,int &x)
{
    if(IsEmpty(q)==true)
    {
        cout<<"Danh sach rong";
    }
    else
    {
        x=q.pHead->data;
    }
}
void XuatQueue(QUEUE q)
{
    while(IsEmpty(q)==false)
    {
        int x;
        Pop(q,x);
        cout<<x<<"\t";
    }
}
int main()
{
    QUEUE q;
    KhoiTaoQueue(q);
    int luachon;
    do
    {
    	system("cls");
        cout<<"\n=============Menu============="<<endl;
        cout<<"1.Them phan tu vao queue -Push"<<endl;
        cout<<"2.Xuat danh sach ra man hinh -Pop"<<endl;
        cout<<"3.Xem thong tin phan tu dau queue -Top"<<endl;
        cout<<"0.Ket thuc"<<endl;
        cout<<"=============End============="<<endl;
        cout<<"\nNhap lua chon:";
        cin>>luachon;
        switch (luachon)
        {
        case 1:{
            int x;
            cout<<"\nNhap phan tu can them:";
            cin>>x;
            Node *p=KhoiTaoNode(x);
            Push(q,p);
            break;
        }
        case 2:
        { 
        XuatQueue(q); break;
        }
        case 3: {int x;
                Top(q,x);
                cout<<"\nPhan tu dau queue la:"<<x;
                break;}
        default:
            break;
        }
        getch();
        }while(luachon!=0);
}
