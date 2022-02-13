#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
using namespace std;
struct BenhNhan
{
    int STT;
    int Tuoi;
    char hoten[30];
};
struct Node
{
    BenhNhan data;
    Node *pNext;
};
typedef struct Node NODE;
struct queue
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct queue QUEUE;
void Nhap(BenhNhan &bn,int &n)
{
    fflush(stdin);
    cout<<"\nNhap ho ten:";
    gets(bn.hoten);
    cout<<"\nNhap tuoi:";
    cin>>bn.Tuoi;
    bn.STT=++n;
}
void Xuat(BenhNhan bn)
{
    cout<<bn.STT<<"\t"<<bn.hoten<<"\t"<<bn.Tuoi<<endl;
}
void KhoiTaoQueue(QUEUE &q)
{
    q.pHead=NULL;
    q.pTail=NULL;
}
NODE *KhoiTaoNode(BenhNhan x)
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
void Pop(QUEUE &q,BenhNhan &x,int &d)
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
    d++;
}
void XuatQueue(QUEUE q)
{
    int n;
    while(IsEmpty(q)==false)
    {
        BenhNhan x;
        Pop(q,x,n);
    }
}
int main()
{
    QUEUE q;
    int n,d=0;
    KhoiTaoQueue(q);
    int luachon;
    do
    {
    	system("cls");
        cout<<"\n=============Menu============="<<endl;
        cout<<"1.Them benh nhan vao queue -Push"<<endl;
        cout<<"2.Xuat thong tin benh nhan tiep theo se kham -Pop"<<endl;
        cout<<"3.So luong nguoi da kham"<<endl;
        cout<<"4.So luong benh nhan chua kham"<<endl;
        cout<<"5.Xuat danh sach benh nhan con trong hang doi cho kham"<<endl;
        cout<<"0.Ket thuc"<<endl;
        cout<<"=============End============="<<endl;
        cout<<"\nNhap lua chon:";
        cin>>luachon;
        switch (luachon)
        {
        case 1:{
            BenhNhan x;
            cout<<"\nNhap thong tin benh nhan can them vao -Queue:";
            Nhap(x,n);
            Node *p=KhoiTaoNode(x);
            Push(q,p);
            break;
        }
        case 2:
        {   
            cout<<"Benh nhan tiep theo"<<endl;
            cout<<"STT\tTen\tTuoi"<<endl;
            BenhNhan x;
            Pop(q,x,d);
            Xuat(x);
            break;
        }
        case 3: {
            cout<<"So luong benh nhan da kham:"<<d; break;
        }
        case 4:{
            cout<<"So luong benh nhan chua kham:"<<n-d; break;
        }
        case 5:
        {
            cout<<"STT\tTen\tTuoi"<<endl;
            XuatQueue(q);
        }
        default:
            break;
        }
        getch();
        }while(luachon!=0);
}
