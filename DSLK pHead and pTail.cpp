#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *pNext;
};
struct SingleList
{
    Node *pHead;
    Node *pTail;
};
void Intialize(SingleList *&list)
{
    list=new SingleList;
    list->pHead=NULL;
    list->pTail=NULL;
}
Node *CreateNode(int d)
{
    Node *pNode=new Node;
    if(pNode==NULL)
    {
        cout<<"Cap phat bo nho that bai!!!";
    }
    else
    {
        pNode->data=d;
        pNode->pNext=NULL;
    }
    return pNode;
}
void InsertFirst(SingleList *&list,int d)
{
    Node *pNode=CreateNode(d);
    if(list->pHead==NULL)
    {
        list->pHead=list->pTail=pNode;
    }
    else
    {
        pNode->pNext=list->pHead;
        list->pHead=pNode;
    }
}
void InsertLast(SingleList *&list,int d)
{
    Node *pNode=CreateNode(d);
    if(list->pHead==NULL)
    {
        list->pHead=list->pTail=pNode;
    }
    else
    {
        list->pTail->pNext=pNode;
        list->pTail=pNode;
    }   
}
int SizeOfList(SingleList *list)
{
    int index=0;
    Node *pTmp=list->pHead;
    while(pTmp!=NULL)
    {
        index++;
        pTmp=pTmp->pNext;
    }
    return index;
}
void InsertMid(SingleList *&list,int pos,int d)
{
    if(pos<0||pos>=SizeOfList(list))
    {
        cout<<"Vi tri khong hop le!!!";
    }
    else
    {
        if(pos==0)
        {
            InsertFirst(list,d);
        }
        else if(pos==SizeOfList(list))
        {
            InsertLast(list,d);
        }
        else
        {
            Node *pNode=CreateNode(d);
            Node *pTmp=list->pHead;
            Node *pPre=NULL;
            int d=0;
            while(pTmp!=NULL)
            {
                if(d==pos)
                {
                    break;
                }
                pPre=pTmp;
                pTmp=pTmp->pNext;
                d++;
            }
            pPre->pNext=pNode;
            pNode->pNext=pTmp;
        }
    }
}
void RemoveNode(SingleList *&list,int d)
{
    Node *pDel=list->pHead;
    if(pDel==NULL){
        cout<<"The list is empty!";
    }
    else
    {
        Node *pPre=NULL;
        while(pDel!=NULL)
        {
            if(pDel->data==d)
                break;
            pPre=pDel;
            pDel=pDel->pNext;
        }
        if(pDel!=NULL)
        {
            if(pDel==list->pHead)
            {
                list->pHead=list->pHead->pNext;
                pDel->pNext=NULL;
                delete pDel;
                pDel=NULL;
            }
            else if(pDel->pNext==NULL)
            {
                list->pTail=pPre;
                pPre->pNext=NULL;
                delete pDel;
                pDel=NULL;
            }
            else
            {
                pPre->pNext=pDel->pNext;
                pDel->pNext=NULL;
                delete pDel;
                pDel=NULL;
            }
        }
    }
}
void PrintList(SingleList *list)
{
    Node *pTmp=list->pHead;
    if(pTmp==NULL)
    {
        cout<<"Danh sach rong";
    }
    while (pTmp!=NULL)
    {
        cout<<pTmp->data<<"\t";
        pTmp=pTmp->pNext;
    }
}
void Chia(SingleList *&list1,SingleList *&list2)
{   
   SingleList *list3;
   SingleList *list4;
   for()
}
int main()
{
    SingleList *list1;
    Intialize(list1);
    InsertLast(list1,1);
    InsertLast(list1,2);
    InsertLast(list1,3);
    InsertLast(list1,4);
    InsertLast(list1,5);
    InsertLast(list1,6);
    SingleList *list2;
    Intialize(list2);
    InsertLast(list2,11);
    InsertLast(list2,10);
    InsertLast(list2,9);
    InsertLast(list2,8);
    InsertLast(list2,2);
    Chia(list1,list2);
    PrintList(list1);
    cout<<endl;
    PrintList(list2);
    // RemoveNode(list1,1);
    // cout<<"pHead="<<list1->pHead->data;

}
