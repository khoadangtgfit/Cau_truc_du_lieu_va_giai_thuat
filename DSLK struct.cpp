#include<iostream>
#include<string.h>
using namespace std;
struct SinhVien
{
    int ma;
    char ten[15];
};
struct Node
{
    SinhVien *data;
    Node *pNext;
};
struct SingleList
{
    Node *pHead;
};
void Initialize(SingleList *&list)
{
    list=new SingleList;
    list->pHead=NULL;
}
SinhVien *NhapSinhVien()
{
    SinhVien *sv=new SinhVien;
    cout<<"Ma:";
    cin>>sv->ma;
    cin.ignore();
    cout<<"Ten:";
    gets(sv->ten);
    return sv;
}
Node *CreateNode(SinhVien *sv)
{
    Node *pNode=new Node;
    if(pNode!=NULL)
    {
        pNode->data=sv;
        pNode->pNext=NULL;
    }
    else
    {
        cout<<"Cap phat bo nho that bai";
    }
    return pNode;
}
void Insertlast(SingleList *&list,SinhVien *sv)
{
    Node *pNode=CreateNode(sv);
    if(list->pHead==NULL)
    {
        list->pHead=pNode;
    }
    else
    {
        Node *pTmp=list->pHead;
        while (pTmp->pNext!=NULL)
        {
            pTmp=pTmp->pNext;
        }
        pTmp->pNext=pNode;
    }
}
void SortList(SingleList *&list)
{
    for(Node *pTmp=list->pHead;pTmp!=NULL;pTmp=pTmp->pNext)
    {
        for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext)
        {
            SinhVien *svTmp=pTmp->data;
            SinhVien *svTmp2=pTmp2->data;
            if(svTmp2->ma<svTmp->ma)
            {
            int ma=svTmp->ma;
            char ten[150];
            strcpy(ten,svTmp->ten);
            svTmp->ma=svTmp2->ma;
            strcpy(svTmp->ten,svTmp2->ten);
            svTmp2->ma=ma;
            strcpy(svTmp2->ten,ten);
            }
        }
    }
}
void PrintList(SingleList *list)
{
    Node *pTmp=list->pHead;
    if(pTmp==NULL)
    {
        cout<<"Danh sach rong!!!";
        return;
    }
    while (pTmp!=NULL)
    {
        SinhVien *sv=pTmp->data;
        cout<<sv->ma<<"\t"<<sv->ten<<"\n";
        pTmp=pTmp->pNext;
    }
}
int main()
{
    SingleList *list;
    Initialize(list);
    SinhVien *teo=NhapSinhVien();
    Insertlast(list,teo);
    SinhVien *ty=NhapSinhVien();
    Insertlast(list,ty);
    SinhVien *bin=NhapSinhVien();
    Insertlast(list,bin);
    PrintList(list);
    SortList(list);
    cout<<"Sau khi sort:"<<endl;
    PrintList(list);
}
