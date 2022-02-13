#include<iostream>
#include<conio.h>
using namespace std;
struct Node
{
    int data;
    Node *pNext;
};
struct Singlelist
{
    Node *pHead;
};
void Initialize(Singlelist &list)
{
    list.pHead=NULL;
}
Node *createNODE(int d)
{
    Node *pNode = new Node;
    if(pNode!=NULL)
    {
        pNode->data=d;
        pNode->pNext=NULL;
    }
    else
    {
        cout<<"\nCap Phat bo nho that bai!!!";
    }
    return pNode;
    
}
void printList(Singlelist list)
{
    Node *pTmp=list.pHead;
    if(pTmp==NULL)
    {
        cout<<"\nDanh sach rong!";
        return;
    }
    while(pTmp!=NULL)
    {
        cout<<pTmp->data<<"\t";
        pTmp=pTmp->pNext;
    }
}
void InsertLast(Singlelist &list,int c)
{
    Node *pNode=createNODE(c);
    if(list.pHead==NULL)
    {
        list.pHead=pNode;
    }
    else
    {
        Node *khoa=list.pHead;
        while(khoa->pNext!=NULL)
        {
            khoa=khoa->pNext;
        }
       khoa->pNext=pNode;
    }   
}
Node *TimNode(Singlelist list,int k)
{
    Node *p=list.pHead;
    int d=0;
    if(k==1)
        return p;
    do
    {
        p=p->pNext;
        d++;
    } while (d<k&&p!=list.pHead);
    return p;
}
void XoaViTri(Singlelist &list,int k)
{
    Node *p=list.pHead;
    Node *Q=TimNode(list,k);
    if(Q==list.pHead)
    {
        list.pHead=list.pHead->pNext;
        delete(Q);
    }
    else
    {
        Node *R=list.pHead;
        while (R->pNext!=Q)
        {
            R=R->pNext;
        }
        R->pNext=Q->pNext;
        delete(Q);
    }
    
}
int SizeOfList(Singlelist list)
{
    int index=0;
    Node *pTmp=list.pHead;
    while(pTmp!=NULL)
    {
        index++;
        pTmp=pTmp->pNext;
    }
    return index;
}
void XoaTrung(Singlelist &list)
{
    for(int i=0;i<SizeOfList(list)-1;i++)
    {
        for(int j=i+1;j<SizeOfList(list);j++)
        {
            if(TimNode(list,i)->data==TimNode(list,j)->data)
            {
                XoaViTri(list,j);
                i--;
            }
        }
    }
}
void Menu()
{
    cout<<"\n=============MENU============="<<endl;
    cout<<"1.Them Node vao cuoi danh sach"<<endl;
    cout<<"2.Xuat Danh sach lien ket"<<endl;
    cout<<"3.Xoa cac phan tu trung nhau chi giu lai mot phan tu"<<endl;
}
int main()
{
    Singlelist list;
    Initialize(list);
    int chon;
    do
    {
        system("cls");
        Menu();
        cout<<"Moi ban chon:";
        cin>>chon;
        switch (chon)
        {
        case 1:
            int x;
            cout<<"Nhap gia tri muon them:";
            cin>>x;
            InsertLast(list,x); 
            break;
        case 2: printList(list); 
                break;
        case 3: XoaTrung(list); cout<<"Danh sach sau khi xoa cac phan tu trung:"<<endl; printList(list);  break;
        default:
            cout<<"\nChon Sai!"<<endl;
        }
        cout<<"\nDe chon tiep lua chon moi ban nhan phim bat ki!";
        getch();
    } while (chon!=0);
    return 0;
}