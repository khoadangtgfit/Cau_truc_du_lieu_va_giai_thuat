#include<iostream>
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
void insertFirst(Singlelist &list ,int d)
{
    Node *pNode=createNODE(d);
    if(list.pHead==NULL)
    {
        list.pHead=pNode;
    }
    else
    {
        pNode->pNext=list.pHead;
        list.pHead=pNode;
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
int SizeOfList(Singlelist list)
{
    int index=0;
    for(Node *k=list.pHead;k!=NULL;k=k->pNext)
    {
        index++;
    }
    return index;
}
void InSertMid(Singlelist list ,int pos,int d)
{
    if(pos<0||pos>=SizeOfList(list))
    {
        cout<<"Vi tri can chem khong hop le!!!";
    }
    if(pos==0)
        insertFirst(list,d);
    else if(pos==SizeOfList(list))
    {
        InsertLast(list,d);
    }
    else
    {
        Node *pNode=createNODE(d);
        Node *pIns=list.pHead;
        Node *pPre=NULL;
        int i=0;
        while(pIns!=NULL)
        {
            if(i==pos)
                break;
            pPre=pIns;
            pIns=pIns->pNext;
            i++;
        }
        pPre->pNext=pNode;
        pNode->pNext=pIns;
    }
    
}
void XoaNode(Singlelist &list)
{
    Node *i=new Node;
    Node *j=new Node;
    Node *Pre=new Node;
    for(i=list.pHead;i!=NULL;i=i->pNext)
    {
        for(j=i->pNext;j!=NULL;j=j->pNext)
        {
            if(j->data=i->data)
            {
               break;
            }
            Pre=j;
        }
        Pre->pNext=j->pNext;
        delete(j);
    }
}
void RemoveNode(Singlelist list,int d)
{
    Node *pPdel=list.pHead;
    if(pPdel==NULL)
    {
        cout<<"The list is empty,can't delete!!!";
    }
    else
    {
        Node *pPre=NULL;
        while(pPdel!=NULL)
        {
            if(pPdel->data==d)
                break;
            pPre=pPdel;
            pPdel=pPdel->pNext;
        }
        if(pPdel==NULL)
        {
            cout<<" Could not found number!";
        }
        else
        {
            if(pPdel==list.pHead)
            {
                list.pHead=list.pHead->pNext;
                pPdel->pNext=NULL;
                delete pPdel;
                pPdel=NULL;
            }
            else
            {
                pPre->pNext=pPdel->pNext;
                pPdel->pNext=NULL;
                delete pPdel;
                pPdel=NULL;
            }
            
        }
        
    }
    
}
int main()
{
    Singlelist list;
    Initialize(list);
    InsertLast(list,4);
    InsertLast(list,4);
    InsertLast(list,4);
    InsertLast(list,6);
    InSertMid(list,2,108);
    XoaNode(list);
    printList(list);
    return 0;
}