#include<iostream>
#include<stdlib.h>
// #include<conio.h>
#include <curses.h>
using namespace std;
struct Node
{
    int data;
    Node* pright;
    Node* pleft;
};
typedef struct Node NODE;
typedef NODE* TREE;
void Init(TREE &t)
{
    t=NULL;
}
void Isert(TREE &t,int d)
{
    if(t==NULL){
        Node *p=new Node;
        p->data=d;
        p->pleft=NULL;
        p->pright=NULL;
        t=p;
    }
    else{
    if(d<t->data)
        Isert(t->pleft,d);
    else if(d>t->data)
        Isert(t->pright,d);
    }
}
void TimPhanTuTheMang(TREE &q,TREE &p)
{
    if(q ->pright != NULL)
    {
        TimPhanTuTheMang(p, q ->pright);
    }
    else // Đã tìm ra phải nhất.
    {
        p ->data = q ->data;
        p = q;
        q = q ->pleft;
    }
}
void Xoa(TREE &t,int d)
{
    if(t==NULL)
        return;
    else{
        if(d>t->data)
            Xoa(t->pright,d);
        else if(d<t->data)
            Xoa(t->pleft,d);
        else{
            Node *X=t;
            if(t->pleft==NULL)
                t=t->pright;
            else if(t->pright==NULL)
                t=t->pleft;
            else
                TimPhanTuTheMang(X,t->pleft);
            delete X;
        }
    }
}
void NLR(TREE t)
{
    if(t!=NULL){
    cout<<"\t"<<t->data;
    NLR(t->pleft);
    NLR(t->pright);
}
}
void Menu()
{
    cout<<"============MENU============"<<endl;
    cout<<"1.Them node vao cay"<<endl;
    cout<<"2.Xoa node"<<endl;
    cout<<"3.Xuat cay"<<endl;
    cout<<"0.Thoat"<<endl;
    cout<<"============END============"<<endl;
}
int main()
{
    TREE t;
    Init(t);
    int chon;
    while(1)
    {
        system("cls");
        Menu();
        cout<<"Moi lua chon:";
        cin>>chon;
        switch(chon){
        case 1:
        {
            int d;
            cout<<"\nNhap gia tri muon them:";
            cin>>d;
            Isert(t,d);
            system("pause");
            break;
        }
        case 2:
        {
            int d;
            cout<<"\nNhap gia tri Node muon xoa:";
            cin>>d;
            Xoa(t,d);
            cout<<"\nCay sau khi xoa:"<<endl;
            NLR(t);
            system("pause");
            break;
        }
        case 3:
        {
            cout<<"\nXuat cac gia tri cua cay:"<<endl;
            NLR(t);
            system("pause");
                break;
        }
        case 0:
        {
            return 0;
        }
        default:
        {
            cout<<"\nNhap sai!"<<endl;
            system("pause");
        }
    }
    }
}