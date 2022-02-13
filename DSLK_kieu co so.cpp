#include<iostream>
using namespace std;
struct Node
{
    float data;
    Node *pNext;
};
struct SingleList
{
   Node *pHead;
};
void Initialize(SingleList *&list)
{
    list->pHead=NULL;
}
Node *CreateNode(float d)
{
    Node *pNode=new Node;
    if(pNode!=NULL)
    {
        pNode->data=d;
        pNode->pNext=NULL;
    }
    else
    {
        cout<<"Cap phat bo nho that bai!!";
    }
    return pNode;
}
void PrintList(SingleList *list)
{
    Node *pTmp=list->pHead;
    if(pTmp=NULL)
    {
        cout<<"Danh sach rong";
        return;
    }
    while(pTmp!=NULL)
    {
        cout<<pTmp->data<<"\t";
        pTmp=pTmp->pNext;
    }
}
int SizeOfList(SingleList *list)
{
    Node *khoa=list->pHead;
    int index=0;
    while(khoa!=NULL)
    {
        index++;
        khoa=khoa->pNext;
    }
    return index;
}
void InsertFirst(SingleList *&list,float d)
{
    Node *pNode=CreateNode(d);
    if(list->pHead=NULL)
    {
        list->pHead=pNode;
    }
    else
    {
        pNode->pNext=list->pHead;
        list->pHead=list->pHead->pNext;
    }
}